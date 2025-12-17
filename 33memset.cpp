#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[5];
    memset(a, 0, sizeof a);
//第一个参数是指向设置值的内存块的指针，要设置的值，要设置的字节数 
    for(int i=0;i<5;++i)cout << a[i] << '\n';
    return 0;
}
//unique是一个去除相邻重复元素的函数 
//unique将（first，last）范围里面的相邻重复的元素去除 
