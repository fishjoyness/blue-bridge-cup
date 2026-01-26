#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9;

int lowbit[N]; // lowbit[i]存储以i结尾、区间大小为Lowbit(i)的和
int a[N];     // a[i]存储第i个学生的魅力值
int n, m;

// lowbit运算，取x最低位的1和后面的0
int Lowbit(int x) {
    return x & (-x);
}

// 单点修改：将x累加到原数组的pos位置，并同步更新lowbit数组
void update(int pos, ll x) {
    a[pos] += x; // 原数组直接累加到pos位置
    for (int i = pos; i <= n; i = i + Lowbit(i)) { // lowbit数组从pos开始依次i+Lowbit(i)的位置
        lowbit[i] += x;
    }
}

// 用lowbit数组计算[1, k]的区间和
ll get_prefix(int k) {
    ll res = 0;
    for (int i = k; i > 0; i = i - Lowbit(i)) { // i从k开始依次累加i-Lowbit(i)的位置
        // 注意这里的退出条件是大于0而非大于等于0，因为0-Lowbit(0)=0，会无限死循环
        res += lowbit[i]; // 依次累加所有的i-Lowbit(i)的位置
    }
    return res;
}

// 获取Σa[left...right]
ll get_sum(int left, int right) {
    return get_prefix(right) - get_prefix(left - 1); // 求[1,right]-[1,left-1]
}

// 计算第i个学生的愉悦值
ll b(int i) {
    // 将题目中给出的愉悦值b的表达式进行化简合并即可
    // b(i) = (2i-n-1)a[i] - Σa[1...i-1] + Σa[i+1...n]
    return (2LL * i - n - 1) * a[i] - get_sum(1, i - 1) + get_sum(i + 1, n);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    // 输入n个学生的魅力值并同步插入lowbit数组
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x); // 将x累加到第i个位置，初始时均为0，累加等同于插入
    }
    
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) { // 修改第x个学生的魅力值为y
            ll x, y;
            cin >> x >> y;
            update(x, -a[x] + y); // 原数组的a[x]减去a[x]再加y，lowbit数组对应位置同理
        } else { // 查询第x个学生的愉悦值
            int x;
            cin >> x;
            cout << b(x) << endl;
        }
    }
    
    return 0;
}

