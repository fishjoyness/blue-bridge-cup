// 枚举算法是一种基本的算法思想，它通过穷举所有可能的情况来解决问题。
//它的基本思想是将问题的解空间中的每个可能的解都枚举出来并进行验证和比较
#include <iostream>

using namespace std;

// 判断一个整数 x 的数位中是否包含 2, 0, 1, 9
bool f(int x) {
    while (x > 0) {
        int y = x % 10; // 取出 x 的最后一位
        if (y == 2 || y == 0 || y == 1 || y == 9) {
            return true; // 如果包含，直接返回 true
        }
        x /= 10; // 去掉 x 的最后一位
    }
    return false; // 如果所有位都检查完了，都没包含，则返回 false
}

int main() {
    int n;
    cin >> n; // 读入范围的上限 n

    int ans = 0; // 初始化答案为 0
    for (int i = 1; i <= n; ++i) {
        if (f(i)) { // 检查 i 是否满足条件
            ans += i; // 如果满足，就累加到答案中
        }
    }

    cout << ans << '\n'; // 输出最终的和
    return 0;
}

