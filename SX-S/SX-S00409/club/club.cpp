#include <bits/stdc++.h>
using namespace std;
int t, n, sum;
int a[50005];
int b[50005];
int c[50005];
int x[50005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		if (n == 2) {
			x[1] = a[0] + b[1];
			x[2] = a[0] + c[1];
			x[3] = b[0] + a[1];
			x[4] = b[0] + c[1];
			x[5] = c[0] + a[1];
			x[6] = c[0] + b[1];
			for (int i = 0; i < 6; i++) {
				if (x[0] < x[i])
					x[0] = x[i];
			}
			cout << x[0] << " ";
		} else {
			for (int i = 0; i < n; i++) {
				if (a[i] > b[i]) {
					if (a[i] > c[i]) {
						sum += a[i];
					} else {
						if (b[i] > c[i]) {
							sum += b[i];
						} else {
							sum += c[i];
						}
					}
				} else if (a[i] > c[i]) {
					if (a[i] > b[i]) {
						sum += a[i];
					} else {
						if (c[i] > b[i]) {
							sum += c[i];
						} else {
							sum += b[i];
						}
					}
				} else if (b[i] > c[i]) {
					if (b[i] > a[i]) {
						sum += b[i];
					} else {
						if (c[i] > a[i]) {
							sum += c[i];
						} else {
							sum += a[i];
						}
					}
				}
			}
			cout << sum<<"¡¡";
		}
	}
	return 0;
}
