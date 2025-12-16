#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> myMultiset;
//set不允许重复的元素，而multiset用红黑树 
    myMultiset.insert(5);
    myMultiset.insert(2);
    myMultiset.insert(8);
    myMultiset.insert(2); 

    cout << "Initial Multiset elements: ";
    for (const auto& elem : myMultiset) {
        cout << elem << " ";
    }
    cout << endl; // 输出: 2 2 5 8


    int searchValue = 2;
    // equal_range 返回一个 pair，包含两个迭代器
    // first 指向第一个等于 searchValue 的元素
    // second 指向最后一个等于 searchValue 的元素的下一个位置
    auto range = myMultiset.equal_range(searchValue);
// 功能是在 myMultiset 中查找所有值等于 searchValue（也就是 2）的元素
//返回一个范围 
    if (range.first != range.second) {
// [range.first, range.second) 的区间就包含了所有的 2
//如果没找到：equal_range 会返回一个空范围
        cout << searchValue << " found in the multiset." << endl;
    } else {
        cout << searchValue << " not found in the multiset." << endl;
    }

    // --- 移除元素 ---
    int removeValue = 2;
    // erase(value) 会移除所有等于 value 的元素
    myMultiset.erase(removeValue);

    // --- 再次遍历多重集合 ---
    cout << "Multiset elements after removing " << removeValue << ": ";
    for (const auto& elem : myMultiset) {
        cout << elem << " ";
    }
    cout << endl; // 输出: 5 8

    // --- 清空多重集合 ---
    myMultiset.clear();

    // --- 检查多重集合是否为空 ---
    if (myMultiset.empty()) {
        cout << "Multiset is now empty." << endl;
    } else {
        cout << "Multiset is not empty." << endl;
    }

    return 0;
}

