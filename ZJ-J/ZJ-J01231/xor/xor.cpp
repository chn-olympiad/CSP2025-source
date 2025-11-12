#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll a[501010];
ll sum[501010];
ll dp[501010];
ll vis[501050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int f=0;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];	
		f+=(a[i]>1);
	}	
	if(f==0)
	{
		ll ans=0;
		if(k==0)
		{
			for(ll i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
				}
				else if(a[i-1]&&vis[i-1]==0)
				{
					ans++;
					vis[i]=1;
				}
				vis[i-1]=1;
			}
		}
		else
		{
			for(ll i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	sum[0]=0;
	for(ll i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]^a[i];
	}
	dp[0]=0;
	for(ll i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(ll j=0;j<i;j++)
		{
			if((sum[i]^sum[j])==k)
			{
				//cout<<i<<j<<'\n';
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}