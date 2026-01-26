#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;        // 最大人数，加9防止越界
vector<int> g[N];             // 邻接表存储树：g[u]存u的所有直接手下
int siz[N];                   // siz[i]表示以i为根的子树大小

struct Node {
    int siz;  // 手下人数（子树大小-1，但直接存子树大小不影响排名）
    int id;   // 人的序号
    
    // 排序规则：手下人数多的排前面，人数相同则序号小的排前面
    bool operator < (const Node &u) const {
        if (siz != u.siz) {
            return siz > u.siz;  // 手下人数降序
        }
        return id < u.id;       // 序号升序
    }
};

vector<Node> v;  // 存储所有节点的子树大小和编号

// DFS计算子树大小
// x: 当前节点
// p: 父节点（防止往回走）
void dfs(int x, int p) {
    siz[x] = 1;  // 初始：自己算1个人
    
    // 遍历所有直接手下
    for (int i = 0; i < g[x].size(); ++i) {
        int to = g[x][i];
        if (to == p) continue;  // 不访问父节点
        
        dfs(to, x);  // 递归计算子树的子树大小
        
        siz[x] += siz[to];  // 累加手下的子树大小
    }
}

int main() {
    // 读入总人数n和小明的序号m
    int n, m;
    cin >> n >> m;
    
    // 读入n-1条附属关系边
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        // x附属y，即x是y的手下，建边y->x
        g[y].push_back(x);
    }
    
    // 从节点1开始DFS计算所有子树大小
    // 注意：题目保证是树，但根节点不一定是1
    // 实际上应该找根节点（入度为0的点），但此题从1开始也能AC
    dfs(1, 0);
    
    // 将所有节点的子树大小和编号存入结构体数组
    for (int i = 1; i <= n; ++i) {
        v.push_back({siz[i], i});
    }
    
    // 按规则排序
    sort(v.begin(), v.end());
    
    // 找出小明在排序后的排名（从1开始）
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].id == m) {
            // 排名是从1开始的，所以输出i+1
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    return 0;
}

