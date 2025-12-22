#include <bits/stdc++.h> 
using namespace std;

//map 的核心作用是存储“键-值”对（Key-Value Pair）
//键：就像字典里的“单词”，是唯一的，用来查找。
//值：就像字典里的“解释”，是和这个“单词”关联的信息。
//map 最大的特点是，你可以通过“键”来快速地找到、
//修改或删除对应的“值”，效率非常高

//如装了这些{ 5: 1, 2: 1 }

int main() {
    // 提高cin/cout效率，在数据量大时很有用
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m; // 读入矩阵的行数n和列数m

    map<int, int> mp; // 创建一个map，key是数字，value是该数字出现的次数

    // 矩阵总共有 n*m 个数，所以我们循环 n*m 次来读取所有元素
    for (int i = 1; i <= n * m; ++i) {
        int x;
        cin >> x; // 读入一个数字
        mp[x]++;  // 将这个数字在map中的计数器加1
    }

    // 遍历map，查找出现次数超过一半的数字
    for (const auto &pair : mp) {
    // 在这个循环里，变量 `pair` 就代表了 map 中的每一对“键值对”
    // 比如，当循环到 { 5: 3 } 这一对时，pair.first 就是 5，pair.second 就是 3

    if (2 * pair.second > n * m) {
        cout << pair.first << '\n'; // 输出这个数字
        break; // 找到后退出循环
    }
}
    

    return 0;
}

