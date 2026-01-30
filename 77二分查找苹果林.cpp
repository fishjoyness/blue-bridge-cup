#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 定义一个足够大的数组，题目中 N 最大 1e5
const int N = 1e5 + 5;

// 全局变量存储坐标和数量
int x[N]; 
int n, m;

// check 函数：检查在最近距离为 mid 的情况下，能否种下至少 m 棵树
int check(int mid)
{
    int cnt = 1;             // 计数器，贪心策略：第一个点 x[1] 肯定种一棵
    int last_pos = x[1];     // 记录上一棵树种下的位置

    // 从第二个位置开始扫描
    for(int i = 2; i <= n; ++i)
    {
        // 如果当前点 x[i] 和上一棵树 last_pos 的距离 大于等于 mid
        if(x[i] - last_pos >= mid)
        {
            cnt++;           // 满足条件，在这里种一棵
            last_pos = x[i]; // 更新上一棵树的位置为当前点
            
            // 小优化：如果已经能种下 m 棵了，直接返回 1 (true)，不用继续往后扫了
            if(cnt >= m) return 1; 
        }
    }

    // 扫完了如果还不够 m 棵，说明 mid 太大了，种不下
    if(cnt >= m) return 1;
    else return 0;
}

int main()
{
    // 优化输入输出效率，竞赛常用
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 输入
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        cin >> x[i];
    
    // 1. 必须排序！
    // 贪心算法依赖于“从左到右”依次选择，所以坐标必须有序
    sort(x + 1, x + 1 + n);

    // 2. 确定二分范围
    // 左边界 l=0：最近距离可以是 0
    // 右边界 r=x[n]-x[1]：最大距离不超过总跨度，但为了保险直接开到题目最大坐标 1e9+5
    int l = 0, r = 1e9 + 5; 

    // 3. 二分循环
    // 这里的写法是 l+1 < r，循环结束时 l 就是最大满足条件的值
    while(l + 1 < r)
    {
        int mid = (l + r) / 2;
        
        // 如果 check(mid) 成立 (返回 >= 1)，说明能放下 m 棵树
        // 这个距离也许还可以更大，所以我们抛弃左半边，去右半区找更优解
        if(check(mid)) 
            l = mid; // 更新左边界为 mid
        else 
            r = mid; // 否则距离太大了，连 m 棵都放不下，抛弃右半边，去左半区找更小的
    }

    // 4. 输出
    // 循环结束时，l 保存的就是满足 check(mid) 为 true 的最大值
    cout << l << endl;

    return 0;
}

