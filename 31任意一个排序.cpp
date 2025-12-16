#include <bits/stdc++.h> 
using namespace std;

int main() {
    int a[10];
    // 初始化为一个任意的排列
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 1;

    bool tag = true;
    int count = 0;
    while (tag) {
        // 打印当前排列
        for (int i = 1; i <= 4; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        count++;

        // 尝试生成下一个排列
        tag = next_permutation(a + 1, a + 1 + 4);
    }
    cout << "\nTotal permutations from this starting point: " << count << endl;

    return 0;
}

