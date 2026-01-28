#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9; // 根据题目范围设定，如果V很大可能需要开更大
const ll inf = 2e18;

struct Edge {
    int to; // 邻居节点
    ll w;   // 边权（距离）
    // 重载 < 运算符，让优先队列变成小根堆（距离小的在队头）
    bool operator < (const Edge &u) const {
        return w > u.w; 
    }
};

vector<Edge> g[N]; // 邻接表存图
ll d[N];           // d[x] 存储节点 x 到已连通集合的最短距离
int n, m;

ll prim() {
    // 1. 初始化距离数组为无穷大
    for (int i = 1; i <= n; ++ i) {
        d[i] = inf;
    }
    
    priority_queue<Edge> pq; // 优先队列
    bitset<N> vis;          // 标记数组，记录节点是否在集合（连通区域）内
    
    // 2. 从 1 号点开始（起点）
    // 注意：Prim 算法中，起点到自己的距离视为 0
    d[1] = 0;
    pq.push({1, 0});
    
    ll res = 0; // 用来记录生成树中最大的边权
    
    // 3. 开始扩张集合
    while (pq.size()) {
        Edge u = pq.top();
        pq.pop();
        
        int x = u.to;
        
        // 如果这个点已经在集合里了，跳过
        if (vis[x]) continue;
        vis[x] = true; // 标记为已加入集合
        
        // 【关键步骤】更新答案
        // d[x] 代表把 x 连进集合所需要的那条边的长度
        // 我们要找所有这些边里最长的一条
        res = max(res, d[x]);
        
        // 4. 松弛操作：查看 x 的所有邻居 y
        for (const auto &e : g[x]) {
            int y = e.to;
            ll w = e.w;
            
            // 如果 y 还没进集合，且 x->y 这条边比当前记录的 y 到集合的距离更短
            if (!vis[y] && w < d[y]) {
                d[y] = w; // 更新 y 到集合的最短距离
                pq.push({y, d[y]});
            }
        }
    }
    
    return res;
}

void solve() {
    cin >> n >> m;
    
    // 清空图，处理多组测试数据
    for (int i = 1; i <= n; ++ i) {
        g[i].clear();
    }
    
    // 读入边（无向图，存两次）
    for (int i = 1; i <= m; ++ i) {
        int x, y;
        ll c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    
    cout << prim() << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t; // 输入测试用例数
    while (t--) {
        solve();
    }
    
    return 0;
}

