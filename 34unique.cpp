#include <bits/stdc++.h> 
using namespace std;
int main() {
	vector<int> vec = {1, 1, 2, 2, 3, 3, 3, 4, 4, 5};

    // 调用unique，它会把重复的元素移到向量末尾，并返回一个指向新逻辑结尾的迭代器
    // 注意：此时向量的大小没有改变，但元素的顺序被重新排列了
    auto it = unique(vec.begin(), vec.end());

    // 删除从新逻辑结尾到向量实际结尾之间的所有元素
    // 这一步才会真正移除那些重复的元素，让向量的大小变小
    vec.erase(it, vec.end());

    // 使用范围 for 循环遍历并打印处理后的向量中的每个元素
    for (int num : vec) {
        std::cout << num << " "; // 打印数字和一个空格
    }
    
    std::cout << std::endl; // 打印一个换行符，让输出格式更整洁

    return 0; 
}

