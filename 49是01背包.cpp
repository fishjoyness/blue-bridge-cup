//0-1背包问题的回溯解法
//用DFS（深度优先搜索）来解决0-1背包问题的思路。

//想象你在整理背包，每个物品只能选或不选，目标是装下价值最高的物品组合。
//当前操作？ - 面对第i个物品，你有两个选择：
//不选：背包容量不变
//选：背包容量减少w[i]
 
//子问题？ - 在剩余容量为c时，从前i个物品中能获得的最大价值
//下一个子问题？ - 分两种情况：
//不选：考虑前i-1个物品，容量还是c
//选：考虑前i-1个物品，容量变为c-w[i]，并加上当前物品的价值v[i]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 全局变量存储物品信息和结果
vector<int> w, v;  // 体积和价值
int n, capacity;
int maxValue = 0;

// DFS回溯函数
void dfs(int i, int currentCapacity, int currentValue) {
    // 回溯三问：子问题 - 在剩余容量为currentCapacity时，从前i个物品中能获得的最大价值
    
    // 基本情况：所有物品都考虑完了
    if (i == n) {
        maxValue = max(maxValue, currentValue);
        return;
    }
    
    // 回溯三问：当前操作 - 枚举第i个物品选或不选
    
    // 1. 不选第i个物品
    dfs(i + 1, currentCapacity, currentValue);
    
    // 2. 选第i个物品（如果容量允许）
    if (currentCapacity >= w[i]) {
        dfs(i + 1, currentCapacity - w[i], currentValue + v[i]);
    }
}

int main() {
    // 输入
    cout << "请输入物品数量n和背包容量capacity: ";
    cin >> n >> capacity;
    
    w.resize(n);
    v.resize(n);
    
    cout << "请输入每个物品的体积和价值: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    
    // 开始DFS
    dfs(0, capacity, 0);
    
    // 输出结果
    cout << "最大价值: " << maxValue << endl;
    
    return 0;
}

