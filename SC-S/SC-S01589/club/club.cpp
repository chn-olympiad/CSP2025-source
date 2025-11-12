#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=500+10,INF=0x3f3f3f3f3f3f3f3f;
int t;
int n;
int a[N][5];
int dp[N][N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int ans=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][k]=-INF;
				}
			}
		} 
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2) && j+k<=i;k++){
					if(i-j-k>min(i,n/2)){
						continue;
					}
					if(j){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					}
					if(k){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					}
					if(i-j-k){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					}
//					cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
				}
			}
		}
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				ans=max(ans,dp[n][j][k]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//1
//10
//2020 14533 18961
//2423 15344 16322
//1910 6224 16178
//2038 9963 19722
//8375 10557 5444
//3518 14615 17976
//6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926