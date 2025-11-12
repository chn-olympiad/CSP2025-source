#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5005];
ll c[5005];
ll ans=0;
void dfs(ll x,ll d,ll maxn,ll sum){
	if(d==n){
		if(maxn*2<sum) ans++;
		return ;
	}
	if(d>=3){
		if(maxn*2<sum) ans++;
	}
	for(int i=x+1;i<=n;++i){
		dfs(i,d+1,max(maxn,a[i]),sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,greater<ll>());
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
