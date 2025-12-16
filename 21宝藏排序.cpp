#include <bits/stdc++.h> 
using namespace std;

const int N = 1e6 + 9; // 定义一个足够大的常量，10的6次方+9
int a[N]; // 定义一个全局数组来存储宝藏的珍贵程度

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; // 宝藏的总数
    cin >> n;


    // 注意：这里从下标 1 开始读取，这是一种常见的竞赛编程习惯
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 核心排序步骤：使用 STL 的 sort 函数
    // a+1 是数组第一个元素的地址，a+1+n 是数组末尾的下一个位置的地址
    // sort 会对 [a+1, a+1+n) 这个区间内的元素进行排序
    sort(a + 1, a + 1 + n);

    // 循环输出排序后的结果
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " "; // 输出每个数字，并用空格隔开
    }
    cout << endl; // 最后输出一个换行符，让输出格式更美观

    return 0;
}

