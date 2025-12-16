#include <bits/stdc++.h> // 包含 setprecision (用于控制小数位数)

using namespace std;
using ll = long long;   // 使用 ll 作为 long long 的别名

const int N = 1e4 + 9;  // 定义一个足够大的常量 N (10000 + 9)
int a[N];               // 定义一个大小为 N 的整型数组

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n;cin >> n; 

    // 循环 n 次，读取 n 个整数到数组 a 中
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 初始化最大值和最小值为数组的第一个元素
    ll mx = a[1];
    ll mi = a[1];

    // 从第二个元素开始遍历，查找最大值和最小值
    for (int i = 2; i <= n; ++i) {
        // 使用 max 和 min 函数更新 mx 和 mi
        //
        mx = max(mx, (ll)a[i]);
        mi = min(mi, (ll)a[i]);
    }

    // 输出最大值和最小值
    cout << "最大值: " << mx << '\n' << "最小值: " << mi << '\n';

    // 计算总和
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
    }

    // 计算并输出平均值
    // 1.0 * sum / n 是为了将整数运算提升为浮点数运算
    // fixed << setprecision(2) 是为了强制输出两位小数
    cout << "平均值: " << fixed << setprecision(2) << 1.0 * sum / n << '\n';

    return 0; } 
