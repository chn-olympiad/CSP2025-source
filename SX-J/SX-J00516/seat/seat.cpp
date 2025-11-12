#include <bits/stdc++.h>
using namespace std;
bool b[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a, k, ant = 0, c, r;
	cin >> n >> m;
	cin >> a;
	k = a;
	for (int i = 2; i <= n * m; i++) {
		cin >> a;
		b[a] = 1;
	}
	for (int i = 100; i > 0; i--) {
		if (b[i]) {
			ant++;
		}
		if (i == k) {
			ant++;
			break;
		}
	}
	if (ant % n == 0) {
		if ((ant / n) % 2 == 1) {
			cout << ant / m << " " << n;
			return 0;
		}
		if ((ant / n) % 2 == 0) {
			cout << ant / m << " " << 1;
			return 0;
		}

	} else {
		c = ant / n + 1;
		r = ant % n;
		if (c % 2 == 1) {
			cout << c << " " << r;
			return 0;

		}
		if (c % 2 == 0) {
			cout << c << " " << n - r + 1;
			return 0;

		}
	}

	return 0;
}