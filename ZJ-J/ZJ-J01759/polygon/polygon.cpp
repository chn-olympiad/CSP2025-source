#include <iostream>
#include <cstdio>
#include <algorithm>

namespace noip {
typedef long long ll;
constexpr ll MAX_N = 5000;
constexpr ll MAX_LOG_N = 32;
constexpr ll MOD = 998244353;
ll a[1+MAX_N];
ll A[1+MAX_N][1+MAX_N];
ll len[1+MAX_N];
ll ksm(ll x, ll y) {
	ll ji = 1;
	while (y) {
		if (y%2 == 1) (ji *= ji) %= MOD;
		(x *= x) %= MOD;
		y /= 2;
	}
	
	return ji;
}
ll geshu(ll x, ll y) {
	if (y == 0) return 1;
	if (A[x][y]) return A[x][y];
	ll sum = 1;
	for (ll i = x; i >= x-y+1; i--) (sum *= i) %= MOD;
	
	for (ll i = 2; i <= y; i++) (sum = ksm(sum, i-2)) %= MOD;
	return A[x][y] = sum;
}
ll suan(ll x, ll y, ll sum) {
	if (x == 0) return sum > y;
	ll tmp = 0;
	if (len[x] == 0) return suan(x-1, y, sum);
	for (ll i = 0; i <= len[x]; i++)
		(tmp += suan(x-1, y, sum+i*x)*geshu(len[x], i)) %= MOD;
	return tmp;
}

void main() {
	std::freopen("polygon.in", "r", stdin);
	std::freopen("polygon.out", "w", stdout);
	
	ll n; std::cin >> n;
	for (ll i = 1; i <= n; i++)
		std::cin >> a[i];
	
	std::sort(a+1, a+1+n);
	
	ll m = 0;
	for (ll i = 1; i <= n; i++) {
		len[a[i]]++, m = std::max(m, a[i]);
	}
		
	ll ans = 0;
	
	for (ll i = 1; i <= m; i++) {
		(ans += suan(i, 2*i, 0)) %= MOD;
			
			
	}
	
	std::cout << ans;		
	
	
	
}
}

int main() {
	noip::main();
	return 0;
}
