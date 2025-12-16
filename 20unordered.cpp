#include <bits/stdc++.h> 
using namespace std;

int main() {
    // 创建一个 unordered_set，它存储整数
    unordered_set<int> myUnorderedSet;

    myUnorderedSet.insert(5);
    myUnorderedSet.insert(2);
    myUnorderedSet.insert(8);
    myUnorderedSet.insert(2); // 尝试插入重复元素，将被忽略

    // --- 遍历无序集合 ---
    cout << "Initial Unordered set elements: ";
    for (const auto& elem : myUnorderedSet) {
        cout << elem << " ";
    }
    cout << endl; // 输出顺序不确定，例如: 8 5 2

    // --- 查找元素 ---
    int searchValue = 5;
    // find() 函数返回一个迭代器，指向被查找的元素
    auto it = myUnorderedSet.find(searchValue);
//1.如果 searchValue（值为 5）在 myUnorderedSet 中存在，
//find 函数会返回一个迭代器，这个迭代器直接指向值为 5 的那个元素。
//2.如果 searchValue在 myUnorderedSet 中不存在，
//find 函数会返回一个特殊的迭代器，叫做 end()
//（指向容器中最后一个元素的下一个位置） 

//set的内部实现是红黑是，有序的
//unordered_set的内部实现是哈希表，无序的 


    if (it != myUnorderedSet.end()) {
        cout << searchValue << " found in the unordered set." << endl;
    } else {
        cout << searchValue << " not found in the unordered set." << endl;
    }

    // --- 移除元素 ---
    int removeValue = 2;
    // erase() 函数会移除所有值为 removeValue 的元素
    // 在 unordered_set 中，最多只会有一个，所以效果是移除那个唯一的 2
    myUnorderedSet.erase(removeValue);

    // --- 再次遍历无序集合 ---
    cout << "Unordered set elements after removing " << removeValue << ": ";
    for (const auto& elem : myUnorderedSet) {
        cout << elem << " ";
    }
    cout << endl; // 输出顺序不确定，例如: 8 5

    // --- 清空无序集合 ---
    myUnorderedSet.clear();

    // --- 检查无序集合是否为空 ---
    if (myUnorderedSet.empty()) {
        cout << "Unordered set is now empty." << endl;
    } else {
        cout << "Unordered set is not empty." << endl;
    }

    return 0;
}

