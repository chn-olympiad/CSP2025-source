#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010], r;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			if (i % n == 0) {
				cout << i / n << " " << n;
				return 0;
			}
			int ans1 = ceil(1.0 * i / n);
			cout << ans1 << " ";
			if (ans1 % 2) {
				cout << i % n;
				return 0;
			} else {
				cout << n - i % n + 1;
				return 0;
			}
		}
	}
	return 0;
}
