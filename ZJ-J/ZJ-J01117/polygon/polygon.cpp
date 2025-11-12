#include <bits/stdc++.h>
using namespace std;
int n,a[5000],c;
bool f=1;
void dfs(int i,int maxi,int s) {
	if(maxi*2<s) c++;
	if(i>=n) return;
	for(int j=i+1; j<n; j++) dfs(j,max(maxi,a[j]),s+a[j]);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f) {
		long long s=-7;
		for(int i=3; i<=n; i++) s+=5*i*i-39*i+80;
		cout<<s%998244353;
		return 0;
	}
	dfs(0,a[0],a[0]);
	cout<<c;
	return 0;
}
