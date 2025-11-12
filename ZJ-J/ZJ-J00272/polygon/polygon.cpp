#include <bits/stdc++.h>
#define ll long long
const ll N = 5005;
const ll Mod = 998244353; 
ll n, a[N], ans, fac[N];
bool f[N];
void dfs(ll step, ll cnt) { 
	if (step == n + 1) {
		if (cnt < 3) return;
		std::vector<ll> p;
		for (ll i = 1; i <= n; i ++) if (f[i]) 
			p.push_back(a[i]);
		ll tot = 0, mx = -INT_MAX;
		ll h = p.size();
		for (ll i = 0; i < h; i ++) {
			tot += p[i];
			if (p[i] > mx) mx = p[i];
		} 
		if (tot > mx * 2) {
			ans ++;
			ans %= Mod;
		}
		return;
	}
	f[step] = 1;
	dfs(step + 1, cnt + 1);
	f[step] = 0;
	dfs(step + 1, cnt);
}
ll qpow(ll a, ll b) {
	ll c = 1;
	while (b) {
		if (b & 1) c = (c * a) % Mod;
		a = (a * a) % Mod;
		b >>= 1;
	}
	return c;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	std::cin >> n;
	bool X = 1;
	for (ll i = 1; i <= n; i ++) {
		std::cin >> a[i];
		if (a[i] != 1) X = 0;
	}
	if (X) { // 预计 24pts 
		// C(n, 3) + C(n, 4) + ... + C(n, n)
		ll F = 1; fac[0] = 1;
		for (ll i = 1; i <= n; i ++) {
			F = (F * i) % Mod;
			fac[i] = F; 
		}
		ll result = 0;
		for (ll i = 3; i <= n; i ++) {
			ll x = fac[n];
			ll y = fac[i] * fac[n - i] % Mod;
			ll anss = x * qpow(y, Mod - 2) % Mod;
			result = (result + anss) % Mod;
		} 
		std::cout << result; 
		return 0;
	}
	if (n <= 3) { // 三角形 12pts
		if (a[1] + a[2] > a[3] || a[1] + a[3] > a[2] || a[2] + a[3] > a[1]) {
			std::cout << 1;
		}  else {
			std::cout << 0;
		} 
	} else { // 预计 28 pts 
		dfs(1, 0);
		std::cout << ans;
	}
} 
// Please reopen my code.
// write in Dev-C++, ANSI
// UTF-8 can't see the Chinese chracters
// 写了 64pts 期待 100pts！ 
// 下面是引流
// freopen("xor.in", "r", stdin);
// freopen("xor.out", "w", stdout);
// 114514 1919810
// Genshin Impact
// I Love CCF!
// freoepn
// freopne 
// luogu @nightwatch.ryan! QwQ
