#include <bits/stdc++.h>
using namespace std;
int arr[500][5];
int dp[210][105][105];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(arr,0,sizeof(arr));
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&arr[i][1],&arr[i][2],&arr[i][3]);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= n/2;j++){
				for(int k = 0;k <= n/2;k++){
					dp[i][j][k]=dp[i-1][j][k];
					if(i-j-k <= n/2 && i-j-k>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+arr[i][3]);
					}
					if(j>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+arr[i][1]);
					}
					if(k>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+arr[i][2]);
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0;i <= n/2;i++){
			for(int j = 0;j <= n/2;j++){
				ans = max(ans,dp[n][i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
