#include <iostream>

using namespace std;
using ll = long long;

// 定义一个常量 N，虽然在这个简化版本中没用到，但保留下来也无妨
const int N = 50;

int main() {
    // 直接使用C++的十六进制字面量表示法
    // 0x 前缀告诉编译器，后面的数字是十六进制格式
    // 将这个十六进制数赋值给一个无符号整型变量 x
    unsigned int x = 0x2021abcd;

    // 直接输出变量 x 的值
    // cout 会默认以十进制格式输出整型变量
    cout << x << '\n';

    return 0; // main 函数返回 0，表示程序正常结束
}

