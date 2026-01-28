#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 2e4 + 9; // 根据题目数据范围，背包容量 V 最大约 2000，这里开稍微大一点
int dp[M]; 

int main()
{
    // 加速输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; // n: 宝物种类数, m: 背包总容量
    cin >> n >> m;
    
    // 遍历每一种宝物
    for(int i = 1; i <= n; ++ i)
    {
        int v, w, s; // v: 单件体积, w: 单件价值, s: 数量
        cin >> v >> w >> s;
        
        // 【二进制优化核心逻辑】
        // 我们将 s 件物品拆分成 1, 2, 4, 8 ... 个为一组的新物品
        // k 代表当前这一组打包了多少个
        for(int k = 1; k <= s; s -= k, k <<= 1) 
        {
            // k <<= 1 等同于 k *= 2，即 1, 2, 4, 8...
            // 这一组物品的总体积是 k * v，总价值是 k * w
            // 01 背包逆序更新
            for(int j = m; j >= k * v; j--)
            {
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
        
        // 【处理剩余部分】
        // 循环结束后，如果 s 还有剩余（不足 2 的幂次），剩下的单独作为一组
        if(s > 0)
        {
            // 注意：这里循环条件是用 s * v（剩余的总体积），不是 k * v
            // dp[j - s * v] + s * w 是拿走剩余的 s 个物品
            for(int j = m; j >= s * v; j--)
            {
                dp[j] = max(dp[j], dp[j - s * v] + s * w);
            }
        }
    }
    
    cout << dp[m] << '\n';
    return 0;
}

