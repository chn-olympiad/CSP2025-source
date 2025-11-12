#include<bits/stdc++.h>
using namespace std;
const int MAXN=200;//200000
int t,n;
long long a[MAXN+5][5];
long long ans=0;
long long dp[MAXN+5][MAXN+5][MAXN+5];
//void dfs(int now,int cnta,int cntb,int cntc,int sum){
//	if(now>n){
//		ans=max(ans,sum);
//		return;
//	}
//	if(cnta<n/2) dfs(now+1,cnta+1,cntb,cntc,sum+a[now][1]);
//	if(cntb<n/2) dfs(now+1,cnta,cntb+1,cntc,sum+a[now][2]);
//	if(cntc<n/2) dfs(now+1,cnta,cntb,cntc+1,sum+a[now][3]);
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
//		dfs(1,0,0,0,0);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(n/2,i);j++){
				for(int k=max(0,i-j-n/2);j+k<=i && k<=n/2;k++){
					int l=i-j-k;
					dp[i][j][k]=0;
					if(j>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(l>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
//					dp[i][j][k]=max(dp[i-1][j][k]+a[i][3],max(dp[i-1][j-1][k]+a[i][1],dp[i-1][j][k-1]+a[i][2]));
//					cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"]["<<l<<"]="<<dp[i][j][k]<<endl;
				}
			}
		}
		for(int j=0;j<=n/2;j++){
			for(int k=max(0,n-j-n/2);j+k<=n && k<=n/2;k++){
				ans=max(ans,dp[n][j][k]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

