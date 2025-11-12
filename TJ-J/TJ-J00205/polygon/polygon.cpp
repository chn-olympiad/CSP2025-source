#include"bits/stdc++.h"
using namespace std;
long long n,a[5010],ans=0;
void dfs(int s,int j,int k,int l){
	if(s==k){
		if(l<=a[j-1]*2) return;
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=j;i<n;i++){
		dfs(s+1,i+1,k,l+a[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=3;i<=n;i++) dfs(0,0,i,0);
	cout<<ans;
	return 0;
}
