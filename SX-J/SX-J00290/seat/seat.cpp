#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;

int a[300];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	int x = 1;
	for (int i = 2; i <= n * m; i ++) {
		if (a[i] > a[1])
			x ++;
	}
	int t = 1, k = 0;
	for (int i = 1, j = 1; ; i += t) {
		if (i == n + 1) {
			i = n;
			j ++;
			t *= -1;
		}
		if (i == 0) {
			i = 1;
			j ++;
			t *= -1;
		}
		k ++;
		if (k == x) {
			cout << j << ' ' << i << endl;
			break;
		}
	}
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
// AKCSP-J2025!!!
