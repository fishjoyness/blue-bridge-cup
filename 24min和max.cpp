#include <bits/stdc++.h> 
using namespace std;

int main() {
    vector<int> v = {5, 1, 7, 3, 10, 18, 9};

    cout << "原始数组: ";
    for (auto& i : v) {
        cout << i << " ";
    }
//min_element(st,ed)返回这个范围里面那个最小的那个值的地址 
    cout << "\n\n";
// *表示解引用，通过地址得到值 
	cout << "数组中的最大元素是: " << *max_element(v.begin(), v.end()) << '\n';

//进行部分排序，传入参数为三个地址或迭代器
//其中第二个参数位置的元素将处于正确位置，其他位置元素的顺序可能是任意的，
//但前面的都比它小，后面的都比它大。时间复杂度O(n)。 
    nth_element(v.begin(), v.begin() + 3, v.end());

    cout << "执行 nth_element(v.begin(), v.begin() + 3, v.end()) 后:\n";
    // 遍历并输出结果
    for (auto& i : v) {
        cout << i << " ";
    }
    cout << "\n\n";

    // 验证一下 v[3] 位置的元素
    cout << "现在，v[3] 位置的元素是: " << v[3] << endl;
    cout << "它正好是数组中第4小的元素（注意：左右两边的元素不一定有序）！" << endl;

    return 0;
}

