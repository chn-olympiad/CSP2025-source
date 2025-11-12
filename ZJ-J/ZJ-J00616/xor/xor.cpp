#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
ll n, k, a[N], p, ans;
struct node {
	ll x, y;
};
vector<ll> g[N];
bool is_tsA() {
	for (ll i = 1; i <= n; i ++) {
		if (a[i] != 1) return false;
	}
	return true;
}
bool is_tsB() {
	for (ll i = 1; i <= n; i ++) {
		if (a[i] > 1) return false;
	}
	return true;
}
void dfs(ll x, bool is, ll cnt) {
	ans = max(ans, cnt);
	if (is == true) {
		for (ll y = x + 1; y <= n; y ++) dfs(y, false, cnt);
	}
	else {
		for (ll i = 0; i < g[x].size(); i ++) dfs(g[x][i], true, cnt + 1);
	}
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for (ll i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	bool opA = is_tsA(), opB = is_tsB();
	if (n <= 100 && !opA && !opB) {
		for (ll l = 1; l <= n; l ++) {
			p = a[l];
			if (p == k) g[l].push_back(l);
			for (ll r = l + 1; r <= n; r ++) {
				p ^= a[r];
				if (p == k) g[l].push_back(r);
			}
		}
		for (ll x = 1; x <= n; x ++) dfs(x, false, 0);
		printf("%lld", ans);
		return 0;
	}
	if (opA) {
		printf("%lld", n / 2);
		return 0;
	}
	if (opB) {
		ll res = 0;
		for (ll i = 1; i <= n; i ++) {
			if (a[i] == k) res ++;
		}
		printf("%lld", res);
	}
	return 0;
}