#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],sum,dp[500001],m;
struct node
{
	int l,r;
};
node v[3000001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		sum=a[i];
		if(sum==k) v[++m]={i,i};
		for(int j=i+1;j<=n;j++)
		{
			sum^=a[j];
			if(sum==k) v[++m]={i,j};
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		dp[i]=dp[i-1];
		for(int j=1;j<=m;j++)
		{
			if(i>=v[j].r) dp[i]=max(dp[i],dp[v[j].l-1]+1);
		}		
	}
	cout<<dp[n];
	return 0;
}