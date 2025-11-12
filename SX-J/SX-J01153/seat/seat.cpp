#include <bits/stdc++.h>
#define ll int
using namespace std;
ll n, m, a[1000010], s[110][110];

bool cmp(ll c, ll d) {
	return c > d;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	ll t = 1, id = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	id = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (i % 2 == 1) {
				s[i][j] = a[t];
				if (a[t] == id) {
					cout << i << " " << j;
					return 0;
				}
			} else {
				s[i][n - j + 1] = a[t];
				if (a[t] == id) {
					cout << i << " " << n - j + 1;
					return 0;
				}
			}
			t++;
		}
	}
	return 0;
}
