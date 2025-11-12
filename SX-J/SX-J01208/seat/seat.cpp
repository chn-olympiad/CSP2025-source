#include <bits/stdc++.h>
using namespace std;
int n, m, x, a, t = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a;
	for (int i = 1; i < n * m; i++) {
		cin >> x;
		if (x > a) {
			t++;
		}
	}
	if (t % n == 0) {
		if ((t / n) % 2 == 1) {
			cout << t / n << ' ' << n;
		} else {
			cout << t / n << ' ' << 1;
		}
	} else {
		if ((t / n + 1) % 2 == 1) {
			cout << t / n + 1 << ' ' << t % n;
		} else {
			cout << t / n + 1 << ' ' << n - t % n + 1;
		}
	}
	return 0;
}
