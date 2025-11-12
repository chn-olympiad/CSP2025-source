#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5 + 7;
ll t;
ll n;
struct de {
	ll a, b, c;
}cl[N];
ll u[N], v[N], w[N];



int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		ll la = 0, lb = 0, lc = 0;
		for (ll i = 1; i <= n; ++i) {
			cin >> u[i] >> v[i] >> w[i];
			cl[i].a = u[i];
			cl[i].b = v[i];
			cl[i].c = w[i];
			la = la + u[i];
			lb = lb + v[i];
			lc = lc + w[i];
		}
		if (!lb && !lc) {
			sort(u + 1, u + n + 1);
			ll ans = 0;
			for (ll i = n; i > n / 2; --i) {
				ans = ans + u[i];
			}
			cout << ans << '\n';
			continue;
		}
		if (!la && !lc) {
			sort(v + 1, v + n + 1);
			ll ans = 0;
			for (ll i = n; i > n / 2; --i) {
				ans = ans + v[i];
			}
			cout << ans << '\n';
			continue;
		}
		if (!la && !lb) {
			sort(w + 1, w + n + 1);
			ll ans = 0;
			for (ll i = n; i > n / 2; --i) {
				ans = ans + w[i];
			}
			cout << ans << '\n';
			continue;
		}
		if (n == 2) {
			cout << max({u[1] + v[2], u[1] + w[2], v[1] + u[2], v[1] + w[2], w[1] + u[2], w[1] + v[2]}) << '\n';
			continue;
		}
	}
	
	return 0;
}