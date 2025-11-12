#include<bits/stdc++.h>
using namespace std;
int a[100010]= {0},b[100010]= {0},c[100010]= {0};
int dp[5][50010]= {0};
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		int res=0;
		for(int i=n;i>n/2;i--){
			res+=a[i];
		}
		cout<<res;
//		for(int i=1; i<=n; i++) {
//			dp[1][0]=a[i];
//			dp[2][0]=b[i];
//			dp[3][0]=c[i];
//			for(int j=min(n/2,i-1); j>0; j--) {
//				dp[1][j]=max(dp[1][j],dp[1][j-1]+a[i]);
//				dp[2][j]=max(dp[2][j],dp[2][j-1]+b[i]);
//				dp[3][j]=max(dp[3][j],dp[3][j-1]+c[i]);
//			}
//		}
//		int res=0;
//		for(int i=n/2;i>=0;i--){
//			for(int j=n/2;j>=0;j--){
//				if(n-i-j>n/2){
//					break;
//				}
//				res=max(res,dp[1][i]+dp[2][j]+dp[3][n-i-j]);
//			}
//		}
//		for(int i=n/2;i>=0;i--){
//			cout<<dp[1][i]<<" "<<i<<endl;
//		}
//		cout<<res<<endl;
	}
	return 0;
}