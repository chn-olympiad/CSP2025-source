#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n,i,m,mod,fll,ans,f[510],a[510],fl[510];
char s[510];
void dfs(int t,int s,int c){
	int i;
	if(n-t+1<m-s)return;
	if(t>n){
		if(s>=m)ans=(ans+1)%mod;
		return ;
	}
	for(i=1;i<=n;i++)
		if(!f[i]){
			f[i]=1;
			if(a[i]<=c)dfs(t+1,s,c+1);
			else if(fl[t]!=1)dfs(t+1,s,c+1);
			else dfs(t+1,s+1,c);
			f[i]=0;
		}
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>s+1;mod=998244353;
	for(i=1;i<=n;i++)
		if(s[i]=='1')fl[i]=1;
		else fll=1;
	for(i=1;i<=n;i++)cin>>a[i];
	if(fll==0){
		ans=1;
		for(i=1;i<=n;i++)ans=ans*i%mod;
	}
	else dfs(1,0,0);
	cout<<ans;
}