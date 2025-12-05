#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//1.记得函数的重载，必须函数名以及函数数据类型都一样才可以 
//2.string里面运用
string str1="hello,world";
string str2=str1.substr(0,5);//第一个为起始位置，第二个是长度 

const char*char1="hello";//指向常量字符的指针 ，表示只读 
string str3(char1);// 从C语言到c++的转化 
 
char buf[100];
scanf("%s",buf);
string str(buf);
printf("输出str=%s\n",str.c_str());//转化之后才可以输出 

string str01="hello,world";
string str02="c++";
int length=str01.length();
string str03=str01.append(",").append(str02);
size_t pos=str.find("world");//返回find size_t ，找不到则返回最大值 
if(pos!=string::npos){//后面那个指最大值 
	cout<<"位置是"<<pos<<endl; 
}
else{
	cout<<"不存在"<<endl; 
}
//str.replace(7,5,"universe");//起始的位置，长度，替换的内容 

//比较字符串  int result=str1.compare(str2); str1和str2比较大小 

return 0;
 
 
} 
int factorial(int n){
	if (n<=1)
		return 1;
	return n*factorial(n-1);
} 
