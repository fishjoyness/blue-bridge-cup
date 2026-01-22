//区间或 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], prefix[35][N];

int main()
{
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    // 为每个二进制位建立前缀和
    for(int w = 0; w <= 30; ++w)
    {
        for(int i = 1; i <= n; ++i)
            prefix[w][i] = prefix[w][i-1] + (a[i] >> w & 1);
    }
    
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        
        for(int w = 0; w <= 30; ++w)
        {
            // 检查第w位在区间[l,r]中是否有1
            if(prefix[w][r] - prefix[w][l-1] > 0)
                ans += (1 << w);  // 如果有1，则这一位贡献2^w
        }
        
        cout << ans << endl;
    }
    
    return 0;
}

