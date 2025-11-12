#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int c[1000], n, m, o, b, s[1000], d, tt;

int main() {
	cin >> n >> m;
	tt = m;
	for (int i = 1; i <= n * m; i++) {
		cin >> c[i];
		if (i == 1) {
			d = c[i];
		}
	}
	int Max = -1;
	int sv = 0;
	for (int i = 0; i < n * m; i++) {
		Max = -1;
		for (int j = 1; j <= n * m; j++) {
			if (Max < c[j]) {
				Max = c[j];
				sv = j;
			}
		}
		c[sv] = -2;
		s[i] = Max;
	}
	int u = 0;
	o = 0;
	b = n;
	for (int x = 0; x < m; x++) {

		if (((x + 2) / 2) != 0) {
			for (int j = n; j <= 1; j--) {
				a[x][j] = s[u];
				cout << 1233333333333;
				cout << s[u] << " +";
				u = u + 1;
			}
		} else {
			for (int j = 1; j <= n; j++) {
				a[x][j] = s[u];
				cout << 85587576583333333;
				cout << s[u] << " +";
				u = u + 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == d) {
				cout << i + 1 << " " << n;
			}
		}
	}
	return 0;
}
