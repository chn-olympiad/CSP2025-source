#include<bits/stdc++.h>
using namespace std;
int a[100005][5],dp[105][105][105];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,ans=0;
		scanf("%d",&n);
		int mx=n/2;
		for(int i=0;i<=mx;i++)
			for(int j=0;j<=mx;j++)
				for(int k=0;k<=mx;k++) dp[i][j][k]=0;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		dp[0][0][0]=0;
		for(int d=1;d<=n;d++){
			for(int i=0;i<=min(mx,d);i++)
				for(int j=0;j<=min(mx,d-i);j++){
					int k=d-i-j;
					if(k>mx) continue;
					if(i!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[d][1]);
					if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[d][2]);
					if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[d][3]);
					if(d==n) ans=max(ans,dp[i][j][k]);
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}