#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<long long> s(n+1,0);
	for(int i=1;i<=n;++i){
		int x;cin>>x;
		s[i]=s[i-1]+x;
	}
	
	int m;cin>>m;
	while(m--){
		int l,r;cin>>l>>r;
		cout<<s[r]-s[l-1]<<'\n';
	}
	return 0;
} 
