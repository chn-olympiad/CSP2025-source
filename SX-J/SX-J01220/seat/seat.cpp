#include <bits/stdc++.h>

using namespace std;

int m, n;
int ans, x, mid;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> mid;
	ans = 1;
	for (int i = 2; i <= n * m; i++) {
		cin >> x;
		if (x > mid) {
			ans++;
		}
	}
	if (ans % n == 0) {
		if ((ans / n) % 2 == 0) {
			cout << ans / n << " " << 1 << endl;
		} else {
			cout << ans / n << " " << n << endl;
		}
	} else {
		if ((ans / n + 1) % 2 == 0) {
			cout << (ans / n) + 1 << " " << n - (ans % n) + 1 << endl;
		} else {
			cout << (ans / n) + 1 << " " << ans % n << endl;
		}
	}
	return 0;
}
