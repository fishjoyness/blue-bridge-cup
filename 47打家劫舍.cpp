#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> memo(n, -1); // -1 表示没有计算过

        // 定义递归函数
        // dfs(i) 表示从 nums[0] 到 nums[i] 最多能偷多少
        function<int(int)> dfs = [&](int i) -> int {
            if (i < 0) { // 递归边界（没有房子）
                return 0;
            }
            if (memo[i] != -1) { // 之前计算过
                return memo[i];
            }
            return memo[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]);
        };

        return dfs(n - 1); // 从最后一个房子开始思考
    }
};

// 主函数用于测试
int main() {
    Solution sol;
    vector<int> test1 = {1, 2, 3, 1};
    vector<int> test2 = {2, 7, 9, 3, 1};
    
    cout << "测试1结果: " << sol.rob(test1) << endl; // 应该输出 4
    cout << "测试2结果: " << sol.rob(test2) << endl; // 应该输出 12
    
    return 0;
}

