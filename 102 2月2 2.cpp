#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
vector <int> L;
int getidx (int x){
	return lower_bound(L.begin(),L.end(),x)-L.begin();
}
int a[N];
int main(){
	int n;cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)L.push_back(a[i]);
	L.erase(unique(L.begin(),L.end()),L.end());
	return 0; 
}
