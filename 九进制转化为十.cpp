#include <iostream>
#include <string>
//九进制正整数(2022)9转换成十进制等于多少?
using namespace std;
using ll=long long; 
const int N = 10; // 定义一个足够大的常量N作为数组大小
int a[N];

int main() {
    int n = 4;
    string s = "2022";
    for (int i = 1; i <= 4; ++i) {
        a[i] = s[i - 1] - '0';
    }//a[1]=2, a[2]=0, a[3]=2, a[4]=2
    long long x = 0;
    for (int i = 1; i <= n; ++i) {
        x = x * 9 + a[i];
    }
    cout << x << '\n';
    return 0;
}

