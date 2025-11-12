#include <bits/stdc++.h>
using namespace std;
long long cnt = 1, n, m, a, aa;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> aa;
	for (int i = 2; i <= n * m; i++) {
		cin >> a;
		if (a > aa)
			cnt++;
	}
	if (n == 1) {
		cout << cnt;
		return 0;
	}
	if (cnt % m == 0) {
		cout << cnt / m << " ";
	} else {
		cout << cnt / m + 1 << " ";
	}
	if (cnt % (2 * m + 1) == 0 ) {
		cout << 1;
	} else if (cnt % m == 0) {
		cout << m;
	} else if (cnt % (2 * m + 1) <= m) {
		cout << cnt % m + 1;
	} else {
		cout << m - (cnt % m) + 1;
	}
	return 0;
}
