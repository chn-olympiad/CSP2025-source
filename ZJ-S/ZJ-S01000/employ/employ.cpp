#include<bits/stdc++.h>//368346,ciallo
using namespace std;
#define ll long long
#define fre(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout)
const ll mod=998244353;
const ll maxn=509;
ll n,m;
string s;
ll p[maxn],h[maxn];
ll cnt=0;
ll vis[maxn];
ll dfs(ll x,ll y)
{
	if(x==cnt+1)
	{
		if(y>=m)
		{	
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(y+(n-h[x]+1)<m)
	{
		return 0;
	}
	ll d=h[x]-1-y;
	
	ll num=0,ans=0,las=0;
	for(ll i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			continue;
		}
		if(p[i]<=d)
		{
			num++;
			las=i;
		}
		else
		{
			vis[i]=1;
			ans=(ans+dfs(x+1,y+1))%mod;
			vis[i]=0;
		}
	}
	vis[las]=1;
	ans=(ans+num*dfs(x+1,y));
	vis[las]=0;
	return ans;
}
int main()
{
	fre(employ);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(ll i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			cnt++;
			h[cnt]=i;
		}
	}
	ll po=1;
	for(ll i=1;i<=n-cnt;i++)
	{
		po=po*i%mod;
	}
	for(ll j=1;j<=n;j++)
	{
		cin>>p[j];
	}
	sort(p+1,p+n+1);
	po=po*dfs(1,0)%mod;
	cout<<po;
	return 0;
}
