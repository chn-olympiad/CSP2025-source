#include<bits/stdc++.h>
#define LL long long
#define Fcin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const LL Mod=998244353;
LL a[5050],n,sum,ans,mx=-1;
bool vis[5050];
void dfs(LL step,LL cnt,LL s)
{
	if(!cnt)
	{
		if((a[step-1]<<1)<s) ans=(ans+1)%Mod;
		return;
	}
	if(step>n) return;
	dfs(step+1,cnt-1,s+a[step]);
	dfs(step+1,cnt,s);
}
int main()
{
 	Fcin;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;++i) cin>>a[i],mx=max(mx,a[i]);
	if(mx==1)
	{
		LL t=6,bt=(n*(n-1)%Mod*(n-2)%Mod)%Mod;
		ans=bt/t;
		for(LL i=4;i<=n;++i)
		{
			t=(t*i)%Mod;
			bt=(bt*(n-i+1)%Mod)%Mod;
			ans+=bt/t;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(LL i=3;i<=n;++i)
	{
		memset(vis,0,sizeof vis);
		dfs(1,i,0);
	}
	cout<<ans;
	return 0;
}

