#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200+10;
int a[N][3],dp[N][N][N],ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T; while(T--){
		memset(dp,0,sizeof(dp)); ans=0;
		int n; cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(i-j-k<0) break;
					if(j>0)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k>0)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					if(i==n) ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
