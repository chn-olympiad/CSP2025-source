#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
bool mark=true;
ll n,s[5005],ans=0,shu[5005];
void dfs(ll x)
{
	if(x>n)
	{
		ll len=0;
		for(ll i=1;i<=n;i++) if(shu[i]==1) len++;
		if(len>=3) 
		{
			ll sum=0,maxn=-1,s2[5005];string ss;
			for(ll i=1;i<=n;i++) s2[i]=s[i]*shu[i];
			for(ll i=1;i<=n;i++)
			{
				sum+=s2[i];
				maxn=max(maxn,s2[i]);
			}
			if(sum<=maxn*2) return;
			ans++;
			return;
		}
		else return;
	}
	for(ll i=0;i<=1;i++)
	{
		shu[x]=i;
		dfs(x+1);
		shu[x]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) 
	{
		scanf("%lld",&s[i]);
		if(s[i]!=1) mark=false; 
	}
	sort(s+1,s+n+1);
	if(n<3) {printf("0");return 0;}
	if(n==3 && s[1]+s[2]>s[3]) {printf("1");return 0;}
	if(mark) {printf("%lld",(n-3+1)%mod);return 0;}
	dfs(1);ans%=mod;
	printf("%lld",ans);
	return 0;
}
