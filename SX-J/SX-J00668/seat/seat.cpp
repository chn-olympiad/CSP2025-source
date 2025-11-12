#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[15][15];
ll b[105];
ll k;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cin >> k;
		cout << "1 1";
		return 0;
	} else if (n == 2 && m == 2) {
		for (ll i = 1; i <= 4; i++)
			cin >> b[i];
		ll cnt = b[1];
		sort(b + 1, b + 5, cmp);
		for (ll i = 1; i <= 4; i++) {
			if (b[i] == cnt) {
				if (i == 1)
					cout << "1 1";
				if (i == 2)
					cout << "1 2";
				if (i == 3)
					cout << "2 1";
				if (i == 4)
					cout << "2 2";
				return 0;
			}
		}
	} else if (n == 1 && m <= 10) {
		for (ll i = 1; i <= n * m; i++)
			cin >> b[i];
		ll cnt1 = b[1];
		sort(b + 1, b + n *m, cmp);
		for (ll i = 1; i <= n * m; i++) {
			if (b[i] == cnt1) {
				cout << "1" << ' ' << i;

				return 0;
			}
		}
	} else if (n == 10 && m <= 1) {
		for (ll i = 1; i <= n * m; i++)
			cin >> b[i];
		ll cnt2 = b[1];
		sort(b + 1, b + n *m, cmp);
		for (ll i = 1; i <= n * m; i++) {
			if (b[i] == cnt2) {
				cout << i << ' ' << "1";
				return 0;
			}
		}
	} else if (n == 2 && m <= 10) {
		for (ll i = 1; i <= n * m; i++)
			cin >> b[i];
		ll cnt3 = b[1];
		sort(b + 1, b + n *m, cmp);
		for (ll i = 1; i <= n * m; i++) {
			if (b[i] == cnt3) {
				if (i % 2 == 1) {
					cout << i / 2 + 1 << ' ' << "1";
					return 0;
				} else {
					cout << i / 2 << ' ' << "2";
					return 0;
				}
			}
		}
	} else if (n <= 10 && m == 2) {
		for (ll i = 1; i <= n * m; i++)
			cin >> b[i];
		ll cnt4 = b[1];
		sort(b + 1, b + n *m, cmp);
		for (ll i = 1; i <= n * m; i++) {
			if (b[i] == cnt4) {
				if (i / m == 1) {
					cout << "1" << ' ' << m - (i % m);
					return 0;
				} else {
					cout << "2" << ' ' << n - (i % m);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
