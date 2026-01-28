#include <bits/stdc++.h>
using namespace std;

const int N = 200010; // 根据题目数据范围 N,M <= 2*10^5，稍微开大一点

int pre[N], siz[N];

// 【函数1】查找根节点（路径压缩）
int root(int x) {
    // 如果 x 的父亲是自己，说明 x 就是根节点
    return pre[x] == x ? x : root(pre[x]);
}

// 【函数2】合并两个集合（按秩合并/启发式合并）
void merge(int x, int y) {
    // 第一步：分别找到 x 和 y 的根节点
    int rx = root(x), ry = root(y);
    
    // 第二步：如果根节点相同，说明他们本来就在同一个朋友圈里，无需操作
    if (rx == ry) return;
    
    // 第三步：启发式合并（为了防止树退化成链，我们尽量把小树接到大树下）
    // 如果 rx 的规模比 ry 大，就交换它们，保证 rx 是小树，ry 是大树
    if (siz[rx] > siz[ry]) swap(rx, ry);
    
    // 第四步：挂接操作，把小树 rx 的根节点接到大树 ry 的根节点下
    pre[rx] = ry;
    
    // 第五步：更新大树 ry 的规模，加上小树 rx 的人数
    siz[ry] += siz[rx];
}

int main() {
    // 加速输入输出，竞赛必备技巧
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // 初始化：最开始每个人都是独立的，自己的父亲是自己，规模为1
    for (int i = 1; i <= n; ++ i) {
        pre[i] = i; 
        siz[i] = 1; 
    }
    
    while (m --) {
        int op, x, y;
        cin >> op >> x >> y;
        
        if (op == 1) {
            // 操作1：用红绳连接 x 和 y -> 合并两个集合
            merge(x, y);
        } else {
            // 操作2：询问 x 和 y 是否是朋友 -> 判断根节点是否相同
            if (root(x) == root(y)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}

