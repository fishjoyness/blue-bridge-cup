//这个题目是经典的“最大环”问题，通常用 DFS 结合时间戳（dfn 数组）来解决。
//就是用 DFS 遍历图，并记录每个节点被访问的时间戳，
//当遇到一个已经访问过的节点时，判断它是否是当前搜索路径上的节点，
//从而计算出环的长度。
#include <iostream>
#include <algorithm> // 用于 max 函数
using namespace std;

const int N = 1e5 + 9; // 定义一个足够大的数组大小
int n;
int a[N]; // 存储每个小朋友崇拜的下一个小朋友
int dfn[N]; // 记录每个节点被访问的时间戳
int idx; // 全局时间戳计数器
int ans = 0; // 记录最大的环的长度

// 深度优先搜索函数
void dfs(int x) {
    // 给当前节点 x 分配一个时间戳
    dfn[x] = ++idx;

    // 获取 x 崇拜的小朋友 y
    int y = a[x];

    // 如果 y 还没有被访问过
    if (!dfn[y]) {
        // 递归访问 y
        dfs(y);
    } 
    // 如果 y 已经被访问过，并且 y 是在当前搜索路径上（即 y 的时间戳 >= 当前路径的最小时间戳）
    else if (dfn[y] >= idx - n) {
        // 计算环的长度：当前节点的时间戳 - y 的时间戳 + 1
        ans = max(ans, dfn[x] - dfn[y] + 1);
    }
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // 读取输入
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 遍历所有节点，确保每个节点都被访问到
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) { // 如果节点 i 还没有被访问
            // 开始一个新的 DFS，设置当前路径的最小时间戳
            // 这里用一个巧妙的方法：将 idx + 1 作为“虚拟”的起始时间戳
            // 这样可以确保只有当前路径上的节点才会被计算在内
            dfs(i);
        }
    }

    // 输出最大的环的长度
    cout << ans << endl;

    return 0;
}

