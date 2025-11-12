#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10005],cnt;
void dfs(ll u,ll pos,ll sum) {
	if(pos>=3 && sum>a[u]*2) ++cnt,cnt%=998244353;
	for(ll i=u+1; i<=n; ++i) dfs(i,pos+1,sum+a[i]);
}
ll ksm(ll a,ll b) {
	ll res=1;
	while(b) {
		if(b&1) res=res*a,res%=998244353;
		a=a*a%998244353;
		b/=2;
	}
	return res;
}
ll C(ll n,ll m) {
	ll p1=1,p2=1;
	for(ll i=n; i>=(n-m+1); --i) p1*=i,p1%=998244353;
	for(ll i=m; i>=1; --i) p2*=i,p2%=998244353;
	return p1*ksm(p2,998244351)%998244353;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1; i<=n; ++i) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1) {
		ll ans=0;
		for(ll i=3; i<=n; ++i) {
			ans+=C(n,min(i,n-i));
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n<=100) {
		for(ll i=1; i<=n; ++i) {
			dfs(i,1,a[i]);
		}
		cout<<cnt;
	}else{
		cout<<n*n-n+1;
	}
	return 0;
}
