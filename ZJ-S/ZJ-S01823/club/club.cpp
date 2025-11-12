#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][10],dp[300005][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(dp[3*i+j-3][j]+1<=n/2){
					dp[3*i+j][j]=dp[3*i+j-3][j]+1;
					dp[3*i+j][5]=dp[3*i+j-3][5]+a[i][j];
				}
			}
		}
		cout<<max(dp[3*n+1][5],max(dp[3*n+2][5],dp[3*n+3][5]))<<"\n";
	}
	return 0;
}
