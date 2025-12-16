#include <bits/stdc++.h>
using namespace std; 
int main() {
    vector<int> numbers = {1, 2, 3, 5, 8, 9}; 

    // 打印插入元素后的向量
    cout << "插入元素后的向量: ";
    for (const auto& number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    // 删除向量中的某个元素
    // numbers.begin() + 4 指向第5个元素，即数字 '8'
    numbers.erase(numbers.begin() + 4);

    // 打印删除元素后的向量
    cout << "删除元素后的向量: ";
    for (const auto& number : numbers) {
        cout << number << " ";
    }
   	cout << endl;

    // 获取向量的大小
    cout << "向量的大小: " << numbers.size() << endl;

    // 清空向量中的所有元素
    numbers.clear();

    // 检查向量是否为空 (第一次检查)
    if (numbers.empty()) {
        cout << "向量为空" << endl;
    } else {
        cout << "向量不为空" << endl;
    }


    return 0; 
}

