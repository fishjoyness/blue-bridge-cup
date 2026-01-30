#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int n, q;
int sz; // 块大小
int a[N];           // 原数组
int add[N];         // 懒惰标记：第 i 个块整体加了多少
int bel[N];         // bel[i]：第 i 个元素属于哪个块
int L[N], R[N];     // 第 i 个块的左右边界
vector<int> v[N];   // v[i]：第 i 个块的排序数组（影子数组）

// 重新构建块的排序数组
// 当暴力修改散块后，该块内的数值可能变了，需要重新排序
void resort(int blo)
{
    v[blo].clear();
    // 从原数组的对应范围取值
    // 注意：这里取的是 a[i] 的原始值，因为 add[blo] 是懒惰标记，还没加到 a[i] 上
    for (int i = L[blo]; i <= R[blo]; i++)
    {
        v[blo].push_back(a[i]);
    }
    sort(v[blo].begin(), v[blo].end());
}

// 预处理：分块、计算边界、建立排序数组
void build()
{
    sz = sqrt(n);
    int tot = n / sz;
    if (n % sz) tot++;

    for (int i = 1; i <= tot; i++)
    {
        L[i] = (i - 1) * sz + 1;
        R[i] = i * sz;
    }
    R[tot] = n;

    for (int i = 1; i <= n; i++)
    {
        bel[i] = (i - 1) / sz + 1;
    }

    for (int i = 1; i <= tot; i++)
    {
        resort(i);
    }
}

// 区间修改：[l, r] 加上 x
void Add(int l, int r, int x)
{
    if (bel[l] == bel[r])
    {
        for (int i = l; i <= r; i++) a[i] += x;
        // 散块修改后，必须重新排序
        resort(bel[l]);
        return;
    }

    // 1. 修改左边的散块
    for (int i = l; i <= R[bel[l]]; i++) a[i] += x;
    resort(bel[l]);

    // 2. 修改中间的整块
    for (int blo = bel[l] + 1; blo < bel[r]; blo++)
    {
        add[blo] += x; // 只打标记，不破坏内部顺序
    }

    // 3. 修改右边的散块
    for (int i = L[bel[r]]; i <= r; i++) a[i] += x;
    resort(bel[r]);
}

// 区间查询：[l, r] 中小于 x 的元素个数
int Query(int l, int r, int x)
{
    int res = 0;

    if (bel[l] == bel[r])
    {
        for (int i = l; i <= r; i++)
        {
            // 真实值 = 原值 a[i] + 懒惰标记 add[bel[i]]
            if (a[i] + add[bel[i]] < x)
                res++;
        }
        return res;
    }

    // 1. 查询左边的散块（暴力）
    for (int i = l; i <= R[bel[l]]; i++)
    {
        if (a[i] + add[bel[i]] < x)
            res++;
    }

    // 2. 查询中间的整块（二分）
    for (int blo = bel[l] + 1; blo < bel[r]; blo++)
    {
        // 我们在 v[blo] 中查找 < x 的元素个数
        // v[blo] 存的是原始值，真实值要加上 add[blo]
        // 所以条件：v[blo][k] + add[blo] < x  =>  v[blo][k] < x - add[blo]
        int target = x - add[blo];
        // lower_bound 返回第一个 >= target 的位置，这个位置下标就是 < target 的个数
        res += lower_bound(v[blo].begin(), v[blo].end(), target) - v[blo].begin();
    }

    // 3. 查询右边的散块（暴力）
    for (int i = L[bel[r]]; i <= r; i++)
    {
        if (a[i] + add[bel[i]] < x)
            res++;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    build(); // 分块预处理

    cin >> q;
    while (q--)
    {
        int op, l, r, x;
        cin >> op >> l >> r >> x;

        if (op == 1)
        {
            Add(l, r, x);
        }
        else
        {
            cout << Query(l, r, x) << '\n';
        }
    }

    return 0;
}

