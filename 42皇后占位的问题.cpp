#include <iostream>
using namespace std;

const int N = 20; // 定义一个足够大的常量N
int n;
int ans = 0; // 用来记录解的个数
int vis[N][N]; // 表示被多少个皇后占用了

// 深度优先搜索函数
void dfs(int dep) {
    // 如果已经处理完第 n 行，说明找到了一个解
    if (dep == n + 1) {
        ans++;
        return;
    }

    // 遍历当前行的每一列
    for (int i = 1; i <= n; ++i) {
        // 如果当前位置 (dep, i) 被占用，则跳过
        if (vis[dep][i]) {
            continue;
        }

        // --- 修改状态：将皇后放置在 (dep, i) 位置 ---
        // 1. 标记第 i 列
        for (int _i = 1; _i <= n; ++_i) {
            vis[_i][i]++;
        }
        // 2. 标记主对角线 (从左上到右下)
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j) {
            vis[_i][_j]++;
        }
        // 3. 标记副对角线 (从右上到左下)
        for (int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j) {
            vis[_i][_j]++;
        }
        // 4. 标记另一条主对角线 (从左下到右上)
        for (int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j) {
            vis[_i][_j]++;
        }
        // 5. 标记另一条副对角线 (从右下到左上)
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j) {
            vis[_i][_j]++;
        }

        // 递归到下一行
        dfs(dep + 1);

        // --- 恢复现场：回溯，取消标记 ---
        // 1. 取消第 i 列的标记
        for (int _i = 1; _i <= n; ++_i) {
            vis[_i][i]--;
        }
        // 2. 取消主对角线的标记
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j) {
            vis[_i][_j]--;
        }
        // 3. 取消副对角线的标记
        for (int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j) {
            vis[_i][_j]--;
        }
        // 4. 取消另一条主对角线的标记
        for (int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j) {
            vis[_i][_j]--;
        }
        // 5. 取消另一条副对角线的标记
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j) {
            vis[_i][_j]--;
        }
    }
}

int main() {
    // 输入 N
    cin >> n;
    // 从第 1 行开始搜索
    dfs(1);
    // 输出解的个数
    cout << ans << endl;
    return 0;
}

