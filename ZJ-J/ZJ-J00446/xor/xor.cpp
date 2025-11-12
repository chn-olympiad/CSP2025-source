#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll a[500005];
ll f[500005];
ll dp[500005];
ll r[2200005];
ll d[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(r,-1,sizeof(r));
	scanf("%lld%lld",&n,&k);
	for(ll i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	r[0] = 0;
	for(ll i = 1;i <= n;i++){
		f[i] = f[i-1] ^ a[i];
		d[i] = r[k ^ f[i]];
		r[f[i]] = i;
	}
	dp[0] = 0;
	for(ll i = 1;i <= n;i++){
		dp[i] = dp[i-1];
		if(d[i] >= 0){
			dp[i] = max(dp[i],1+dp[d[i]]);
		}
	}
	printf("%lld",dp[n]);
	return 0;
}
