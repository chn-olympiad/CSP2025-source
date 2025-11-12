#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=998244353;
ll n,a[114514],dp[5007];
ll ans;
ll qpow(ll a,ll k){
	ll res=a,rtn=1;
	while(k){
		if(k&1)rtn=rtn*res%M;
		k/=2;
		res=res*res%M;
//		cout<<rtn<<'\n';
	}
	return rtn%M;
}
void main1(){
	sort(a+1,a+1+n);
	dp[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=5000;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=M;
		}
	}
	
	for(ll i=2;i<=5000;i++){
		dp[i]+=dp[i-1];
		dp[i]%=M;
	}
//	for(ll i=1;i<=20;i++){
//		cout<<dp[i]<<' ';
//	}
//	cout<<'\n';
	for(ll i=3;i<=n;i++){
		ans=(ans+qpow(2,i-1))%M;
//		cout<<qpow(2,i-1)<<' '<<dp[a[i]]<<'\n';
	}
	for(ll i=3;i<=n;i++){
		ans=(ans-dp[a[i]]+M)%M;
	}
	cout<<ans;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll f1=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f1=0;
	}
	if(f1){
		ll ans=1;
		for(ll i=1;i<=n;i++){
			ans=ans*2%M;
		}
		ans=(ans-1-(n-1)*n/2-n+M)%M;
		cout<<ans;
		return 0;
	}
	if(n==3){
		ll x=a[1],y=a[2],z=a[3];
		if(x+y>z&&x+z>y&&y+z>x){
			cout<<1;
		}else cout<<0;
		return 0;
	}
	if(n<=20){
		for(ll i=7;i<(1<<n);i++){
			ll sum=0,ma=0;
			for(ll j=1;j<=n;j++){
				if(i&(1<<j-1)){
					ma=max(ma,a[j]);
					sum+=a[j];
				}
			}
			if(sum>2*ma){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	main1();
	return 0;
}