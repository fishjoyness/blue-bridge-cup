#include <bits/stdc++.h> 
using namespace std;
typedef long long ll; // 使用 ll 代替 long long，更简洁

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; // 糖果的种类数
    cin >> n;

    ll sum = 0; // 所有糖果的总数
    ll mx = 0;  // 数量最多的那种糖果的数量

    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x; // 读取每种糖果的数量
        sum += x;     // 累加到总数
        mx = max(mx, x); // 更新最大值
    }

    // 核心判断逻辑
    if (sum - mx >= mx - 1) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}

