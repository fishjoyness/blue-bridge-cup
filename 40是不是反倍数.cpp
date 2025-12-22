#include <iostream>

using namespace std;

// 全局变量 a, b, c，这样 f 函数里就可以直接用了
int a, b, c;

// 判断 x 是否是“反倍数”
bool f(int x) {
// 如果 x 除以 a, b, c 的余数都不为0，说明它不是 a, b, c 中任何一个的整数倍
    return (x % a != 0) && (x % b != 0) && (x % c != 0);
}

int main() {
    int n;
    cin >> n;        // 读入范围上限 n
    cin >> a >> b >> c; // 读入三个整数 a, b, c

    int ans = 0; // 初始化计数器为 0
    for (int i = 1; i <= n; ++i) {
        if (f(i)) { // 检查 i 是否是“反倍数”
            ans++;  // 如果是，计数器加 1
        }
    }

    cout << ans << '\n'; // 输出最终的计数结果
    return 0;
}

