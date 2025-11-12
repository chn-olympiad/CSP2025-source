#include<bits/stdc++.h>
using namespace std;
int t;
int n,s[3][100005],dp[505][505][505];
int main(){
	freopen("club.in","r",stdin);
   	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>s[0][i]>>s[1][i]>>s[2][i];
		memset(dp,0,sizeof dp);
		dp[1][0][0]=s[0][1];dp[0][1][0]=s[1][1];dp[0][0][1]=s[2][1];
		for(int num=2;num<=n;num++){
			for(int j=0;j<num;j++){
				for(int k=0;k<num-j;k++){
					int i=num-j-k;
					if(i+j<k||i+k<j||k+j<i)continue;
					if(i){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+s[0][num]);
					}if(j){
						dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+s[1][num]);
					}if(k){
						dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+s[2][num]);
					}
				}
			}
		}
		int ans=0;
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				int i=n-j-k;
				if(i+j<k||i+k<j||k+j<i)continue;
				if(ans<dp[i][j][k]){
					ans=dp[i][j][k];
				}
			}
		}
		cout<<ans<<endl;
	}
}
