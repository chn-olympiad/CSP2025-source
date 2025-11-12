#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[5005];
ll dp[15005];
ll tot;
const ll p = 998244353;
ll ans = 1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	dp[0] = 1;
	for(ll i = 1;i <= n;i++){
		for(ll j = 0;j <= a[i];j++){
			tot += dp[j];
			tot %= p;
		}
		for(ll j = 10050;j >= a[i];j--){
			dp[j] = (dp[j-a[i]] + dp[j]) % p;
		}
	}
	for(ll i = 1;i <= n;i++){
		ans *= 2;
		ans %= p;
	}
	ans -= tot;
	ans--;
	printf("%lld",((ans % p) + p) % p);
	return 0;
}
/*12
1 2 4 8 16 30 64 128 256 512 1024 2048 4096*/
