#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[20][20], b[110], k;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	for (ll i = 1; i <= m; i++) {
		if (m % 2 == 0) {
			for (ll j = n; j >= 1; j--) {
				a[i][j] = ++k;
			}
		} else {
			for (ll j = 1; j <= n; j++) {
				a[i][j] = ++k;
			}
		}
	}
	ll t = b[1];
	if (t == 100) {
		cout << 1 << " " << 1;
		return 0;
	}
	for (ll i = 1; i <= n * m; i++) {
		for (ll j = i; j <= n * m; j++) {
			if (b[i] < b[j]) {
				swap(b[i], b[j]);
			}
		}
	}
	if (m == 1) {
		for (ll i = n; i >= 1; i--) {
			if (b[i] == t) {
				cout << 1 << " " << n - i + 1;
			}
		}
	} else if (n == 1) {
		for (ll i = m; i >= 1; i--) {
			if (b[i] == t) {
				cout << m - i + 1 << " " << 1;
			}
		}
	} else {
		for (ll i = 1; i <= m; i++) {
			if (m % 2 == 0) {
				for (ll j = n; j >= 1; j--) {
					if (b[a[i][j]] == t) {
						cout << i << " " << j;
						return 0;
					}
				}
			} else {
				for (ll j = 1; j <= n; j++) {
					if (b[a[i][j]] == t) {
						cout << i << " " << j;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
