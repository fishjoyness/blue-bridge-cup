#include <bits/stdc++.h>
//读入一个N进制的数，把它转换成M进制的数后输出
using namespace std;

// 使用 ll 作为 long long 的别名，方便书写
using ll = long long;

// solve 函数处理单个测试用例
void solve() {
    int n, m;
    cin >> n >> m; // 读入源进制 N 和目标进制 M
    string s;
    cin >> s;      // 读入 N 进制数字符串 S

    // --- 第一步：将 N 进制字符串 S 转换为十进制数 ---
    ll x = 0;
    for (char c : s) {
        int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else { // 'A' 到 'F'
//用 A~F表示字码10~ 15
            digit = c - 'A' + 10;
        }
        x = x * n + digit;
    }

    // --- 第二步：将十进制数 x 转换为 M 进制字符串 ---
    // 处理 x 为 0 的特殊情况
    if (x == 0) {
        cout << 0 << '\n';
        return;
    }

    string ans;
    while (x > 0) {
//我们会不断地对 x 进行除法和取余操作，直到 x 变成 0 为止
        int remainder = x % m;
        char ch;
        if (remainder < 10) {
            ch = '0' + remainder;
        } else { // 10 到 15
            ch = 'A' + (remainder - 10);
        }
        ans.push_back(ch); // 将计算出的字符添加到结果字符串的末尾
        x /= m;
    }

    // 因为计算过程是从低位到高位的，所以需要反转字符串
    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

int main() {
    // 提高cin/cout效率，在大量输入输出时很有用
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t; // 读入测试用例数量
    while (t--) {
        solve(); // 循环处理每个测试用例
    }
    return 0;
}

