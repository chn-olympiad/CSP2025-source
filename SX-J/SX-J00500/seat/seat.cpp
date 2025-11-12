#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m + 3];
	int sum = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	sum = a[1];
	sort(a + 1, a + 1 + n *m);
	int t = 0;
	int s = 0;
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == sum) {
			t = n * m - i + 1;
			s = t / n;
			if (n == 1) {
				cout << t << " " << 1;
				break;
			}
			if (s == 0) {
				cout << 1 << " " << t;
				break;
			} else if (s >= 1 && (t - 1) % n == 0 && t % n != 0) {
				if (s % 2 == 0) {
					cout << s + 1 << " " << 1;
					break;
				}
				if (s % 2 != 0) {
					cout << s + 1 << " " << n;
				}
			} else if (s >= 1 && (t - 1) % n != 0 && t % n == 0) {

				if (s % 2 != 0) {
					cout << s << " " << n;
					break;
				}
				if (s % 2 == 0) {
					cout << s << " " << 1;
					break;

				}

			} else {
				if ((s + 1) % 2 != 0) {
					for (int j = 1; j <= n; j++) {
						if ((t + j) % n == 0) {
							cout << s + 1 << " " << n - j;
							break;
						}
					}
				}
				if ((s + 1) % 2 == 0) {
					for (int k = 1; k <= n; k++) {
						if ((t + k) % n == 0) {
							cout << s + 1 << " " << k + 1;
							break;
						}
					}
				}
			}
		}
	}

	return 0;
}
