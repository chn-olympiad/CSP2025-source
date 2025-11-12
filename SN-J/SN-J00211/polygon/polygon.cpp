#include<bits/stdc++.h>
using namespace std;

const int maxn=15555,mod=998244353;
int n,a[maxn],dp[2][maxn],mx,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	mx+=2;
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=0,c=0;i<n;i++,c^=1){
		for(int j=0;j<=2*mx;j++){
			if(dp[c][j]&&j+a[i+1]>2*a[i+1]) (ans+=dp[c][j])%=mod;
		}
		for(int j=0;j<=2*mx;j++) dp[c^1][j]=0;
		for(int j=0;j<=2*mx;j++){
			if(!dp[c][j]) continue;
			(dp[c^1][j]+=dp[c][j])%=mod;
			(dp[c^1][min(j+a[i+1],2*mx)]+=dp[c][j])%=mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
