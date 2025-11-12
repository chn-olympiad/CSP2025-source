#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[222][111][111],ans=0,T;
int arr[114514][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>T;
	while(T--){
		cin>>n;memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
			for(int j=0;j<=n;j++)for(int k=0;k<=n;k++){
				if(j>n/2||k>n/2||k+j>i||j>i||k>i)continue;
				if(i-j-k>n/2)continue;
				if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+arr[i][0]);
				if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+arr[i][1]);
				if(i+1-j-k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+arr[i][2]);
				ans=max(ans,dp[i][j][k]);
			}
		}
		cout<<ans<<endl;
	}
}
