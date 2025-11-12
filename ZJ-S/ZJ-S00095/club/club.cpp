#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int T;
int n;
long long dp[210][210];
long long ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		memset(dp,0xf0,sizeof(dp));
		dp[0][0]=0;
		ans=-1e18;
		for(int x=1; x<=n; x++) {
			long long a,b,c;
			cin>>a>>b>>c;
			for(int i=n/2; i>=0; i--)
				for(int j=n/2; j>=0; j--) {
					dp[i][j]+=c;
					if(i)
						dp[i][j]=max(dp[i-1][j]+a,dp[i][j]);
					if(j)
						dp[i][j]=max(dp[i][j-1]+b,dp[i][j]);
					if(i+j>=n/2)
						ans=max(dp[i][j],ans);
				}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
