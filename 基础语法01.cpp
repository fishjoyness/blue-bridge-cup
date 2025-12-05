#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;//对于比较大的数组可以这么用常量 
typedef long long ll;
ll a[N];//存放长整数的数组 
int b[N];
int main(){
	cout<<"hello,world"<<endl;
	printf("hello,world");
	int x=3;
	double d=3.1415;
	char ch='a';//printf用%c 
	char s[]="hello";
	printf("%s",s);
	bool b=true;
	cout <<x<<endl;
	cout <<d<<endl;
	//对于小数
	printf("%.2lf",&d);//double 
	
	//输出所有的偶数
	int n=10;
	for (int i=1;i<=n;i++){
		if(i%2==0)
			cout<<i<<endl;
	} 
	//printf scanf效率高
	//cout cin 输入和输出的流
	char num[50]; 
	scanf("%[^\n]",num);//读取并匹配所有不是换行符 \n 的字符，直到遇到换行符为止
	printf("%s",num);
	
	double c,e;
	cin>>c>>e;
	cout<<fixed<<setprecision(3)<<c<<e<<endl; //保证三位小数
	
	char s1[10];
	cin>>s1;
	cout<<s1;//遇到空格会结束
	
	string s2;//自动管理内存 
	getline(cin,s2);//可以输入空格 
	cout<<s2;
	 
	return 0;

} 
