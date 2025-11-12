#include<bits/stdc++.h>
using namespace std;
int dp[100001][100001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>dp[1][i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			dp[i][j]=(dp[i-1][j]^dp[i-1][j+1]^dp[i-2][j+1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp[i][j]==k)
			{
				dp[i+1][j+1]=-1;
				dp[i-1][j+1]=-1;
				dp[i+1][j-1]=-1;
				dp[i-1][j-1]=-1;
				dp[i][j+1]=-1;
				dp[i][j-1]=-1;
				dp[i+1][j]=-1;
				dp[i-1][j]=-1;
			}
		}
	} 
	int x=0;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			if(dp[i][j]==k)
			{
				x++;
			}
		}
	} 
	cout<<x;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
