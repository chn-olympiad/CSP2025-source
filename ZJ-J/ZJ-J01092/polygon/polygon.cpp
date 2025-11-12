#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int b[5005];
int dp[5005][5005][2];
int maxx;
int y;
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]);
	}
	y=maxx+1;
	dp[0][0][0]=1;
	sort(a+1,a+1+n); 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i]-1;j++){
			dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
			dp[i][j][0]%=mod;
		}
	    for(int j=a[i];j<=y-1;j++){
	    	dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
	    	dp[i][j][1]=dp[i-1][j-a[i]][0]+dp[i-1][j-a[i]][1];
	    	dp[i][j][0]%=mod;
	    	dp[i][j][1]%=mod;
		}
		dp[i][y][0]=dp[i-1][y][0]+dp[i-1][y][1];
		dp[i][y][0]%=mod;
		for(int j=y-a[i];j<=y;j++){
		    dp[i][y][1]+=dp[i-1][j][0];
		    dp[i][y][1]%=mod;
		    dp[i][y][1]+=dp[i-1][j][1];
		    dp[i][y][1]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=y;j++){
			ans+=dp[i][j][0];
			ans%=mod;
		}
	}
	printf("%d",ans); 
	return 0;
}
