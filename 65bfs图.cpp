#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;        // 最大城市数量
const int MOD = 1e9 + 7;      // 取模数

vector<int> g[N];             // 邻接表存储图
int d[N];                     // d[i]表示从城市1到城市i的最短距离
int dp[N];                    // dp[i]表示到城市i的最短路径方案数

void bfs(int x) {
    // 初始化距离为无穷大
    memset(d, 0x3f, sizeof(d));
    d[x] = 0;                  // 起点到自己的距离为0
    dp[x] = 1;                 // 起点到自己只有1种方案
    
    queue<int> q;
    q.push(x);                 // 将起点加入队列
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // 遍历所有相邻的城市
        for (int v : g[u]) {
            // 情况1: 发现更短的路径
            if (d[u] + 1 < d[v]) {
                d[v] = d[u] + 1;      // 更新最短距离
                dp[v] = dp[u];        // 重新计算方案数，继承u的方案数
                q.push(v);            // 将v加入队列（可能需要继续更新）
            }
            // 情况2: 发现相同长度的最短路径
            else if (d[u] + 1 == d[v]) {
                dp[v] = (dp[v] + dp[u]) % MOD;  // 累加方案数，注意取模
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // 读入m条边并建图
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);    // 双向边
        g[y].push_back(x);
    }
    
    bfs(1);  // 从城市1开始BFS
    
    cout << dp[n] << '\n';  // 输出到城市n的最短路径方案数
    
    return 0;
}

