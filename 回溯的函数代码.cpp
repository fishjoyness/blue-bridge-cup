#include <iostream>
using namespace std; 
const int N = 10; 

int n; // 定义全局变量 n
int a[N]; // 定义全局数组 a
bool vis[N]; // 定义全局数组 vis
    
void dfs(int dep) {
    // 如果深度等于n+1，说明已经找到了一个完整的排列
    if (dep == n + 1) {
        // 遍历输出当前排列
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n"; // 换行
        return;       // 返回上一层
    }

    // 向下搜索
    for (int i = 1; i <= n; ++i) {
        // 排除不合法的路径（如果这个数字已经被使用过了，就跳过）
        if (vis[i]) continue;

        // 修改状态：标记当前数字 i 为已使用
        vis[i] = true;
        // 将数字 i 存入当前深度的位置
        a[dep] = i;

        // 下一层递归
        dfs(dep + 1);

        // 回溯：恢复状态，让这个数字 i 在后续路径中可以被再次使用
        vis[i] = false;
    }
}

int main() {
        return 0;
}
