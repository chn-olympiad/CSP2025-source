#include<bits/stdc++.h>
using namespace std;
const int N=210;
int dp[N][N][N];//qian i ren,j ge 1 zu,k ge 2 zu 
int a[N][4];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++) dp[i][j][k]=0;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i-j-k>n/2) continue;//>
				if(j>=1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				if(k>=1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				if(i-j-k>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]); 
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n/2;j++){
		for(int k=0;k<=n/2;k++){
			if(n-j-k>n/2)continue;
			ans=max(ans,dp[n][j][k]);
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
