#include <bits/stdc++.h> 
using namespace std;
int main() {
    vector<int> vec = {2, 1, 3, 2, 4, 1, 5, 4};
    // 2. 对 vector 进行排序，为去重做准备
    sort(vec.begin(), vec.end());

    // 3. 使用 unique 将重复元素移到末尾，并返回新逻辑终点的迭代器
    auto last = unique(vec.begin(), vec.end());
//last 就像一个分界线标记，它指向垃圾部分的第一个元素
    // 4. 从 vector 中永久地删除一个或多个元素，并自动调整 vector 的大小
    vec.erase(last, vec.end());

    // 5. 使用范围for循环遍历并打印去重后的结果
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout <<endl; // 打印一个换行符，让输出更美观

    return 0;
}

