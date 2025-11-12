#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
const ll mod = 998244353;
int n;
int a[5010];
ll ans = 0;
bool can(bool p[]) {
	int sum = 0, maxn = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i]) {
			sum += a[i];
			maxn = max(maxn, a[i]);
		}
	}
//	cout << sum << " " << maxn << "\n";
	if (sum > maxn * 2) {
		return 1;
	}
	return 0;
}
void dfs(int k, bool p[]) {
	if (k == n + 1) {
		ans += can(p);
		ans %= mod;
		return;
	}
	p[k] = 0;
	dfs(k + 1, p);
	p[k] = 1;
	dfs(k + 1, p);
}
ll qpow(ll n) {
	if (n == 0) return 1;
	if (n == 1) return 2;
	if (n % 2 == 0) {
		ll t = qpow(n / 2) % mod;
		return t * t % mod;
	} else {
		ll t = qpow(n / 2) % mod;
		return t * t % mod * 2;
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1) {
			flag = 0;
		}
	}
	if (flag) {
		cout << ((qpow(n) - 1 - n - (n * (n - 1) / 2) + mod) % mod);
		return 0;
	}
	bool p[5010] = {};
	dfs(1, p);
	cout << ans;
	return 0;
}
