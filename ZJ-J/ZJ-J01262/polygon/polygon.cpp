#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5005;
const int mod=998244353;
ll dp[N],b[N];
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	b[0]=1;
	for(int i=1;i<=n;i++)b[i]=b[i-1]*2%mod;
	sort(a+1,a+n+1);
	dp[0]=1;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int j=0;j<=a[i];j++)
			sum=(sum+dp[j])%mod;
		for(int j=5000;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		ans=(ans+b[i-1]-sum+mod)%mod;
	}
	cout<<ans;
	return 0;
}