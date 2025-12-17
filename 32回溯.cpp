#include <iostream>
const int N = 10; 

int a[N];      // 用来存放每一层选择的数字
bool vis[N];   // 标记数组，vis[i]为true表示数字i已经被使用过
int n;         // 需要排列的数字总数，比如 n=3 就是排列 1, 2, 3

// 深度优先搜索函数，dep 代表当前搜索的深度
void dfs(int dep) {
// 递归的出口条件。当 dep 等于 n+1 时，
//意味着我们已经成功填充了 n 个位置（从第1层到第n层），
//找到了一个完整的、长度为 n 的排列。
    if (dep == n + 1) {
        // 打印这个完整的排列
        for (int i = 1; i <= n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << '\n';
        return; // 返回上一层，继续寻找其他排列
    }

    // 尝试在当前层 (dep) 放入每一个可能的数字 i
    for (int i = 1; i <= n; ++i) {
// 在当前的第 dep 层，尝试把所有可能的数字（从 1 到 n）都放一遍
        if (vis[i]) {
            continue;
        }

// 如果 vis[i] 是 true，说明数字 i 在前面的层已经被用过了，不能再用了
        vis[i] = true;
// 将数字 i 存入当前层的位置
        a[dep] = i;
// 递归调用，去填充下一层 (dep + 1)
        dfs(dep + 1);
        // 当从下一层返回后，需要撤销当前层的选择，
        // 以便让 for 循环可以尝试其他数字。
        vis[i] = false;
//选择 -> 探索 -> 撤销 
    }
}

int main() {
    n = 3; // 我们来测试一下 n=3 的全排列
    dfs(1); // 从第 1 层开始搜索
    return 0;
}

