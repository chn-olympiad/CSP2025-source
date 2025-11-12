#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int t,bil[5][100005],dp[5][100005],n;
int maxx(int a,int b,int c,int d){
	return max(a,max(b,max(c,d)));
}
signed main(){
	FI("club");
	FO("club");
	cin>>t;
	int i=1;
	int ma,sum=0;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>bil[1][i]>>bil[2][i]>>bil[3][i];
			ma=max(bil[1][i],max(bil[2][i],bil[3][i]));
			sum+=ma;	
		}
		int W=n/2;
		for(int i=1;i<=3;i++){
			for(int k=1;k<=n;k++){
				for(int j=W;j>=1;j--){
					dp[i][j]=maxx(dp[i][j],dp[1][j-1]+bil[1][k],dp[i][j-1]+bil[i][k],dp[i][j-1]+bil[i][k]);
				}
			}
		}
		cout<<ma;
		//cout<<dp[1][W]<<" "<<dp[2][W]<<" "<<dp[3][W]<<" "<<endl;
	}
	return 0;
}
//		for(int i=1;i<=3;i++){
//			for(int k=1;k<=n;k++){
//				for(int j=W;j>=1;j--){
//					dp[i][j]=max(dp[i][j],dp[i][j-1]+bil[i][k]);
//				}
//			}
//		}

