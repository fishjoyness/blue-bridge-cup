#include <bits/stdc++.h>
using namespace std;
int main(){
	string str={"hello,world"};
	int length=str.length();
	size_t pos=str.find("hello");
	if (pos!=std::npos){
		cout<<pos<<'\n';
	}
	else{
		cout<<"ц╩спур╣╫"<<'\n'; 
	}
	return 0;
} 
