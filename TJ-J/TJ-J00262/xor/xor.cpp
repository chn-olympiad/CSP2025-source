#include<bits/stdc++.h>
using namespace std;
int n;
long long k,sum=0,a[555555],b[1111][1111],dp[1111][1111]={0};
bool f[1111][1111];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(dp,1,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
			f[i][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		b[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
		{
			b[i][j]=b[i][j-1]^a[j];
			if(b[i][j]==k)
			{
				f[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n-3;i++)
	{
		for(int j=i+1;j<=n-2;j++)
		{
			for(int l=j+1;l<=n-1;l++)
			{
				for(int c=l+1;c<=n;c++)
				{
					if(f[i][j]&&f[l][c])
						dp[l][c]=dp[i][j]+1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum=max(sum,dp[i][j]);
		}
	}
	cout<<sum;
	return 0;
}

