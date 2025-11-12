#include <cstdio>
#include <iostream>
using namespace std;
int n, m, a[180], t;

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	for (int i = 1; i <= n * m; i++) {
		for (int j = i - 1; j <= n * m; j++) {
			int p = 0;/*
			if (i == 1) {
				a[1] = max(a[1], a[j]);
			} else if (a[j] < a[i - 1]) {
				a[i] = max(a[i], a[j]);
			}*/
			for (int k = 1; k <= n * m; k++) {
				if (j > k && a[j] == a[k]) {
					p = 1;
				}
			}
			if (p != 1) {
				a[i] = max(a[i], a[j]);
			}
		}
		cout << a[i] << " ";
	}
	int g = 0;
	for (int i = n * m; i >= 1; i--) {
		if (t == a[i]) {
			g++;
			int g1 = 0;
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					g1++;
					if (g1 == g) {
						cout << endl << j << " " << k;
					}
				}
			}
			return 0;
		} else {
			g++;
		}
	}
	return 0;
}