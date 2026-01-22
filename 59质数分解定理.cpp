#include <bits/stdc++.h>
using namespace std;

// 使用 pair 存储质因数和对应的指数
// first 存质数 p，second 存指数 cnt
vector<pair<int, int>> v;

int main() {
    int x;
    cin >> x;

    // 从小到大枚举所有可能的质因子 i
    // 只需枚举到 sqrt(x)，即 i*i <= x
    for (int i = 2; i * i <= x; ++i) {
        // 如果 i 不能整除 x，直接跳过
        if (x % i != 0) continue;

        // 如果能整除，由于是从小到大枚举，i 此时必然是质因数
        int cnt = 0;
        // 一直除，直到除干净
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        
        // 将该质因数及其指数存入 vector
        v.push_back({i, cnt});
    }

    // 如果最后 x 仍然大于 1，说明 x 本身是一个大于 sqrt(原x) 的质因数
    if (x > 1) {
        v.push_back({x, 1});
    }

    // 输出结果
    for (auto it : v) {
        cout << "质数: " << it.first << ", 指数: " << it.second << endl;
    }

    return 0;
}

