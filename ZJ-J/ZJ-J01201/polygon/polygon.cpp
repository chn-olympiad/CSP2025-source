#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll INF=1e18;
ll n,a[5005];
ll fac[5005],sum;
bool flag;
ll powmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void dfs(ll step,ll maxn,ll cnt){
	if(step==n){
		if(cnt>2*maxn)sum++;
		return;
	}
	dfs(step+1,max(maxn,a[step+1]),cnt+a[step+1]);
	dfs(step+1,maxn,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(!flag){
		ll ans=0;
		fac[0]=fac[1]=1;
		for(ll i=2;i<=n;i++)fac[i]=fac[i-1]*i%mod;
		for(ll i=3;i<=n;i++){
			ll x=fac[n]*powmod(fac[i],mod-2)%mod*powmod(fac[n-i],mod-2)%mod;
			ans=(ans+x)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,-INF,0);
	cout<<sum-1;
	return 0;
}

