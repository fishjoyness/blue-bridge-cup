#include <bits/stdc++.h> 
using namespace std;

int main() {
    char ch1 = 'A';
    char ch2 = 'b';

    // --- 判断字符 ---
    // 使用 islower 函数判断字符是否为小写字母
    if (islower(ch1)) {
        cout << ch1 << " is a lowercase letter." << endl;
    } else {
        cout << ch1 << " is not a lowercase letter." << endl;
    }

    // 使用 isupper 函数判断字符是否为大写字母
    if (isupper(ch2)) {
        cout << ch2 << " is an uppercase letter." << endl;
    } else {
        cout << ch2 << " is not an uppercase letter." << endl;
    }

    cout << "\n--- 转换字符 ---\n";

    // --- 转换字符 ---
    // 使用 tolower 函数将字符转换为小写字母
    char lowercase_ch1 = tolower(ch1);
    cout << "Lowercase of " << ch1 << " is " << lowercase_ch1 << endl;

    // 使用 toupper 函数将字符转换为大写字母
    char uppercase_ch2 = toupper(ch2);
    cout << "Uppercase of " << ch2 << " is " << uppercase_ch2 << endl;

    return 0;
}

