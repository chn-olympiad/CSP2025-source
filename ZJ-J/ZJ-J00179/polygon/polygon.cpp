#include<bits/stdc++.h>
#define rep(i,x,y) for(ll i=x;i<=y;++i)
#define repp(i,x,y) for(ll i=x;i>=y;--i)
#define ll long long
#define getc getchar
#define putc putchar
#define scan scanf
#define prin printf
using namespace std;
const ll N=5e3,mod=998244353;
ll a[N+100];
ll n,cnt=0;
void dfs(ll deep,ll sum,ll maxn) {
	if(deep==n+1) {
		if(sum>(maxn<<1)) ++cnt,cnt%=mod;
		return ;
	}
	dfs(deep+1,sum,maxn);
	dfs(deep+1,sum+a[deep],max(maxn,a[deep]));
}
ll qpow(ll e,ll x) {
	ll ans=1;
	while(x) {
		if(x&1) ans=(ans*e)%mod;
		e=(e*e)%mod;
		x>>=1;
	}
	return ans;
}
ll inv(ll x) {
	return qpow(x,mod-2);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll maxn=0;
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld",a+i),maxn=max(maxn,a[i]);
//	cerr<<inv(2)<<endl;
	if(maxn==1) {
		prin("%lld",((qpow(2,n)-n-1+mod)%mod-((n*(n-1+mod)%mod)*inv(2))%mod+mod)%mod);
		return 0;
	}
	dfs(1,0,0);
	prin("%lld",cnt);
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/
