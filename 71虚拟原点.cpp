#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 9;      // 题目数据范围
const ll inf = 2e18;       // 无穷大

struct Edge {
    int x;                 // 邻居节点编号
    ll w;                  // 边权
    // 优先队列重载，构建小根堆
    bool operator < (const Edge &u) const {
        if (w != u.w) return w > u.w; // 距离小的优先
        return x < u.x;
    }
};

vector<Edge> g[N];         // 邻接表存图
ll d[N];                   // 存储最短距离
int n, m, k;

// Dijkstra 标准模板
void dijkstra(int start) {
    // 1. 初始化距离数组
    for (int i = 0; i <= n; ++ i) {
        d[i] = inf;
    }
    d[start] = 0; // 从 start 点开始出发
    
    priority_queue<Edge> pq;
    pq.push({start, 0});
    
    while (!pq.empty()) {
        Edge u = pq.top();
        pq.pop();
        
        // 如果当前点的距离已经不是最小的了，跳过
        if (u.w != d[u.x]) continue;
        
        // 2. 松弛操作：遍历 u.x 的所有邻边
        for (auto e : g[u.x]) {
            // 如果 "起点 -> u.x -> e.x" 比 "起点 -> e.x" 更短
            if (d[e.x] > d[u.x] + e.w) {
                d[e.x] = d[u.x] + e.w;
                pq.push({e.x, d[e.x]});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    
    // 清空图，处理多组测试数据
    for (int i = 0; i <= n; ++ i) {
        g[i].clear();
    }
    
    // 【核心步骤1：构建虚拟源点】
    // 题目给了 k 个起点，要求它们到终点 1 的最短路。
    // 我们建立一个虚拟的 "0号点"，让 0 号点分别连一条边权为 0 的线指向这 k 个起点。
    // 这样，从 0 号点出发跑最短路，相当于同时从这 k 个起点出发！
    for (int i = 1; i <= k; ++ i) {
        int x;
        cin >> x;
        g[0].push_back({x, 0}); // 0 -> x，花费为 0
    }
    
    // 读入正常的 m 条边
    for (int i = 1; i <= m; ++ i) {
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
    }
    
    // 【核心步骤2：从虚拟源点 0 出发跑 Dijkstra】
    dijkstra(0);
    
    // 【核心步骤3：输出结果】
    // d[1] 现在存的就是 "0 -> ... -> 起点 -> ... -> 1" 的最短距离
    // 因为 0 到起点的距离是 0，所以 d[1] 就是所有起点到 1 的最短距离中的最小值
    if (d[1] == inf) cout << -1 << '\n';
    else cout << d[1] << '\n';
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}

