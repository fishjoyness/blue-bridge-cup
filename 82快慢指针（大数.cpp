#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N];

int main()
{
    // 1. 优化输入输出效率
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    // 2. 读取输入
    // n: 序列长度
    // m: 判断"大数"的阈值（题目描述中有些混乱，这里以代码逻辑为准：数值 >= m 视为大数）
    // k: 需要的"大数"的最少个数
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    long long ans = 0; // 答案可能很大，建议用 long long 防止溢出，虽然 int 也能过某些数据
    int cnt = 0;       // 当前区间 [i, j] 中"大数"的个数

    // 3. 快慢指针循环
    // i: 慢指针（左边界），从 1 遍历到 n
    // j: 快指针（右边界），初始为 0
    for (int i = 1, j = 0, cnt = 0; i <= n; ++i)
    {
        // 4. 核心逻辑：移动 j，直到区间 [i, j] 中的大数个数 >= k
        // 条件解析：
        // (i > j): 只有当 j 落后于 i 时（比如 i 刚开始走，j 还没动），必须让 j 追上来
        // (j + 1 <= n && cnt < k): 只要 j 还没越界，且大数个数还不够，就继续往右加
        while (i > j || (j + 1 <= n && cnt < k))
        {
            j++; // j 右移一步
            // 判断新加入的 a[j] 是否是大数（>= m）
            // (a[j] >= m) 结果为 1（真）或 0（假），直接加到 cnt 上
            if (a[j] >= m)
                cnt++;
        }

        // 5. 统计答案
        // 如果此时 cnt >= k，说明对于左端点 i，我们已经找到了最小的合法右端点 j
        // 那么从 j 到 n 的任意位置做右端点，区间 [i, ...] 都是合法的
        // 共有 n - j + 1 个选择
        if (cnt >= k)
        {
            ans += (n - j + 1);
        }

        // 6. 准备下一轮（左边界 i 将要右移）
        // 移出 a[i]，如果它是大数，计数器要减 1
        if (a[i] >= m)
        {
            cnt--;
        }
    }

    // 7. 输出结果
    cout << ans << '\n';

    return 0;
}

