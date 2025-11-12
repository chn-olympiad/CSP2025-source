#include<bits/stdc++.h>
using namespace std;
long long a[10005],k,n,dp[1005][1005],mx;
void dfs(int i,long long sum)
{
	if(i>n)
	{
		mx=max(mx,sum);
		return;
	}
	for(int l=i;l<=n;l++)
	{
		if(dp[i][l]==k)
		{
			dfs(l+1,sum+1);
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=true,f1=false;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][i]=a[i];
		if(a[i]>1) f=false;
		if(a[i]==0) f1=true;
	}
	if(f&&f1)
	{
		int sum;
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			sum+=a[i];
			cout<<sum;
			return 0;
		}
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]==1&&a[i-1]==1)
					a[i]=0,sum++;
			}
			cout<<sum;
			return 0;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int l=i;l<=n;l++)
		{
			for(int r=l+1;r<=n;r++)
				dp[l][r]=dp[l][r-1]^a[r];
		}
	}
	dfs(1,0);
	cout<<mx;
}