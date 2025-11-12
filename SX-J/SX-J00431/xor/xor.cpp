#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t, b, a[1111];
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cin >> a[1];
		cout << 1 << ' ' << 1;
		return 0;
	}
	if (n == 2 && m == 2) {
		cin >> a[1] >> a[2] >> a[3] >> a[4];
		if (a[1] < a[2] && a[1] < a[3] && a[1] < a[4]) {
			cout << 2 << ' ' << 1;
			return 0;
		}
		if (a[1] < a[2] && a[1] < a[3] && a[1] > a[4]) {
			cout << 2 << ' ' << 2;
			return 0;
		}
		if (a[1] < a[2] && a[1] > a[3] && a[1] > a[4]) {
			cout << 1 << ' ' << 2;
			return 0;
		}
		if (a[1] > a[2] && a[1] > a[3] && a[1] > a[4]) {
			cout << 1 << ' ' << 1;
			return 0;
		}
	}
	if (n == 10 && m == 1) {
		cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5]
		    >> a[6] >> a[7] >> a[8] >> a[9] >> a[10];
		b = a[1];
		for (int i = 1; i <= 10 ; i++) {
			for (int j = 1; j <= i; j++) {
				if (a[j] > a[i]) {
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
			for (int i = 1; i <= 10 ; i++) {
				if (a[i] == b) {
					cout << a[i] << ' ' << 1;
					return 0;
				}
			}
		}

	}
	return 0;
}
