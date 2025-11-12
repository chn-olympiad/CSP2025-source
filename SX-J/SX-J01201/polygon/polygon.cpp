#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll a[110], n, ans, sum[5010], c[5010];

bool cmp(ll x, ll y) {
	return x > y;
}

ll dg(ll l, ll k) {
	ll an = 0;
	for (ll i = l; i <= n; i++) {
		if (a[i] > k) {
			an += sum[n - i];
			an %= mod;
		} else {
			if (i == n)
				continue;
			an += dg(i + 1, k - a[i]);
			an %= mod;
		}
	}
	return an;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	sum[0] = 1;
	c[0] = 1;
	for (ll i = 1; i <= n; i++)
		c[i] = (c[i - 1] * i) % mod;
	for (ll i = 1; i <= n; i++) {
		sum[i] = (sum[i - 1] * 2) % mod;
	}
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (ll i = 1; i <= n - 2; i++) {
		ans += dg(i + 1, a[i]);
		ans %= mod;
	}
	cout << ans;
	return 0;
}