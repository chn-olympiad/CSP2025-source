#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N][5],dp[N][N][N];
int T,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=n/2;k++)
				{
					if(j+k>i||i-j-k>n/2)
						continue;
					if(j>=1)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k>=1)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(i-j-k>=1)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}		
		int ans=0;
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=n/2;j++)
				if(i+j>=n/2)
					ans=max(ans,dp[n][i][j]);
		printf("%d\n",ans);
		memset(dp,0,sizeof(dp));
	}
}
