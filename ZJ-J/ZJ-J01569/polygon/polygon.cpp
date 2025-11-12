#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n;
ll a[25];
ll ans;

ll qpow(ll a,ll k){
	ll ret=1;
	while(k>0){
		if(k%2==1) ret=(ret*a)%mod,k--;
		else a=(a*a)%mod, k/=2;
	}
	return ret;
}

bool b[25];
ll sum,mx;

void dfs(ll k){
	ll sv=mx;
	if(k>n){
		if(sum>2*mx) ans++, ans%=mod;
		return;
	}
	b[k]=true;
	sum+=a[k];
	mx=max(mx,a[k]);
	dfs(k+1);
	b[k]=false;
	sum-=a[k];
	mx=sv;
	dfs(k+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n>20){
		ll c2;
		if(n%2==0) c2=(n/2*(n-1))%mod;
		else c2=((n-1)/2*n)%mod;
		ans=(qpow(2,n)-1-n-c2+mod)%mod;
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}