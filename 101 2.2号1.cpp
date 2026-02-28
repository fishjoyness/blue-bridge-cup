#include <bits/stdc++.h>
using namespace std;
int main(){
	vector <int> nums={1,2,3};
	for (auto num:nums){
		cout<<num;
	}
		cout<<'\n';
	while(next_permutation(nums.begin(),nums.end())){
		for (auto num:nums){
			cout <<num;
		}
		cout<<'\n';
	}
	return 0;
} 
