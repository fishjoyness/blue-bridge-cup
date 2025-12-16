#include <bits/stdc++.h> 
using namespace std;
int main() {
    vector<int> numbers;
    
    numbers.push_back(5);
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(5);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(9);
    numbers.push_back(8);

    // 打印
    cout << "原始向量中的元素: ";
    for (const auto& number : numbers) {
        cout << number << " ";
    }
    cout <<endl;

    sort(numbers.begin(), numbers.end());

    // 打印排序后的向量
    cout << "排序后的向量: ";
    for (const auto& number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    // 去除重复元素 (sort-unique-erase 的简洁写法)
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    // 打印去重后的向量
   cout << "去重后的向量: ";
    for (const auto& number : numbers) {
        cout << number << " ";
    }
    cout << std::endl;

    // 向向量中插入元素
    numbers.insert(numbers.begin() + 2, 3);

    // 打印插入后的向量
    cout << "插入元素后的向量: ";
    for (const auto& number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}

