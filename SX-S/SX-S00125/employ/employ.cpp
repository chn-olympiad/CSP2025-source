#include <bits/stdc++.h>
#define ll int
using namespace std;
ll t, n, m,   a[525], ans, f[505][505], h;
string k;
priority_queue<ll> c;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cout << a[i];
		if (a[i] != 0) {
			c.push(-a[i]);
		} else {
			t++;
		}
		f[i][0] = 1;
	}
	ans = 1;

	while (c.empty()) {
		h++;
		ll x = min(-c.top(), t);
		for (int i = 1; i <= x; i++) {
			f[h][i] = f[h - 1][t - i] * i;
			f[h][i] &= 998244353;
			ans += f[h][i];
			ans &= 998244353;
		}
		c.pop();
	}
	cout << ans;
}