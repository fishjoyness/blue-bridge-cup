#include <bits/stdc++.h>
using namespace std;
const int N=20;
int a[N];//当前路径上的当前节点值
//递归的方式实现了DFS，通过构建一棵虚拟的数字树
int dfs(int dep){
	int res=1;//计算以当前节点为根的整棵子树一共有多少个节点
	for(int i=1;i<=a[dep-1]/2;++i){//a[dep - 1] 也就是父节点
		a[dep]=i;
		res+=dfs(dep+1); //dfs(3) 会返回 2
	}
	return res;
} 
int main(){
	int n;cin>>n;
	a[1]=n;
	cout<<dfs(2)<<'\n';//从深度 2 开始进行深度优先搜索
	return 0;
} 
