#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=2e5+5,mod=998244353;
ll t,n,dp[mx],a[mx],ldp[mx];
void colse(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll xz=1,ret=0;
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		ll _=0;
		for(int j=0;j<=a[i];j++) _=(_+dp[j])%mod;
		ret=(ret+(xz-_+mod)%mod)%mod;
		for(int j=a[i];j<=5000;j++) ldp[j]=(dp[j]+dp[j-a[i]])%mod;
		for(int j=a[i];j<=5000;j++) dp[j]=ldp[j],ldp[j]=0;
		xz=xz*2%mod;
	}
	cout<<ret<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	t=1;
	colse();
	while(t--) solve();
	return 0;
}