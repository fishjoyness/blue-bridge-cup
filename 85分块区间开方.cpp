#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

// a[]: 原数组
// sum[]: 块的和
// tag[blo]: 记录块 blo 进行了多少次整体开方（用于剪枝）
// bel[], L[], R[]: 分块常规数组
// sz: 块的大小
ll a[N], sum[N];
int tag[N], bel[N], L[N], R[N];
int n, m, sz;

// 暴力修改函数：对 [l, r] 范围内的每一个数开方
// 必须手动更新 a[i] 和该元素所属块的 sum
void modify(int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        int b = bel[i];
        sum[b] -= a[i];       // 先把原来的值减去
        a[i] = sqrt(a[i]);    // 开方
        sum[b] += a[i];       // 加上新的值
    }
}

// 区间开方操作
void Sqrt(int l, int r)
{
    if (bel[l] == bel[r])
    {
        // 如果在一个块里，直接暴力
        modify(l, r);
        return;
    }

    // 第一部分：左边零散部分
    modify(l, R[bel[l]]);

    // 第二部分：中间的整块
    for (int blo = bel[l] + 1; blo < bel[r]; ++blo)
    {
        // 剪枝：如果一个块已经开方过很多次了（比如 >= 7次），
        // 说明里面的数早就是 1 了，不需要再算了，直接跳过。
        if (tag[blo] >= 7) continue; 
        
        tag[blo]++;          // 记录开方次数
        modify(L[blo], R[blo]); // 暴力重构这个块
    }

    // 第三部分：右边零散部分
    modify(L[bel[r]], r);
}

// 区间求和操作
ll query(int l, int r)
{
    ll res = 0;
    
    if (bel[l] == bel[r])
    {
        // 如果在一个块里，直接循环加
        for (int i = l; i <= r; ++i)
            res += a[i];
        return res;
    }

    // 第一部分：左边零散部分
    for (int i = l; i <= R[bel[l]]; ++i)
        res += a[i];

    // 第二部分：中间的整块
    // 直接用预处理好的 sum[] 数组，O(1) 查询
    for (int blo = bel[l] + 1; blo < bel[r]; ++blo)
        res += sum[blo];

    // 第三部分：右边零散部分
    for (int i = L[bel[r]]; i <= r; ++i)
        res += a[i];

    return res;
}

int main()
{
    // 优化输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // 1. 建立分块结构
    sz = sqrt(n);
    int tot = n / sz;
    if (n % sz) tot++;

    for (int i = 1; i <= tot; ++i)
    {
        L[i] = (i - 1) * sz + 1;
        R[i] = i * sz;
    }
    R[tot] = n; // 修正最后一块的边界

    for (int i = 1; i <= n; ++i)
    {
        bel[i] = (i - 1) / sz + 1;
        sum[bel[i]] += a[i];
    }

    // 2. 处理操作
    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1)
        {
            // 开方操作
            Sqrt(l, r);
        }
        else
        {
            // 求和操作
            cout << query(l, r) << '\n';
        }
    }

    return 0;
}

