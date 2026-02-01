#include <bits/stdc++.h> 
using namespace std;

int N, K;

// path 改成 vector 类型，这就是一个“智能数组”
vector<int> path; 

// u: 当前正在考虑第几个数
// cnt: 当前已经选了几个数 (其实这里也可以不用 cnt，直接用 path.size()，但为了让你对比方便，先保留着)
void dfs(int u, int cnt) {
    // 1. 剪枝：如果已经选够了 K 个，就输出
    if (cnt == K) {
        // vector 可以直接用范围 for 循环遍历，非常清爽
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // 2. 边界条件：数都考虑完了，就返回
    if (u > N) {
        return;
    }

    // --- 核心分支 ---

    // 分支 1：我要选第 u 个数
    // vector 有个神奇的功能叫 push_back，意思是在袋子尾部塞进一个元素
    path.push_back(u); 
    dfs(u + 1, cnt + 1);
    
    // 【关键点】回溯现场！
    // 既然选了 u，递归回来后，如果不把这个 u 拿出来，它就会留在袋子里影响“不选”的那个分支
    // pop_back 就是把尾部最后一个元素扔掉
    path.pop_back(); 


    // 分支 2：我不选第 u 个数
    // 这里的 path 里干干净净，没有 u，所以直接往下走
    dfs(u + 1, cnt);
}

int main() {
    cin >> N >> K;
    dfs(1, 0);
    return 0;
}

