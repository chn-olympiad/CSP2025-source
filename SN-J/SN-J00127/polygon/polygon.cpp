#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n;
int a[5005];
ll dp[25000005],sum=0;
void add(ll &a,ll b){a=(a+b+mod)%mod;}
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ll ans=0;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++)
			add(ans,dp[j]);
		sum+=a[i];
		for(int j=sum;j>=a[i];j--)
			add(dp[j],dp[j-a[i]]);
	}
	ans=(qpow(2,n)-1+mod-ans+mod)%mod;
	cout<<ans;
	return 0;
}
