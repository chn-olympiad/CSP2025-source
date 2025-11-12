#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 15;
int n, m;
int a[N * N];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int k = a[1];
	sort(a + 1, a + 1 + n *m, greater<int>());
	int t;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == k) {
			t = i;
			break;
		}
	}
	int kk = t % (2 * n);
	if (!kk) {
		kk = 2 * n;
	}
	int ans = (t + n - 1) / n;
	if (kk <= n) {
		cout << ans << ' ' << kk;
	} else {
		kk -= n;
		cout << ans << ' ' << n - kk + 1;
	}
	return 0;
}
