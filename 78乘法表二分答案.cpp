#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k;

// 计算小于等于 mid 的元素个数
// 对于第 i 行，这一行的数是 i*1, i*2, ..., i*m
// 要找 i*j <= mid，即 j <= mid/i
// 所以这一行满足条件的个数就是 min(m, mid/i)
ll rnk(ll mid)
{
    ll res = 0;
    for(ll i = 1; i <= n; ++i)
    {
        res += min(m, mid / i);
    }
    return res;
}

int main()
{
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 输入
    cin >> n >> m >> k;
    
    // 二分范围
    // 乘法表的最小值是 1，最大值是 n*m
    // 题目中 n, m 最大 5e5，所以 n*m 最大 2.5e11
    // 为了安全起见，右边界可以开得更大一点，比如 1e12 或 1e14
    ll l = 0, r = 1e12; 

    // 二分循环
    // 这里的写法是 l+1 < r，循环结束时 r 就是答案
    while(l + 1 < r)
    {
        ll mid = (l + r) >> 1;
        
        // rnk(mid) 表示矩阵中小于等于 mid 的元素个数
        // 如果个数 >= k，说明第 k 小的元素在 mid 或 mid 的左边
        if(rnk(mid) >= k)
            r = mid;
        else 
            l = mid;
    }

    // 输出结果
    cout << r << endl;

    return 0;
}

