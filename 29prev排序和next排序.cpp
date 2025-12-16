#include <bits/stdc++.h>
using namespace std;

int main() {
    // --- next_permutation函数 示例 ---
    vector<int> nums = {1, 2, 3};

    cout << "Initial permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // 循环生成并打印所有后续排列
//next_permutation函数用于生成当前序列的下一个排列。
//它按照字典座对序列进行重新排列，
//如果存在下一个排列，则将当前序列更改为下一个排列，并返回true;
//如果当前序列已经是最后一个排列，则将序列更改为第一个排列，并返回 false。 
    while (next_permutation(nums.begin(), nums.end())) {
        cout << "Next permutation:   ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "No more permutations." << endl << endl;


    // --- prev_permutation 示例 ---
    vector<int> nums2 = {3, 2, 1};
    cout << "--- prev_permutation Example ---" << endl;
    cout << "Initial permutation: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    // 循环生成并打印所有前置排列
    while (prev_permutation(nums2.begin(), nums2.end())) {
        cout << "Previous permutation: ";
        for (int num : nums2) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "No more permutations." << endl;

    return 0;
}

