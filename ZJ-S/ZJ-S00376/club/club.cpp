#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxx=1e4;
int T,n,a1[maxx*2],a2[maxx*2],a3[maxx*2],dp[2][maxx][maxx];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a1[i]>>a2[i]>>a3[i];
		int k=0,ans=0;
		for (int i=1;i<=n;i++){
			for (int x=0;x<=min(n/2,i);x++){
				for (int y=0;y<=min(n/2,i-x);y++){
					if (x>0) dp[k][x][y]=dp[1-k][x-1][y]+a1[i];
					if (y>0) dp[k][x][y]=max(dp[k][x][y],dp[1-k][x][y-1]+a2[i]);
					if ((i-x-y>0)&&(i-x-y)<=n/2) dp[k][x][y]=max(dp[k][x][y],dp[1-k][x][y]+a3[i]);
					if (i==n) ans=max(ans,dp[k][x][y]);	
				}
			}
			k=1-k;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
