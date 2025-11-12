#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[15000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ll n, m, l, h, sum;
	cin >> n >> m;
	sum = n * m;
	ll r, d;
	for (ll i = 1; i <= sum; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a, a + sum + 1);
	for (ll i = sum; i > 0; i--) {
		if (a[i] == r) {
			d = sum - i + 1;
		}
	}
	if (d % m != 0) {
		l = d / m + 1;
	} else {
		l = d / m;
	}
	d -= (l - 1) * m;
	if (l % 2 == 1) {
		h = d;
	} else {
		h = m - d + 1;
	}
	cout << l << " " << h;
	return 0;
}