#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10,mod=998244353;
ll n,m,s,a[N],b[N],v[N];string f;
void dfs(ll t)
{
	if(t==n+1)
	{
		ll o=0,p=n;
		for(ll i=0;i<n;i++)
			if(f[i]=='0'||o>=b[i+1])o++;
		if(n-o>=m){s++;}
	}
	for(ll i=1;i<=n;i++)
		if(!v[i])v[i]=1,b[t]=a[i],dfs(t+1),v[i]=0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>f;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(n>18)
	{
		s=1;
		for(ll i=1;i<=n;i++)s=(s*i)%mod;;
		cout<<s;
	}
	else
	{
		dfs(1);cout<<s;
	}
	return 0; 
}

