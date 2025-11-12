#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N][3];
int a[N][3];
int t;
int n;
int ans=0;
int cnt1,cnt2,cnt3;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dp[1][1]=a[1][1]; 
		dp[1][2]=a[1][2];
		dp[1][3]=a[1][3];
		for(int k=1;k<=n;k++){
			
				dp[k][1]=max(dp[k][1],dp[k][2]);
				dp[k][1]=max(dp[k][1],dp[k][3]);
				
				dp[k+1][1]=dp[k][1]+a[k+1][1];
				dp[k+1][2]=dp[k][1]+a[k+1][2];
				dp[k+1][3]=dp[k][1]+a[k+1][3];
		
		}
		ans=max(dp[n][1],dp[n][2]);
		ans=max(ans,dp[n][3]);
		cout<<ans<<" ";
	}
	return 0;
}
