#include <bits/stdc++.h>
using namespace std;

// 定义最大节点数，根据题目要求调整，这里开1e6比较保险
const int N = 1e6 + 9;

// g[x] 存储节点x的邻接表（连接了哪些点）
vector<int> g[N]; 

// sz[x] 表示以x为根的子树的大小（包含x自己）
int sz[N]; 
// mss[x] 表示如果删掉节点x，产生的最大连通块的大小
int mss[N]; 

int n;
int ans = 0; // 存储最终答案

// 深度优先搜索函数
// x: 当前正在访问的节点
// fa: x的父节点（防止回头搜）
void dfs(int x, int fa) {
    // 1. 初始化：子树大小初始为1（包含自己）
    sz[x] = 1;
    
    // 2. 遍历x的所有邻居
    for (const auto &y : g[x]) {
        // 如果y是x的爸爸，跳过，防止死循环
        if (y == fa) continue;
        
        // 递归访问儿子y
        dfs(y, x);
        
        // 回溯阶段：更新x的子树大小
        sz[x] += sz[y];
        
        // 核心步骤A：更新删掉x后，下方儿子子树产生的最大块
        // 删掉x后，y会变成独立的树，大小为sz[y]
        mss[x] = max(mss[x], sz[y]);
    }
    
    // 核心步骤B：更新删掉x后，上方“父树”产生的块
    // 删掉x后，除了下方的子树，x上面还有一大块连通区域
    // 那个区域的大小 = 总节点数n - x的子树大小sz[x]
    mss[x] = max(mss[x], n - sz[x]);
    
    // 核心步骤C：判断x是否为重心
    // 重心的定义：删除后产生的最大连通块最小。
    // 性质：如果最大连通块 mss[x] <= n/2，那么x一定是重心（或者满足题意的点）。
    if (mss[x] <= n / 2) {
        // 题目要求输出“剩余各个连通块中结点数的最大值”
        // 如果是重心，这个值就是 mss[x]
        ans = mss[x];
    }
}

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    
    // 读入n-1条边，建树
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    // 从节点1开始进行深搜（森林也是树，任一点皆可）
    dfs(1, 0);
    
    // 输出最终结果
    cout << ans << endl;
    
    return 0;
}

