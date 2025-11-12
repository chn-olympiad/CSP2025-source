#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans;
int dp[790][790][790];
int tong[20005];
bool key1=1;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
				if(j==1)tong[a[i][j]]++;
				else if(j==2 && a[i][j]!=a[i][j-1])key1=0;
				else if(j==3 && a[i][j]!=a[i][j-1])key1=0;
			}
		if(key1) {
			int cnt=0;
			for(int i=20000; cnt<n/2; i--) {
				if(cnt+tong[i]<=(n/2))cnt+=tong[i],ans+=tong[i]*i;
				else ans+=(n/2-cnt)*i;
			}
			cout<<ans<<endl;
			continue;
		}
		memset(dp,0,sizeof dp);
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=min(i,(n/2)); j++) {
				for(int k=0; k<=min(i,(n/2)); k++) {
					if(i-j-k>(n/2))continue;
					if(j==0) {
						if(k==0)dp[j][k][i-j-k]=dp[j][k][i-j-k-1]+a[i][3];
						else if(i-j-k==0)dp[j][k][i-j-k]=dp[j][k-1][i-j-k]+a[i][2];
						else dp[j][k][i-j-k]=max(dp[j][k-1][i-j-k]+a[i][2],dp[j][k][i-j-k-1]+a[i][3]);
					} else if(k==0) {
						if(i-j-k==0)dp[j][k][i-j-k]=dp[j-1][k][i-j-k]+a[i][1];
						else dp[j][k][i-j-k]=max(dp[j-1][k][i-j-k]+a[i][1],dp[j][k][i-j-k-1]+a[i][3]);
					} else if(i-j-k==0)dp[j][k][i-j-k]=max(dp[j-1][k][i-j-k]+a[i][1],dp[j][k-1][i-j-k]+a[i][2]);
					else dp[j][k][i-j-k]=max(dp[j-1][k][i-j-k]+a[i][1],max(dp[j][k-1][i-j-k]+a[i][2],dp[j][k][i-j-k-1]+a[i][3]));
					if(i==n)ans=max(ans,dp[j][k][i-j-k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

