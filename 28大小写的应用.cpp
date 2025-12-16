#include <bits/stdc++.h> 

using namespace std;

// 定义一个函数，用于转换单个字符的大小写
char convertedch(char ch) {
    if (islower(ch)) {
        // 如果是小写，转为大写
        ch = toupper(ch);
    } else if (isupper(ch)) {
        // 如果是大写，转为小写
        ch = tolower(ch);
    }
    // 如果不是字母，则不做任何处理，直接返回
    return ch;
}

int main() {
    string s;
    cout << "请输入一行字符串: ";
    getline(cin, s); // 读取一整行，包括空格

    // 使用范围 for 循环遍历字符串中的每一个字符
    // 使用 & 引用，这样修改 i 才会真正改变 s 中的字符
    for (auto &i : s) {
        i = convertedch(i); // 调用函数转换字符，并赋值回去
    }

    cout << "转换后的字符串: " << s << '\n';

    return 0;
}

