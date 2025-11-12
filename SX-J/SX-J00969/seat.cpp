#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int r, s[1010];
int n, m;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			r = a[1][1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (r > a[i][j]) {
				r = a[1][1 + 1];
			}
			if (r <= a[i][j]) {
				cout << a[i][j];
				break;

			}
		}
	}
	return 0;
}