#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=1002;
int n,i,ma,ans,a[N];
void dfs(int t,int s,int ma){
	if(t==n+1){
		if(s>ma*2) ans++,ans=ans%mod;
		return ;
	}
	dfs(t+1,s,ma);
	ma=max(ma,a[t]);
	dfs(t+1,s+a[t],ma);
}
int C(int x,int y){
	y=min(y,x-y);
	int s=1,s2=1;
	for(int i=x;i>=(x-y+1);i--) s=s*i,s=s%mod;
	for(int i=2;i<=y;i++) s2=s2*i,s2=s2%mod;
	return (s+mod)/s2;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i],ma=max(ma,a[i]);
	if(ma>1&&n<=20){
		dfs(1,0,0);
		cout<<ans%mod;
	}
	else{
		for(i=3;i<=n;i++) ans=ans+C(n,i),ans=ans%mod;
		cout<<ans%mod;
	}
	return 0;
}
