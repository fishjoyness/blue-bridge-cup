#include <iostream>
#include <vector>
#include <algorithm> // for max

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int f0 = 0, f1 = 0;
        for (int x : nums) {
            int new_f = max(f1, f0 + x);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};

// 主函数用于测试
int main() {
    Solution sol;
    
    // 测试用例1
    vector<int> test1 = {1, 2, 3, 1};
    cout << "测试1结果: " << sol.rob(test1) << endl; // 应该输出 4
    
    // 测试用例2
    vector<int> test2 = {2, 7, 9, 3, 1};
    cout << "测试2结果: " << sol.rob(test2) << endl; // 应该输出 12
    
    // 测试用例3
    vector<int> test3 = {2, 1, 1, 2};
    cout << "测试3结果: " << sol.rob(test3) << endl; // 应该输出 4
    
    return 0;
}

