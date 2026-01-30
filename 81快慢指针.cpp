#include <iostream>
#include <algorithm> // 需要使用 min 函数
using namespace std;

const int N = 1e5 + 9;
int a[N];

int main()
{
    // 1. 输入输出优化，防止大数据超时
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, S;
    // 2. 读取 n 和 S
    cin >> n >> S; 

    // 3. 读取序列数据
    // 这里从下标 1 开始存储，方便计算区间长度
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // 4. 初始化答案为一个很大的数
    // 如果 ans 最终没变，说明没找到答案
    int ans = n + 1;

    // 5. 快慢指针主循环
    // i 是慢指针（左边界），j 是快指针（右边界）
    // 初始状态：j=0，表示还没开始扩展；sum=0，表示区间和为0
    for (int i = 1, j = 0, sum = 0; i <= n; ++i)
    {
        // 6. 扩展右边界 j
        // 只要当前的 j 还没到头，并且区间和 sum 还小于 S，就继续往后加
        // 这里 j < i 的判断是为了处理 i 走得比 j 快的情况（比如数组中有0的情况）
        while (j < n && sum < S)
        {
            j++;          // j 先右移一步
            sum += a[j];  // 把新位置的值加到 sum 里
        }

        // 7. 判断是否满足条件
        // 跳出上面的 while 循环有两种情况：
        // 情况A：sum >= S （满足了，这是一个美丽的区间）
        // 情况B：j == n （到头了，后面没数了）
        if (sum >= S)
        {
            // 如果满足了，就尝试更新最短长度
            // 长度 = 右边界 - 左边界 + 1
            ans = min(ans, j - i + 1);
        }

        // 8. 准备下一次循环（左边界 i 准备右移）
        // 既然 i 要往右移了，那么 a[i] 就要被踢出区间了
        // 所以 sum 要减去 a[i]
        sum -= a[i];
    }

    // 9. 输出结果
    // 如果 ans 还是初始值 n+1，说明从来没更新过，也就是没找到满足条件的区间
    if (ans == n + 1)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return 0;
}

