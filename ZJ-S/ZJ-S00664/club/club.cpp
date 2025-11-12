#include<bits/stdc++.h>
#define N 210
using namespace std;
int n,a1[N],a2[N],a3[N],ans=0,dp[N][N/2][N/2][N/2],s1,s2,s3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a1[i]>>a2[i]>>a3[i];
		ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int k=0;k<=n/2;k++)
				for(int j=0;j<=n/2;j++)
					for(int l=0;l<=n/2;l++)
						dp[i][k+1][j][l]=max(dp[i-1][k][j][l]+a1[i],dp[i][k+1][j][l]),
						dp[i][k][j+1][l]=max(dp[i-1][k][j][l]+a2[i],dp[i][k][j+1][l]),
						dp[i][k][j][l+1]=max(dp[i-1][k][j][l]+a3[i],dp[i][k][j][l+1]);
		for(int k=0;k<=n/2;k++)
			for(int j=0;j<=n/2;j++)
				for(int l=0;l<=n/2;l++)
					ans=max(dp[n][k][j][l],ans);
		printf("%d\n",ans);
	}
	return 0;
}