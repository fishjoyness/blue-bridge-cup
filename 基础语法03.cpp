#include <bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=1e5+9;
const ll p = 1e9+7;//对于取模是负数，(ans % p + p) % p

ll fib(int n){
	if (n<=2)
		return 1;
	return (fib(n-1)+fib(n-2))%p;//防止数字过大,使结果在 [0, 1e9+6]
	
} 
//带备忘录的递归
ll dp[N];//全局数组，所有元素默认会被初始化为 0
ll fib1(int n){
	if (dp[n])return dp[n];
	if (n<=2)
		return 1;
	return dp[n]=(fib1(n-1)+fib1(n-2))%p;
} 

int main(){
	int n;cin>>n;
	cout<<fib1(n)<<'\n';//'\n' 只是换行，而 endl 是换行加刷新缓冲区，后者更慢
	return 0;
} 
