
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    // 大根堆
    priority_queue<int> pq;
    ll sum = 0;
    
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        sum += x;
        pq.push(x);
    }
    
    while (q--) {
        int x;
        cin >> x;
        
        // 只要堆顶元素 >= x，就拿出来取模
        while (!pq.empty() && pq.top() >= x) {
            int val = pq.top();
            pq.pop();
            
            sum -= val;       // 减去旧值
            sum += val % x;   // 加上新值
            
            pq.push(val % x); // 放回堆
        }
        
        cout << sum << " ";
    }
    
    return 0;
}

