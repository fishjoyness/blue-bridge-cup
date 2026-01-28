#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005; // 根据题目数据范围 V <= 200，稍微开大一点即可

// dp[j] 表示背包容量为 j 时能获得的最大价值
int dp[N]; 

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, V; // n是物品种数，V是背包总容量
    // 注意：题目描述里输入第一行写的是 N 和 V，代码里变量名要对应
    cin >> n >> V;
    
    // 初始化 dp 数组，默认就是 0，对于求最大值的问题，初始为 0 即可
    
    // 遍历每一种物品
    for (int i = 1; i <= n; ++ i) {
        int w, v, s; // w:体积, v:价值, s:数量
        cin >> w >> v >> s;
        
        // 【核心逻辑】：把多重背包转化为 0/1 背包
        // 第 i 种物品有 s 件，我们就循环 s 次，每次只拿 1 件出来做决策
        while (s --) {
            // 0/1 背包的标准一维数组写法：逆序遍历
            for (int j = V; j >= w; j --) {
                // 状态转移方程：
                // 不拿第 i 件物品：dp[j]
                // 拿第 i 件物品：dp[j - w] + v
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    
    // 输出容量为 V 时的最大价值
    cout << dp[V] << '\n';
    
    return 0;
}

