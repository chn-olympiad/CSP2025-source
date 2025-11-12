#include<bits/stdc++.h> 
using namespace std;
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>> n >> k;
	int a[n+3],ans[n+3][n+3];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==j)
			{
				ans[i][j]=a[i];
			}
			else
			{
				ans[i][j]=(ans[i-1][j]^a[i]);
			}
		} 
	}
	int dp[n+3][n+3];
	for(int i=0;i<n;i++)
	{
		for(int y=1;y+i<=n;y++)
		{
			if(i==0)
			{
				dp[y][y]=(ans[y][y]==k);
			}
			else
			{
				if((ans[y+i][y]==k)) dp[y+i][y]=max(1,dp[y+i-1][y]+dp[y+i][y+1]-dp[y+i-1][y+1]);
				else dp[y+i][y]=max(0,dp[y+i-1][y]+dp[y+i][y+1]-dp[y+i-1][y+1]); 
			}
		}
		
	}
	cout << dp[n][1];
	return 0;
}
