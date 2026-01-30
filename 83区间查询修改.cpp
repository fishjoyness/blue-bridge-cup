#include <bits/stdc++.h>
using namespace std;

// 数据范围 1e5，数组开大一点
const int N = 1e5 + 9;

// a[]: 原数组
// sum[]: 每个块的区间和
// add[]: 每个块的懒惰标记（表示这个块整体加了多少）
// bel[]: bel[i] 表示第 i 个元素属于哪个块
// L[], R[]: 每个块的左右边界
long long a[N], sum[N], add[N];
int L[N], R[N], bel[N];
int n, q;
int sz; // 块的大小

// 读入并初始化分块结构
void build()
{
    // 块的大小设为 sqrt(n)
    sz = sqrt(n);
    
    // 计算总块数
    int tot = n / sz;
    if (n % sz) tot++; // 如果除不尽，块数+1

    // 初始化每个块的边界
    for (int i = 1; i <= tot; i++)
    {
        L[i] = (i - 1) * sz + 1;
        R[i] = i * sz;
    }
    // 修正最后一个块的右边界，防止超出 n
    R[tot] = n;

    // 记录每个元素属于哪个块，并初始化块的和
    for (int i = 1; i <= n; i++)
    {
        bel[i] = (i - 1) / sz + 1;
        sum[bel[i]] += a[i];
    }
}

// 区间修改：[l, r] 每个数加上 x
void Add(int l, int r, long long x)
{
    // 情况1：l 和 r 在同一个块里，直接暴力修改
    if (bel[l] == bel[r])
    {
        for (int i = l; i <= r; i++)
        {
            a[i] += x;       // 原数组修改
            sum[bel[i]] += x; // 块的和同步修改
        }
        return;
    }

    // 情况2：l 和 r 跨越了多个块，分三部分处理
    
    // 第一部分：处理 l 所在块的零散部分 (从 l 到 该块末尾)
    for (int i = l; i <= R[bel[l]]; i++)
    {
        a[i] += x;
        sum[bel[i]] += x;
    }

    // 第二部分：处理中间的整块
    // 我们只需要修改 add 标记和 sum 块和，不需要遍历内部元素
    for (int blo = bel[l] + 1; blo < bel[r]; blo++)
    {
        add[blo] += x;                       // 打上懒惰标记
        sum[blo] += x * (R[blo] - L[blo] + 1); // 块和增加了 (元素个数 * x)
    }

    // 第三部分：处理 r 所在块的零散部分 (从该块开头 到 r)
    for (int i = L[bel[r]]; i <= r; i++)
    {
        a[i] += x;
        sum[bel[i]] += x;
    }
}

// 区间查询：求 [l, r] 的和
long long getsum(int l, int r)
{
    long long res = 0;

    // 情况1：在同一个块
    if (bel[l] == bel[r])
    {
        for (int i = l; i <= r; i++)
        {
            // 真实值 = 原值 + 懒惰标记
            res += a[i] + add[bel[i]];
        }
        return res;
    }

    // 情况2：跨越多个块
    
    // 第一部分：l 所在块的零散部分
    for (int i = l; i <= R[bel[l]]; i++)
    {
        res += a[i] + add[bel[i]];
    }

    // 第二部分：中间的整块
    // 直接用 sum[] 加上懒惰标记带来的增量
    for (int blo = bel[l] + 1; blo < bel[r]; blo++)
    {
        res += sum[blo] + add[blo] * (R[blo] - L[blo] + 1);
    }

    // 第三部分：r 所在块的零散部分
    for (int i = L[bel[r]]; i <= r; i++)
    {
        res += a[i] + add[bel[i]];
    }

    return res;
}

int main()
{
    // 优化输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 1. 建立分块结构
    build();

    while (q--)
    {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1)
        {
            // 修改操作：读入 x
            long long x;
            cin >> x;
            Add(l, r, x);
        }
        else
        {
            // 查询操作
            cout << getsum(l, r) << '\n';
        }
    }

    return 0;
}

