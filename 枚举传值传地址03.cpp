#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s="hello";
	for(int i=0;i<s.length();i++)
		cout<<s[i]<<endl;
	
	for(auto i:s){//遍历s这个容器里面的所有元素 ，传值 
		cout<<i;
		i='a';
	}
	cout<<endl;
	cout<<s<<endl;
	for (auto &i:s){//传地址 
		cout<<i;
		i='a';
	} 
	cout<<endl;
	cout<<s<<endl;
	
	string s1;
	getline(cin,s1);//读取空格，直到回车 
	reverse(s1.begin(),s1.end());//反转这个s1里面所有字符 
	cout<<s1<<endl;
	return 0;
} 
