#include <bits/stdc++.h> 
using namespace std;
int main() {
    vector<pair<int, int>> vec;//动态数组里要存放的东西的类型
    vec.push_back(make_pair(3, 2));
    vec.push_back(make_pair(1, 4));
    vec.push_back(make_pair(2, 1));
    // 对 vector 进行排序
    // std::pair 默认的排序规则是：先比较 first，如果 first 相等，再比较 second
    sort(vec.begin(), vec.end());
    // 使用范围for循环遍历并打印结果
    for (const auto& p : vec) {
        std::cout << p.first << ", " << p.second << std::endl;
    }
    return 0;
}
