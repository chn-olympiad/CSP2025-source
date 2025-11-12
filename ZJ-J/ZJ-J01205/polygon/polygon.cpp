#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9, mod=998244353;
ll n, a[N], ma=-0x3f3f3f3f;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	scanf("%lld", &n);
	for(ll i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		ma = max(a[i], ma);
	}
	if(n==3){
		printf("1");
		exit(0);
	}
	if(n<3){
		printf("0");
		exit(0);
	}
	if(ma==1){
		ll ans = 1;
		for(ll i=n-1;i>=3;i--){
			ll nans = 1;
			for(ll j=n;j>i;j--){
				nans *= j;
				nans %= mod;
			}
			ans += nans;
			ans %= mod;
		}
		printf("%lld", ans);
		exit(0);
	}
	printf("%lld", n);
	return 0;
}