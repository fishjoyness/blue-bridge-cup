// x & (x - 1)：最低位的1变0。常用于统计二进制中 1 的个数（即 __builtin_popcount(x) 的底层原理）。
//例子：x = 1001000，x-1 = 1000111，相与得 1000000。
//x | y：集合并集。
//x & y：集合交集。
//x ^ y：集合对称差（只在其中一个集合出现的状态）。
//~x：取反。
//(x >> k) & 1：取出第k位。
//x & (-x)：取出最低位的1（lowbit操作，用于树状数组）
//二进制中1的数量 
#include <bits/stdc++.h>
using namespace std;

const int N = 1050;

int main() {
    int x;
    cin >> x;
    int ans = 0;
    
    while(x) {
        if(x & 1) {
            ans++;
        }
        x >>= 1;
    }
    
    cout << ans << endl;
    return 0;
}

