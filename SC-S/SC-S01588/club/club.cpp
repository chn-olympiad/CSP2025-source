#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
int t;
ll n,ans,dp[N][5],a[N][5],cnt1,cnt2,cnt3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n/2;++i){
			for(int j=1;j<=3;++j){
				if(j==1) dp[i][j]=max(dp[i-1][3],max(dp[i-1][1],dp[i-1][2]))+a[i][j];
			}
		}
		for(int i=n/2;i<=n;++i){
			for(int j=1;j<=3;++j){
				if(j==1) dp[i][j]=max(dp[i-1][2],dp[i-1][3])+a[i][j];
				if(j==2) dp[i][j]=max(dp[i-1][1],dp[i-1][3])+a[i][j];
				if(j==3) dp[i][j]=max(dp[i-1][1],dp[i-1][2])+a[i][j];
			}
		}
		for(int i=1;i<=3;++i) ans=max(ans,dp[n][i]);
		cout<<ans<<"\n";
	}
	return 0;
}
