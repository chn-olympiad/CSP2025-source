#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int a[N];

int main() {
	long long n, m, r, f;
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		if (r == a[i]) {
			f = n * m - i + 1;
			break;
		}
	}
	if (f % n == 0) {
		if ((f / n) % 2 == 1) {
			cout << f / n << " " << n;
		} else {
			cout << f / n << " " << 1;
		}
	} else {
		if ((f / n) % 2 == 1) {
			cout << f / n + 1 << " " << n - f % n + 1;
		} else {
			cout << f / n + 1 << " " << f % n;
		}
	}
	return 0;
}
