#include <iostream>
#include <vector>
#include <algorithm> // sort函数所需的头文件
using namespace std;

// 自定义比较函数：降序排列
// 返回 true 表示 u 应该排在 v 前面
bool cmp(const int &u, const int &v) {
    return u > v; 
}

int main() {
    // 优化输入输出效率（蓝桥杯常用技巧）
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ==========================================
    // 用法1：对普通数组进行排序 (从下标1开始)
    // ==========================================
    int a[1000];
    int n;
    // 读取数组大小
    cin >> n;
    // 读取元素
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 对数组进行排序 (范围是 [a+1, a+n+1) )
    sort(a + 1, a + n + 1);
    // 输出
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // ==========================================
    // 用法2：对vector进行排序 (默认升序)
    // ==========================================
    vector<int> v = {5, 1, 3, 9, 11};
    // 对vector进行排序，使用迭代器 begin() 和 end()
    sort(v.begin(), v.end());
    // 输出
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // ==========================================
    // 用法3：自定义规则排序 (降序)
    // ==========================================
    // 重新初始化v以便演示
    v = {5, 1, 3, 9, 11};
    // 传入比较函数 cmp，实现降序
    sort(v.begin(), v.end(), cmp);
    // 输出
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

