#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[7005],dp[7005][7005];
const ll MOD=998244353;
ll ui=-1;
ll L_max(ll x,ll y){
	return (x>y?x:y);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ui=max(ui,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=ui;j++){
			dp[i][j]=((j>=a[i]?dp[i-1][j-a[i]]:0)+dp[i-1][j])%MOD;
		}
		dp[i][ui+1]=dp[i-1][ui+1];
		for(ll j=ui-a[i]+1;j<=ui+1;j++){
			dp[i][ui+1]=(dp[i][ui+1]+dp[i-1][j])%MOD;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=ui;j>=0;j--){
			dp[i][j]=(dp[i][j]+dp[i][j+1])%MOD;
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans=(ans+dp[i-1][a[i]+1])%MOD;
	}
	cout<<ans;
	return 0;
}
