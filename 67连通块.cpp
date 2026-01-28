#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int pre[N], siz[N];

// 【函数1】查找根节点（路径压缩）
int root(int x) {
    // 如果 x 的父亲是自己，说明 x 就是根节点
    return pre[x] == x ? x : root(pre[x]);
}

// 【函数2】合并两个集合（按秩合并）
void merge(int x, int y) {
    // 1. 分别找到 x 和 y 的根节点
    int rx = root(x), ry = root(y);
    
    // 2. 如果根节点相同，说明他们已经连通了，无需操作
    if (rx == ry) return;
    
    // 3. 启发式合并：把小的树挂到大的树下面，保证树的高度尽可能低
    if (siz[rx] > siz[ry]) swap(rx, ry);
    
    // 4. 合并：rx 接到 ry 下面
    pre[rx] = ry;
    
    // 5. 更新大树 ry 的规模
    siz[ry] += siz[rx];
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // 初始化：最开始每个人都是独立的，自己是自己的父亲，规模为1
    for (int i = 1; i <= n; ++ i) {
        pre[i] = i;
        siz[i] = 1;
    }
    
    // 处理每一条输入的边
    while (m --) {
        int x, y;
        cin >> x >> y;
        // 读入一条边，就把这两个点所在的集合合并
        merge(x, y);
    }
    
    // 【关键步骤】统计连通块的个数
    int cnt = 0;
    for (int i = 1; i <= n; ++ i) {
        // 如果 i 的父亲是它自己，说明 i 是某个连通块的根节点（代表）
        if (pre[i] == i) {
            cnt++;
        }
    }
    
    // 【核心逻辑】如果有 cnt 个连通块，要把它们连起来，最少需要 cnt - 1 条边
    cout << cnt - 1 << endl;
    
    return 0;
}

