#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> col_set;
        unordered_set<int> add_set;
        unordered_set<int> sub_set;
        
        dfs(res, col_set, add_set, sub_set, n, 0, board);
        return res;
    }
    
private:
    void dfs(vector<vector<string>>& res, unordered_set<int>& col_set, 
             unordered_set<int>& add_set, unordered_set<int>& sub_set, 
             int n, int row, vector<string>& board) {
        
        if (row == n) {
            res.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (col_set.count(col) || add_set.count(row + col) || sub_set.count(row - col)) {
                continue;
            }
            
            col_set.emplace(col);
            add_set.emplace(row + col);
            sub_set.emplace(row - col);
            board[row][col] = 'Q';
            
            dfs(res, col_set, add_set, sub_set, n, row + 1, board);
            
            col_set.erase(col);
            add_set.erase(row + col);
            sub_set.erase(row - col);
            board[row][col] = '.';
        }
    }
};

// 主函数，用于测试
int main() {
    Solution sol;
    int n;
    cout << "请输入N皇后问题的N值: ";
    cin >> n;
    
    vector<vector<string>> solutions = sol.solveNQueens(n);
    
    cout << "找到 " << solutions.size() << " 种解法:" << endl;
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    return 0;
}

