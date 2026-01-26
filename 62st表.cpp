#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
int a[N], st[N][21];

int getMax(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        st[i][0] = a[i];
    }
    
    // ST表预处理
    for(int j = 1; j <= 20; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(i + (1 << j) - 1 <= n) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    // 处理询问
    while(m--) {
        int l, r;
        cin >> l >> r;
        cout << getMax(l, r) << "\n";
    }
    
    return 0;
}

