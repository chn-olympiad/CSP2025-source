#include<bits/stdc++.h>
using namespace std;
const int NUI=998244353;
long long ans;
int n;
int a[5005];
int dp[505][505][505]; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++i)
		{
			for(int k=1;k<=n;++k)
			{
				dp[i][j][k]=max(dp[i][j-1][k],dp[i-1][j-a[i]][max(k,a[i])]+a[i]);
			}
		}
	}
	cout<<dp[n][n][n];
	return 0;
}
