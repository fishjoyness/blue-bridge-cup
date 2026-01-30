#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 定义一个小根堆（优先队列）
// greater<ll> 使得堆顶元素是最小的元素
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main()
{
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // 读入每个部落的人数并放入小根堆
    for(int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }

    ll ans = 0;

    // 当堆中元素大于1个时，持续合并
    // 因为每次合并两个，最后剩1个部落，所以一共需要进行 n-1 次操作
    while(pq.size() > 1)
    {
        // 取出当前人数最少的两个部落
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();

        // 计算本次谈判的花费
        ll cost = x + y;
        
        // 累加到总花费中
        ans += cost;

        // 将合并后的新部落重新放回堆中，以便后续参与合并
        pq.push(cost);
    }

    // 输出最小花费
    cout << ans << '\n';

    return 0;
}

