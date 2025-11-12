#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define int long long
using namespace std;
const int mod=998244353;
int n,i,x,y,ans,mi,zma,a[5010],sum;
void dfs(int t,int ma,int s){
	if(ma>mi)return;
	if(t==n+1){
		if(s>ma*2)ans=(ans+1)%mod;
		return ;
	}
	dfs(t+1,max(ma,a[t]),s+a[t]);
	dfs(t+1,ma,s);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;mi=2e9;
	for(i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	if(n>=30){
		x=n*(n-1)/2;
		for(i=3;i<=n;i++)
			x=x*(n-i+1)/i%mod,ans=(ans+x)%mod;
		return cout<<ans,0;
	}
	for(i=1;i<=n;i++)
		if(sum<=2*a[i])mi=min(mi,a[i]);
	dfs(1,0,0);
	cout<<ans;
}
