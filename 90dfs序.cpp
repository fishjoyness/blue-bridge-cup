#include <bits/stdc++.h>
using namespace std;

// 定义常量，最大节点数根据题目范围设定
const int N = 2e5 + 9;

// g[N] 存储树的邻接表
vector<int> g[N];

// c[i] 存储节点i的颜色
int c[N];

// prefix[i][col] 前缀和数组
// 定义：在DFS序的第1个到第i个节点中，颜色为col的节点出现的总次数
int prefix[N][101];

// dfn[x] 存储节点x在DFS序中的位置（时间戳）
// idx[t] 存储DFS序第t个位置对应的节点编号
// sz[x] 存储以x为根的子树的大小（在DFS序中的区间长度）
int dfn[N], idx[N], sz[N];
int tot; // DFS序计数器

// 深度优先搜索，将树拍平
void dfs(int x, int fa) {
    // 1. 记录当前节点x的DFS序位置
    dfn[x] = ++tot;
    // 2. 建立反向映射：通过DFS序位置找到对应的节点
    idx[dfn[x]] = x;
    
    // 3. 初始化子树大小为1（包含自己）
    sz[x] = 1;
    
    // 4. 遍历子节点
    for (const auto &y : g[x]) {
        if (y == fa) continue; // 防止回头
        dfs(y, x);
        // 5. 回溯时累加子树大小
        sz[x] += sz[y];
    }
}

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    // 读入每个节点的颜色
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    
    // 读入树的边，建立邻接表
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // 1. 进行DFS，计算dfn、idx、sz数组
    dfs(1, 0);
    
    // 2. 预处理前缀和
    // 这里的i代表DFS序的位置（1 到 n），j代表颜色（1 到 100）
    for (int j = 1; j <= 100; ++j) {
        for (int i = 1; i <= n; ++i) {
            // 获取DFS序第i个位置对应的真实节点
            int node = idx[i];
            // 状态转移：等于上一次的次数 + (当前节点颜色是否等于j)
            // 注意：prefix[j] 是一维数组的一部分，这里写成 prefix[i][j] 对应二维数组的定义
            // 你的代码中 prefix 是 N x 101 的，所以第一维是i(位置)，第二维是j(颜色)
            if (c[node] == j) {
                prefix[i][j] = prefix[i - 1][j] + 1;
            } else {
                prefix[i][j] = prefix[i - 1][j];
            }
        }
    }
    
    // 3. 处理询问
    while (q--) {
        int x;
        cin >> x;
        
        // 计算以x为根的子树在DFS序中的区间范围
        // 左端点 l：x的DFS序位置
        // 右端点 r：l + 子树大小 - 1
        int l = dfn[x];
        int r = l + sz[x] - 1;
        
        int ans = 0;
        
        // 4. 枚举颜色，统计在区间 [l, r] 内出现的颜色
        for (int i = 1; i <= 100; ++i) {
            // 利用前缀和计算区间内颜色i的数量
            // 数量 = prefix[r][i] - prefix[l-1][i]
            int cnt = prefix[r][i] - prefix[l - 1][i];
            
            // 如果数量大于0，说明该颜色存在，答案+1
            if (cnt > 0) {
                ans++;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}

