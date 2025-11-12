// xt66666
// TYZ
// IGVA
//%%%qzr&jmc&wnn&qjy&lzh&wsk&qyx&zyr
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,a[5010];
bool f[5010];
ll ans=0;
ll mod=998244353;
void dfs(ll x)
{
	if(x==n+1)
	{
		ll mx=0,s=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i])
			{
				num++;
				s+=a[i];			
				mx=max(a[i],mx);
			}
		}
		if(num<3)
		{
			return ;
		}
		if(mx*2<s)
		{
			ans++;
			
		}
		ans%=mod;
		return ;
	}
	f[x]=0;
	dfs(x+1);
	f[x]=1;
	dfs(x+1);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll mxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mxx=max(mxx,a[i]);
	}
	if(mxx<=1)
	{
		ll ret=1;
		for(int i=1;i<=n;i++)
		{
			ret*=2;
			ret%=mod;
		}
		ret-=(1+n+n*(n-1)/2);
		ret+=mod*10;
		ret%=mod;
		ret+=mod*10;
		ret%=mod;
		cout<<ret;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

