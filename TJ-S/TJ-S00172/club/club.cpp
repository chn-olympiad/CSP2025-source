#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
int a[N][3];
int dp[103][104][105];
int main(){
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0][0]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int idx=1;idx<=n;idx++){
			for(int i=n;i>=0;i--){
				for(int j=n-i;j>=0;j--){
					int k=idx-1-i-j;
					if(k<0 || k>n) continue;
					if(dp[i][j][k]<0) continue;
					if(i+1<=n/2){
						dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[idx][0]);
					}
					if(j+1<=n/2){
						dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+a[idx][1]);
					}
					if(k+1<=n/2){
						dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+a[idx][2]);
					}
				}
			}
		}
		int ans=-1;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				int k=n-i-j;
				if(k>0 && k<=n/2 && i+j+k==n){
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
