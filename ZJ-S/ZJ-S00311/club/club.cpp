#include <bits/stdc++.h>
#define ll long long
const ll N = 1e5 + 5;
ll n, a[N], b[N], c[N], mx_vall = -1;
void dfs(ll step, ll A, ll B, ll C, ll tot) {
	if (step == n + 1) {
		mx_vall = std::max(mx_vall, tot);
		return;
	}
	// 1
	if (A < n / 2) dfs(step + 1, A + 1, B, C, tot + a[step]);
	if (B < n / 2) dfs(step + 1, A, B + 1, C, tot + b[step]);
	if (C < n / 2) dfs(step + 1, A, B + 1, C, tot + c[step]);
}
void solve() {
	std::cin >> n;
	bool xzA = 1;
	for (ll i = 1; i <= n; i ++) {
		std::cin >> a[i] >> b[i] >> c[i];
		if (!(b[i] == 0 && c[i] == 0)) xzA = 0;
	}
	if (xzA) {
		std::sort(a + 1, a + 1 + n, std::greater<ll>());
		ll tottot = 0;
		for (ll i = 1; i <= n / 2; i ++) {
			tottot += a[i];
		}
		std::cout << tottot << "\n";
		return;
	}
	mx_vall = -1;
	dfs(1, 0, 0, 0, 0);
	std::cout << mx_vall << "\n";
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll T; std::cin >> T;
	while (T --) solve();
}

// [13min] 20pts
// 且看 nightwatch.ryan 如何写部分分拿到 1= 
// [16:55] 117pts
