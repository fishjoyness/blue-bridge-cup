// 哈夫曼编码”问题----贪心算法，使用最小优先队列（最小堆）来解决
#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 使用 long long 防止数据溢出

int main() {
    ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);

    int n;cin >> n;

	// greater<ll> 使得堆顶元素永远是最小的
    priority_queue<ll, vector<ll>, greater<ll>> pq;
//优先队列（默认的优先级是最大堆），存放的是长整数数字，用动态数组来，greater来定义优先级
//创建一个最小优先队列（最小堆）--------------每次取出来的是最小元素 
// 读取每种果子的数量并加入最小堆
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    ll ans = 0;

    // 当堆里至少还有两堆果子时，持续合并
    while (pq.size() >= 2) {
        // 取出当前最轻的两堆果子
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();

        // 合并它们，消耗的体力是 x + y
        ans += x + y;

        // 将合并后的新堆放回堆中
        pq.push(x + y);
    }

    cout << ans << '\n';

    return 0;
    
// priority_queue<int> max_pq;
//max_pq.push(10);
//max_pq.push(5);
//max_pq.push(20);
//cout << "最大堆的堆顶是: " << max_pq.top() << endl; // 输出 20

// 最小堆 (使用 greater)
//priority_queue<int, vector<int>, greater<int>> min_pq;
//min_pq.push(10);
//min_pq.push(5);
//min_pq.push(20);
//cout << "最小堆的堆顶是: " << min_pq.top() << endl; // 输出 5


    
    
}

