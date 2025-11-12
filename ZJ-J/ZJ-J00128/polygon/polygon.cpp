#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],mod=998244353,ans=0,mx=0;
void dfs(long long st,long long tot){
	if(tot>2*a[st-1]) ans=(ans+1)%mod;
	for(long long i=st;i<=n;i++){
		dfs(i+1,tot+a[i]);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		cout<<(long long)(n-1)*(n-2)/2%mod;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			dfs(j+1,a[i]+a[j]);
		}
	}
	cout<<ans;
	return 0;
}
