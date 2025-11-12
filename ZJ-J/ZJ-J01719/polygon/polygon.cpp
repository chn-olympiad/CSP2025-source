#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5010,mod=998244353;
ll n,a[MAXN],mx,ans;
ll C(ll x,ll y){
	ll ret=1,cnt=0;
	for(ll i=x;i>=x-y+1;i--){
		cnt++;
		ret=ret*i/cnt;
	}
	return ret;
}
void dfs(ll p,ll sum){
	if (sum>mx){
		ans=(ans+(1<<(n-p+1)))%mod;
		return;
	}
	if (p>n) return;
	for(ll i=p;i<=n;i++)dfs(i+1,sum+a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n,greater<ll>());
	for(ll i=1;i<=n;i++){
		mx=a[i];
		dfs(i+1,0);
	}
	cout<<ans;
	return 0;
}
