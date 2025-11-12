#include <bits/stdc++.h>
using namespace std;
int a[1005], z, myz = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, l;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int ans = a[1];
	sort(a + 1, a + 1 + n *m);
	for (int i = 1; i <= (n * m) / 2; i++) {
		swap(a[i], a[n *m - z]);
		z++;
	}
	for (int i = 1; i <= n * m; i++) {
		myz++;
		if (i % n == 1  && myz % n == 0) {
			for (int j = 1; j <= m / 2; j++) {
				int s = 0;
				swap(a[i + s], a[i + m - 1 - s]);
				s++;
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (ans == a[i]) {
			l = i;
		}
	}
	if (l % m == 0) {
		cout << (l / n) + (l % n) << " " << l % m + m ;
	} else
		cout << (l / n) + (l % n) << " " << l % m ;
	return 0;
}