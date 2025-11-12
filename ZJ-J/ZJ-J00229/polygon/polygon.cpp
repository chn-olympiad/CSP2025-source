#include <bits/stdc++.h>
using namespace std;
const int N=5010;
const int mod=998224353;
int n,a[N],dp[505][50010],ans,ma,ma2,w,su,la_;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ma=max(a[i],ma);
		su+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;++i) dp[i][0]=1; 
	for(int i=1;i<=n;++i){
		for(int j=1;j<a[i];++j){
			dp[i][j]=dp[i-1][j];
		}
		for(int j=su;j>=a[i];--j){
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
		}
	}
	ma=0;
	a[n+1]=su+1;
	for(int i=1;i<=n;++i){
		ma=max(a[i],ma);
		ma2=max(ma,a[i+1]);
		for(int j=2*ma+1;j<min(su+1,2*ma2+1);++j){
			ans=(ans+dp[i][j])%mod;
		}
	} 
	cout<<ans;
	return 0;
}

