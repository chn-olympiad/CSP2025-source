#include <bits/stdc++.h>
using namespace std;
int n, m, cj[100], x, w, a, b, d = 1, pm = 1;

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	cin >> x;
	if (n == 1 && m == 1) {
		cout << "1 1";
		return 0;
	}
	for (int i = 1; i < m * n; i++) {
		cin >> cj[i];
	}
	cj[0] = x;
//	for (int i = 1; i < m * n  ; i++) {
//		for (int j = 1; j < m * n - i  ; j++) {
//
//			if (cj[i] > cj[i + 1]) {
//				swap(cj[i], cj[i + 1]);
//			}
//		}
//	}
	for (int i = 0; i < m * n; i++) {
		if (cj[i] > x) {
			pm++;
		}
	}

	for (int i = 0; i <= pm; i++) {

		if (d == 1) {
			a++;
			if (a > n - 1) {
				a--;
				d = 2;

			}
		} else if (d == 2) {
			b++;
			if (a == n - 1) {
				d = 1;
			} else {
				d = 3;
			}

		} else if (d == 3) {
			a--;
			if (a < 0) {
				a++;
				d = 2;

			}
		}
	}
	cout << a + 1 << ' ' << (pm + 2) / n;
	return 0;
}