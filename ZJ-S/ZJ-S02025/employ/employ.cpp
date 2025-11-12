#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p=998244353;
ll n,m,ans=0,A=1;
ll c[510],vis[510],v[510];
//int dp[510][510];
string f;
void dfs(ll k,ll s)
{
	if(k==n)
	{
		if(s>=m)
		{
//			for(int i=1;i<=n;i++)
//			{
//				cout<<c[v[i]]<<" ";
//			}
//			cout<<endl;
			ans=(ans+1)%p;
		}
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			v[k+1]=i;
			if(k-s<c[i]&&f[k]=='1')
			{
				dfs(k+1,s+1);
			}
			else
			{
				dfs(k+1,s);
			}
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ2.in","r",stdin);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>f;
	int z=0;
	for(ll i=1;i<=n;i++)
	{
		if(!f[i-1])
		{
			A=0;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			z++;
		}
	}
	if(n<=18)
	{
		dfs(0,0);
		cout<<ans;
	}
	else if(A)
	{
		if(n-z<m)
		{
			cout<<0;
			return 0;
		}
		ans=1;
		for(ll i=1;i<=n;i++)
		{
			ans=ans*i%p;
			cout<<ans<<endl;
		}
		cout<<ans;
	}
	else if(m==1)
	{
		ans=0;
		ll x=-1,y=1;
		for(ll i=0;i<f.size();i++)
		{
			if(f[i]=='1')
			{
				x=i;
				break;
			}
		}
		for(ll i=1;i<n;i++)
		{
			y=y*i%p;
		}
		for(ll i=1;i<=n;i++)
		{
			if(x<c[i])
			{
				ans=(ans+y)%p;
			}
		}
		cout<<ans;
	}
	else if(m==n)
	{
		cout<<0;
	}
	return 0;
}
