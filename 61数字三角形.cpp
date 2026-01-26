#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N][N], dp[N][N];

int main() {
    int n;
    // 优化输入输出效率
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 读取三角形的行数
    cin >> n;
    
    // 读取三角形数据
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j];
            // 初始化dp数组，直接从最后一行开始
            dp[i][j] = a[i][j];
        }
    }
    
    // 从倒数第二行开始向上进行状态转移 (从下往上)
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            // 状态转移方程：
            // 当前位置的最大路径和 = 当前位置的值 + max(左下角的最大路径和, 右下角的最大路径和)
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    
    // 输出 dp[1][1]，即从塔顶出发的最大路径和
    cout << dp[1][1] << endl;
    
    return 0;
}

