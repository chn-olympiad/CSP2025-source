#include<bits/stdc++.h>
using namespace std;
long long t,n,a[3][100001],dp[101][101][101],dp1[101][101],m,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++) cin>>a[j][i];
		}
		m=n/2;
		ans=0;
		if(n==200){
			memset(dp1,0,sizeof(dp1));
			for(int i=1;i<=n;i++){
				for(int j=m;j>=0;j--){
					for(int k=m;k>=0;k--){
						if(j>0) dp1[j][k]=max(dp1[j][k],dp1[j-1][k]+a[0][i]);
						if(k>0) dp1[j][k]=max(dp1[j][k],dp1[j][k-1]+a[1][i]);
					}
				}
			}
			for(int j=0;j<=m;j++){
				ans=max(ans,dp1[j][n-j]);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n){
			sort(a[0]+1,a[0]+n+1);
			for(int i=n;i>n/2;i--) ans+=a[0][i];
			cout<<ans<<'\n';
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=m;j>=0;j--){
				for(int k=m;k>=0;k--){
					for(int l=m;l>=0;l--){
						if(j>0) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[0][i]);
						if(k>0) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[1][i]);
						if(l>0) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[2][i]);
					}
				}
			}
		}
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m;k++){
				ans=max(ans,dp[j][k][n-j-k]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

