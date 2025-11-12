//SN-J01084 menkeming xi'anfulunzhongxue
#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,maxn,a[5010],dp[50200][110],ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*2)%mod;
		ans-=(n*(n-1)/2)+n+1;
		cout<<(ans+mod)%mod;
		return 0;
	}
	for(int i=1;i<(1<<(n+1));i++)
	{
		int sum=0,maxx=0;
		for(int j=1;j<=n;j++)
			if((i>>(j-1))&1)
				sum+=a[j],maxx=max(maxx,a[j]);
		if(sum>2*maxx)
			ans++;
	}
	cout<<ans/2;
	return 0;
}
