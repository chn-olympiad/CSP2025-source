//SN-S00244  张溪诺  西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5][10010];
int dp[3][510][510];
int main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	int T;
 	cin>>T;
 	while(T--)
 	{
 		int n;
 		cin>>n;
 		int m=n/2;
 		for(int i=1;i<=n;i++)
 		{
 			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=m;k++)
				{
					dp[i][j][k]=max(dp[i][j-1][k],dp[i][j-1][k-1]+a[i][j]);
				}
			}
		}
		int maxx=max(dp[1][n][m]+dp[2][n][m],dp[2][n][m]+dp[3][n][m]);
		cout<<max(maxx,dp[1][n][m]+dp[3][n][m])<<"\n";
	}
	return 0;
}//不要挂分！！不要挂分 ！！ 给我60分吧！！！ 

