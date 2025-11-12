#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x, xx, tt;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			x = a[i];
		}
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			xx = i;
		}
//		cout << a[i] << " ";
	}
//	cout << xx;
	int t = (n *m) % xx + 1;
	cout << t << " ";
	tt = (t - 1) * m + 1;
//	cout << tt << "*";
	if (t % 2 == 0) {
		for (int i = m; i >= 1; i--) {
			for (int j = tt; j <= t * m; j++) {
				if (xx == j) {
					cout << i << " ";
					return 0;
				}
			}
		}
	} else {
		if (t == 1) {
			cout << tt + 1;
		} else {
			for (int i = 1; i <= m; i++) {
				for (int j = tt; j <= t * m; j++) {
					if (j == xx) {
						cout << i << " ";
						return 0;
					}
				}
			}
		}
	}
	return 0;
}