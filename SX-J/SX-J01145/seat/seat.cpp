#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 110;
ll n, m, a[N], t, s, w, c;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (ll i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			s = i;
			break;
		}
	}
	if (s % n == 0 && s >= n) {
		w = s / n;
	} else {
		w = s / n + 1;
	}
	if (s % n == 0) {
		c = n;
	} else {
		c = s % n;
	}
	if (w % 2 == 0) {

		cout << w << " " << (n + 1 - c);
	} else {
		cout << w << " " << c;
	}
	return 0;
}