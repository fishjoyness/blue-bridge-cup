#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

// a[]: 原数组
// t[]: 线段树数组，t[p] 存储节点 p 代表的区间和
// lz[]: 懒惰标记数组，lz[p] 表示节点 p 对应的区间需要加上的值（还没传给儿子）
ll a[N], t[N * 4], lz[N * 4];
int n;

// 建树函数：build(当前节点p, 区间左边界l, 区间右边界r)
void build(int p, int l, int r)
{
    if (l == r)
    {
        // 如果是叶子节点，直接存原数组的值
        t[p] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    // 递归建立左儿子和右儿子
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    
    // 回溯：当前区间的和 = 左儿子之和 + 右儿子之和
    t[p] = t[p << 1] + t[p << 1 | 1];
}

// 下传懒惰标记函数
// 当我们需要访问子节点（修改或查询）时，如果当前节点有标记，必须把标记传给儿子
void pushdown(int p, int l, int r)
{
    // 如果没有标记，直接返回
    if (lz[p] == 0) return;

    int mid = (l + r) >> 1;
    ll val = lz[p]; // 取出当前节点的标记值

    // 更新左儿子：区间和加上 (左区间长度 * val)
    t[p << 1] += val * (mid - l + 1);
    lz[p << 1] += val; // 打上标记

    // 更新右儿子：区间和加上 (右区间长度 * val)
    t[p << 1 | 1] += val * (r - mid);
    lz[p << 1 | 1] += val; // 打上标记

    // 清除当前节点的标记（标记已经传给儿子了）
    lz[p] = 0;
}

// 区间修改函数：update(当前节点p, 当前区间[l,r], 目标区间[L,R], 增量x)
void update(int p, int l, int r, int L, int R, ll x)
{
    // 情况1：当前区间完全被目标区间包含
    // 直接更新当前节点的和，并打上懒惰标记，不再往下递归
    if (L <= l && r <= R)
    {
        t[p] += x * (r - l + 1);
        lz[p] += x;
        return;
    }

    // 情况2：没有完全覆盖，需要往下走
    // 在访问儿子之前，必须先下传当前的懒惰标记
    pushdown(p, l, r);

    int mid = (l + r) >> 1;
    
    // 如果目标区间和左儿子有交集，递归左儿子
    if (L <= mid) update(p << 1, l, mid, L, R, x);
    // 如果目标区间和右儿子有交集，递归右儿子
    if (R > mid)  update(p << 1 | 1, mid + 1, r, L, R, x);

    // 回溯：儿子更新完了，更新当前节点
    t[p] = t[p << 1] + t[p << 1 | 1];
}

// 区间查询函数：query(当前节点p, 当前区间[l,r], 目标区间[L,R])
ll query(int p, int l, int r, int L, int R)
{
    // 情况1：当前区间完全被目标区间包含
    // 直接返回当前节点的和
    if (L <= l && r <= R)
    {
        return t[p];
    }

    // 情况2：没有完全覆盖
    // 在访问儿子之前，必须先下传当前的懒惰标记
    pushdown(p, l, r);

    int mid = (l + r) >> 1;
    ll res = 0;

    // 如果目标区间和左儿子有交集，查询左儿子并累加
    if (L <= mid) res += query(p << 1, l, mid, L, R);
    // 如果目标区间和右儿子有交集，查询右儿子并累加
    if (R > mid)  res += query(p << 1 | 1, mid + 1, r, L, R);

    return res;
}

int main()
{
    // 优化输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // 建立线段树，根节点是 1，区间范围是 [1, n]
    build(1, 1, n);

    while (q--)
    {
        int op;
        cin >> op;
        
        if (op == 1)
        {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            // 区间修改
            update(1, 1, n, l, r, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            // 区间查询
            cout << query(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}

