#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9; 

struct Edge {
    int x, y, c;
    // 重载 < 运算符，让 sort 按边权从小到大排
    bool operator < (const Edge &u) const {
        return c < u.c; 
    }
};

int pre[N]; // 并查集数组

// 并查集查根函数（路径压缩）
int root(int x) {
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> es;
    
    // 1. 读入边
    for (int i = 1; i <= m; ++ i) {
        int x, y, c;
        cin >> x >> y >> c;
        es.push_back({x, y, c});
    }
    
    // 2. 按边权从小到大排序
    sort(es.begin(), es.end());
    
    // 3. 初始化并查集（每个点自己是一个集合）
    for (int i = 1; i <= n; ++ i) {
        pre[i] = i;
    }
    
    int ans = 0;
    
    // 4. 遍历所有边，执行 Kruskal 算法
    for (int i = 0; i < es.size(); ++ i) {
        // 注意：这里不用 C++17 的结构化绑定，手动取出
        int x = es[i].x;
        int y = es[i].y;
        int c = es[i].c;
        
        // 如果 x 和 y 不在一个集合里（说明连通它们不会形成环）
        if (root(x) != root(y)) {
            pre[root(x)] = root(y); // 合并集合
            ans = max(ans, c);      // 更新当前选中的最大边权
        }
    }
    
    cout << ans << '\n';
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t; // 输入测试用例数
    
    while (t--) {
        solve();
    }
    
    return 0;
}

