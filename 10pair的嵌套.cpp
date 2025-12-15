#include <bits/stdc++.h>
using namespace std; 
int main() {
    pair<int, pair<int, int>> p2(3, make_pair(4, 5));
    //make_pair快速创建一个 std::pair 对象
    pair<pair<int, int>, pair<int, int>> p3(
        make_pair(6, 7), 
        make_pair(8, 9)
    );
    // 访问嵌套元素时，需要连续使用 .first 和 .second
    std::cout << "p2: " << p2.first << ", " << p2.second.first << ", " << p2.second.second << std::endl;
    std::cout << "p3: " << p3.first.first << ", " << p3.first.second << ", " 
              << p3.second.first << ", " << p3.second.second << std::endl;
    return 0;
}
