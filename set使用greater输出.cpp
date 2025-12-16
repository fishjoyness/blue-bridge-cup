#include <bits/stdc++.h> 
using namespace std;

int main() {
    // 在 set 的第二个模板参数中指定比较规则为 greater<int>
    // greater<int> 的逻辑是“大于”，所以会形成从大到小的顺序
    set<int, greater<int>> mySet;

    // 插入元素
    mySet.insert(25);
    mySet.insert(17);
    mySet.insert(39);
    mySet.insert(42);

    // 使用范围for循环遍历并输出
    cout << "使用 greater<int> 的输出: ";
    for (const auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

