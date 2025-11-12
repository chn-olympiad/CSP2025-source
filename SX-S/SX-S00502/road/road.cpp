#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5+10, mod = 998244353;
ll n, m, k, ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		ans += w;
	}
	for (ll i = 1; i <= k; i++) {
		ll nn, x;
		cin >> nn;
		for (ll i = 1; i <= n; i++)
			cin >> x;
	}
	cout << ans;
	return 0;
}