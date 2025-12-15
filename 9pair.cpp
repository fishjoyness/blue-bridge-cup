#include <bits/stdc++.h>
using namespace std; 
int main() {
    pair<int, double> p1(1, 3.14);
    pair<char, string> p2('a', "hello");
    // 使用 .first 访问第一个元素，.second 访问第二个元素
    cout << "Pair 1: " << p1.first << ", " << p1.second << endl;
    cout << "Pair 2: " << p2.first << ", " << p2.second << endl;
    return 0;
}
