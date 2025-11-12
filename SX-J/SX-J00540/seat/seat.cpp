#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 110;
ll n, m, a[M], r, t;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			r = a[i];
		}
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (ll i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			t = i;
		}
	}
	if (t <= n) {
		cout << 1 << " " << t;
		return 0;
	}
	if (t == 2 * n) {
		cout << 2 << " " << 1;
		return 0;
	}
	if (t == n + 1) {
		cout << 2 << " " << n;
		return 0;
	}
	if (t == 2 * n + 1) {
		cout << 3 << " " << 1;
		return 0;
	}
	ll cnt = 1;
	for (ll i = 1;; i++) {
		if (t - n > 0) {
			t -= n;
			cnt++;
		} else {
			break;
		}
	}
	cout << cnt << " ";
	if (n == cnt) {
		cout << cnt;
		return 0;
	}
	if (cnt % 2 == 0) {
		cout << n - cnt + 1;
		return 0;
	} else {
		cout << t;
		return 0;
	}
	return 0;
}