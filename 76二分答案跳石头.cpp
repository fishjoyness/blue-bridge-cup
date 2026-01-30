#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;
// a[] 存储石头距离起点的位置
// L 是总距离，n 是石头数量，m 是最多移走的石头数
int a[N], L, n, m;

// check 函数：检查如果要求最短跳跃距离为 mid，最少需要移走多少块石头
int check(int mid) {
    int res = 0;          // 记录需要移走的石头数量
    int lst = 0;          // lst 代表“上一块我落脚的石头”的下标，初始是 0 (起点)
    
    // 注意：我们需要把终点 L 也考虑进去，所以要遍历到 n + 1
    for (int i = 1; i <= n + 1; ++ i) {
        // a[i] 是当前石头的位置，a[lst] 是上一块落脚石头的位置
        // 注意：当 i == n+1 时，a[i] 应该是终点距离 L，需要手动把终点当作第 n+1 块石头处理
        int cur_pos = (i == n + 1) ? L : a[i];
        
        // 如果当前跳跃距离小于 mid，说明这块石头太近了，挡路了
        if (cur_pos - a[lst] < mid) {
            res++;       // 移走当前这块石头 (计数 +1)
            // 注意：lst 不变，人还站在原来的石头上，继续看下一块
        } else {
            lst = i;      // 距离够远，跳过去！落脚点更新为当前这块石头
        }
    }
    return res;
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> L >> n >> m;
    
    // 读入每块石头的位置
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    
    // 二分范围
    // l 是答案可能的最小值，r 是答案可能的最大值
    int l = 0, r = L + 1; // r 设为 L+1 确保 while 循环能覆盖到 L 的情况
    
    // 二分模板
    while (l + 1 != r) {   // 这是一个常见的二分写法，直到 l 和 r 相邻
        int mid = (l + r) / 2;
        
        // 如果需要移走的石头数量 <= 限制数量 m
        // 说明 mid 这个距离是可以达到的，我们甚至可以试着挑战更大的距离
        if (check(mid) <= m) {
            l = mid;      // 答案可能是 mid，或者更大，所以下界 l 移到 mid
        } else {
            // 需要移走的石头太多了，说明 mid 太大了，很难达到
            r = mid;      // 上界 r 移到 mid
        }
    }
    
    // 循环结束时，l 就是最大满足条件的距离
    cout << l << '\n';
    
    return 0;
}

