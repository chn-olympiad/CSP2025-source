#include<bits/stdc++.h>
#define rep(i,x,y) for(ll i=x;i<=y;++i)
#define repp(i,x,y) for(ll i=x;i>=y;--i)
#define ll long long
#define scan scanf
#define prin printf
using namespace std;
const ll N=500,M=500,mod=998244353;
ll n,m,s[N+100],c[N+100],cnt;
bool f[N+100];
void dfs(ll deep,ll sum) {
	if(n-deep+1+sum<m) return ;
	if(deep==n+1) {
		if(sum>=m) ++cnt;
		return ;
	}
	rep(i,1,n) {
		if(f[i]) continue;
		f[i]=1;
		if(s[deep]==0||deep-1-sum>=c[i]) dfs(deep+1,sum),f[i]=0;
			else dfs(deep+1,sum+1),f[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scan("%lld%lld",&n,&m);
	rep(i,1,n) {
		char ch;
		cin>>ch;
		if(ch=='1') s[i]=1;
	}
	ll sum=0;
//	rep(i,1,n) cerr<<s[i]<<" ";
	rep(i,1,n) scan("%lld",c+i),sum+=(c[i]==0?1:0);
	bool f=1;
	rep(i,1,n)
		if(s[i]!=1) {
			f=0;
			break;
		}
	if(f) {
		ll mm=n-sum;
		if(mm>=m) {
			ll s=1;
			rep(i,1,n) s=(s*i)%mod;
			prin("%lld",s);
		}else prin("0");
		return 0;
	}
	dfs(1,0);
	prin("%lld",cnt%mod);
	return 0;
}
/*
3 2
101
1 1 2
*/
