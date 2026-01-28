//3433 
#include <bits/stdc++.h>
using namespace std;

// 优先队列默认是大根堆（大的在队头）
// 底层容器默认是 vector<int>
priority_queue<int> pq;

int main() {
    // 加速输入输出，竞赛必备
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    // sum 记录当前所有元素的和
    long long sum = 0;
    
    // 1. 读入数组元素
    for (int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;
        sum += x;            // 累加到总和
        pq.push(x);          // 将元素放入优先队列
    }
    
    // 2. 处理 q 次操作
    for (int i = 1; i <= q; ++ i) {
        int x;
        cin >> x;            // 读入当前操作的模数 x
        
        // 核心优化循环：
        // 只要堆顶元素 >= x，就需要处理它。
        // 如果堆顶元素 < x，说明堆里剩下的所有元素都不用动了（性质：y < x 则 y%x == y）
        while (!pq.empty() && pq.top() >= x) {
            int y = pq.top(); // 取出当前最大的数
            pq.pop();         // 从堆中移除
            
            sum -= y;         // 从总和里减去原来的数
            
            int new_val = y % x; // 计算取模后的新值
            
            sum += new_val;   // 把新值加回总和
            pq.push(new_val); // 把新值放回堆中
        }
        
        // 输出本次操作后的总和
        cout << sum << " ";
    }
    
    return 0;
}

