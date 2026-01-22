#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;  // m是背包容量，n是物品数量
    
    int w[31], v[31];  // 物品重量和价值
    
    // 输入每个物品的重量和价值
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    
    // 完全背包 - 二维数组解法
    int dp_2d[32][201] = {0};  // 二维DP数组，自动初始化为0
    
    for (int i = 1; i <= n; i++) {  // 遍历每个物品
        for (int j = 1; j <= m; j++) {  // 遍历每个容量
            dp_2d[i][j] = dp_2d[i-1][j];  // 继承上一层状态（不选当前物品）
            if (j >= w[i]) {  // 容量足够，考虑选当前物品
                dp_2d[i][j] = max(dp_2d[i][j], dp_2d[i][j-w[i]] + v[i]);
            }
        }
    }
    
    // 完全背包 - 一维滚动数组解法（空间优化）
    int dp_1d[201] = {0};  // 一维DP数组，自动初始化为0
    
    for (int i = 1; i <= n; i++) {  // 遍历每个物品
        for (int j = w[i]; j <= m; j++) {  // 从小到大遍历容量
            dp_1d[j] = max(dp_1d[j], dp_1d[j-w[i]] + v[i]);
        }
    }
    
    // 输出两种方法的结果（应该相同）
    cout << "二维数组结果: " << dp_2d[n][m] << endl;
    cout << "一维滚动数组结果: " << dp_1d[m] << endl;
    
    return 0;
}

