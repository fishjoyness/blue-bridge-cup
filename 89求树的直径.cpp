#include <bits/stdc++.h>
using namespace std;

// 定义数据类型和常量
typedef long long ll;
const int N = 1e5 + 9;

// g[N] 存储树的邻接表
vector<int> g[N];

// dep1: 以1为根时的深度（即从1号点出发到各点的距离）
// depU: 以直径端点U为根时的深度
// depV: 以直径端点V为根时的深度
int dep1[N], depU[N], depV[N];

// 深度优先搜索函数，计算从根节点 s 到所有节点的距离
// x: 当前节点, fa: 父节点, dep: 存储距离的数组
void dfs(int x, int fa, int dep[]) {
    // 距离 = 父节点的距离 + 1 (题目中每条边长度默认为1)
    dep[x] = dep[fa] + 1;
    // 遍历邻居
    for (const auto &y : g[x]) {
        if (y == fa) continue; // 不回头
        dfs(y, x, dep);
    }
}

void solve() {
    int n, k, c;
    cin >> n >> k >> c;
    
    // 记得清空邻接表，因为有多组测试数据
    for (int i = 1; i <= n; ++i) g[i].clear();
    
    // 读入树的边
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // 1. 找到直径的第一个端点 U
    // 假设 dep[0] = -1，这样 dep[1] = 0，深度即为边数
    dep1[0] = depU[0] = depV[0] = -1; 
    dfs(1, 0, dep1);
    
    int U = 1;
    for (int i = 1; i <= n; ++i) {
        if (dep1[i] > dep1[U]) U = i;
    }
    
    // 2. 找到直径的第二个端点 V，同时计算 depU[]
    dfs(U, 0, depU);
    
    int V = 1;
    for (int i = 1; i <= n; ++i) {
        if (depU[i] > depU[V]) V = i;
    }
    
    // 3. 计算 depV[]
    dfs(V, 0, depV);
    
    // 4. 枚举所有点作为根，计算最大盈利
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        // 价值 = max(到U的距离, 到V的距离) * k
        // 注意：这里dep存储的是路径长度（边数），如果是"路径长度最大值"直接用即可
        // 如果题目强调是"最大深度 * k"，这里就是树的深度乘系数k
        ll val = max(depU[i], depV[i]) * (ll)k;
        
        // 代价 = 从1移动到i的花费 = dist(1, i) * c
        // 因为初始根是1，dep1[i] 存的就是 1 到 i 的距离
        ll cost = dep1[i] * (ll)c;
        
        // 更新最大盈利
        ans = max(ans, val - cost);
    }
    
    cout << ans << '\n';
}

int main() {
    // 优化输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

