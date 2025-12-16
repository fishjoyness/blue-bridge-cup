#include <bits/stdc++.h>  
using namespace std;
using ll = long long;   // 使用 ll 作为 long long 的别名

const int N = 1e4 + 9;  // 定义一个足够大的常量 N (10000 + 9)
int a[N];               // 定义一个大小为 N 的整型数组

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n;cin >> n; // 读取整数 n
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 输出最大值
    cout << "最大值: " << *max_element(a+1, a + 1 + n) << '\n';

    // 输出最小值
    cout << "最小值: " << *min_element(a+1, a + 1 + n) << '\n';

    // 计算总和
    ll sum = 0; // 使用 long long 防止数据过大导致溢出
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
    }

    // 计算并输出平均值
    // 1.0 * sum / n 是为了将整数运算提升为浮点数运算
    // fixed << setprecision(2) 是为了强制输出两位小数
    cout << "平均值: " << fixed << setprecision(2) << 1.0 * sum / n << '\n';

    return 0;
}

