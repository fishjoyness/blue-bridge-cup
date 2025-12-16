#include <bits/stdc++.h> 
using namespace std;

int main() {
    int a[10]; 

    // 初始化数组为最小的排列 {1, 2, 3, 4}
    for (int i = 1; i <= 4; ++i) {
        a[i] = i;
    }
//先创建一个“最小”的排列
    bool tag = true;//tag作为一个开关 
    int count = 0;// 统计我们总共生成了多少个排列
    while (tag) {
        // 打印当前排列
        for (int i = 1; i <= 4; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        count++;

        // 尝试生成下一个排列
        // next_permutation 会修改数组，如果成功返回 true，否则返回 false
        tag = next_permutation(a + 1, a + 1 + 4);
    }
    cout << "\nTotal permutations: " << count << endl;

    return 0;
}

