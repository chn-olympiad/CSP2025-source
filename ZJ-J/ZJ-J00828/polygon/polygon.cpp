#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,a[5010],dp[5010][5],mod=998244353,ans;
ll qpow(ll x,ll q){
	ll res=1;
	while(q){
		if(q&1)res=(res*x)%mod;
		q>>=1;
		x=(x*x)%mod;
	}return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);ans=qpow(2,n);
	ans=(ans-n*(n-1)/2-n-1+mod)%mod;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++)ans=(ans-dp[j][3]-dp[j][4]-dp[j][2]+mod+mod+mod)%mod;
		for(int j=5000;j>=a[i];j--)dp[j][4]=(dp[j-a[i]][3]+dp[j-a[i]][4]+dp[j][4])%mod;
		for(int j=5000;j>=a[i];j--)dp[j][3]=(dp[j-a[i]][2]+dp[j][3])%mod;
		for(int j=5000;j>=a[i];j--)dp[j][2]=(dp[j-a[i]][1]+dp[j][2])%mod;
		dp[a[i]][1]=(dp[a[i]][1]+1)%mod;
	}
	cout<<ans;
	return 0;
}

