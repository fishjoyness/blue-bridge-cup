#include <bits/stdc++.h> 
using namespace std;

int main() {
    int a[] = {1, 1, 2, 2, 3};

// 对数组进行去重，unique函数返回新逻辑序列的结尾指针
//unique(a, a + 5) 返回的指针，指向数组中第 3 个位置
// 用这个指针减去数组首地址，就得到了新序列的长度
    int n = unique(a, a + 5) - a;

// 使用普通for循环，遍历并打印数组中前n个元素
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    
    cout << endl; // 打印一个换行符，让输出格式更整洁

    return 0; // main 函数返回 0，表示程序正常结束
}

