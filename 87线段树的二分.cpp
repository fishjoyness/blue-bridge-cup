#include <bits/stdc++.h>
using namespace std;

// 定义常量，线段树节点数量通常是数据量的4倍以确保覆盖
const int N = 2e5 + 9;

// 定义结构体存储查询信息，v代表身高，a代表人数
struct Q {
    int v, a;
} q[N];

// 用于离散化的数组，存储所有出现过的不同身高值
vector<int> X;

// 离散化函数：将具体的身高值映射为线段树中的索引(1, 2, 3...)
int getIdx(int x) {
    // lower_bound返回第一个不小于x的迭代器
    // 减去begin()得到下标，再加1是因为线段树通常从1开始编号
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}

// 反离散化函数：根据线段树索引还原回原始的身高值
int getVal(int idx) {
    // 线段树索引是从1开始的，而vector下标是从0开始的，所以要减1
    return X[idx - 1];
}

// 线段树数组，t[i]存储该区间内学生的人数总和
long long t[N * 4];

// pushup函数：线段树的核心操作之一
// 作用：当前节点的值等于其左子节点和右子节点值的和
// 这样可以保证t[o]始终维护的是该区间内学生的总人数
void pushup(int o) {
    t[o] = t[o << 1] + t[o << 1 | 1];
}

// update函数：更新线段树
// 参数 a: 身高的离散化索引，V: 增加的人数，s/e: 当前处理的区间范围，o: 当前节点编号
void update(int a, long long V, int s, int e, int o) {
    // 递归终止条件：如果当前区间长度为1（即到达了叶子节点）
    if (s == e) {
        // 增加该身高对应的人数
        t[o] += V;
        return;
    }
    
    // 计算中点，将当前区间分为左右两半
    int mid = (s + e) >> 1;
    
    // 如果要更新的身高索引在左半边，递归更新左子树
    if (a <= mid) update(a, V, s, mid, o << 1);
    // 否则递归更新右子树
    if (a > mid) update(a, V, mid + 1, e, o << 1 | 1);
    
    // 子节点更新完后，重新计算当前节点的值（回溯过程）
    pushup(o);
}

// query函数：线段树上二分查找第k小
// 目的：找到排序后第k个位置对应的身高索引
// 参数 k: 目标排名，s/e: 当前区间，o: 当前节点
int query(long long k, int s = 1, int e = X.size(), int o = 1) {
    // 递归终止条件：如果区间长度为1，说明找到了第k小的位置
    if (s == e) return s;
    int mid = (s + e) >> 1; 
    // 获取左子节点的值，即左区间内的人数总和
    long long left_sum = t[o << 1];
    
    // 判断逻辑：
    // 如果左边的人数已经大于等于k，说明第k个人肯定在左边
    if (left_sum >= k) return query(k, s, mid, o << 1);
    // 如果左边人数不够k，说明第k个人在右边
    // 此时我们需要在右边找第 (k - left_sum) 小
    return query(k - left_sum, mid + 1, e, o << 1 | 1);
}

int main() {
    // 优化输入输出效率，在数据量大时非常有必要
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    // 循环读取每一条信息
    for (int i = 1; i <= n; ++i) {
        cin >> q[i].v >> q[i].a;
        // 将所有出现的身高值存入X数组，为离散化做准备
        X.push_back(q[i].v);
    }
    
    // --- 离散化预处理开始 ---
    // 1. 排序：将身高从小到大排列
    sort(X.begin(), X.end());
    // 2. 去重：去除重复的身高值，因为线段树只需要记录身高的种类
    X.erase(unique(X.begin(), X.end()), X.end());
    // --- 离散化预处理结束 ---
    
    long long sum = 0; // sum用来记录当前体育馆内的总人数
    
    // 再次循环，处理每一次进入
    for (int i = 1; i <= n; ++i) {
        // 1. 更新线段树：根据身高离散化后的索引，增加对应的人数
        update(getIdx(q[i].v), q[i].a, 1, X.size(), 1);
        
        // 2. 更新总人数
        sum += q[i].a;
        
        // 3. 计算中位数的位置
        // 如果总人数是奇数，如5，(5+1)/2 = 3，取第3个
        // 如果总人数是偶数，如4，(4+1)/2 = 2，取第2个（即较矮的那个），符合题意
        long long k = (sum + 1) / 2;
        
        // 4. 查询：在线段树上找到第k小的位置（得到的是离散化后的索引）
        int idx = query(k);
        
        // 5. 输出：将索引还原为原始身高并输出
        cout << getVal(idx) << '\n';
    }
    
    return 0;
}

