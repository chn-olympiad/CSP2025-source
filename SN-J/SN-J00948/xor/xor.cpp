//SN-J00948 蔡铭禹 西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],sc[1100010],xz[500010],dp[500010];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	sc[0]=-1;
	int tp;
	for(int i=1;i<=n;i++)
	{
		tp=a[i]^k;
		if(sc[tp]==-1)
		{
			xz[i]=0;
		}
		else if(sc[tp]==0)
		{
			xz[i]=-1;
		}
		else
		{
			xz[i]=sc[tp];
		}
		sc[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		tp=xz[i];
		dp[i]=dp[i-1];
		if(xz[i]>(-1))
		{
			dp[i]=max(dp[i],1+dp[xz[i]]);
		}
	}
	cout<<dp[n];
	return 0;
}
