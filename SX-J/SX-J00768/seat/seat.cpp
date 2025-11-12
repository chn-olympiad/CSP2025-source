#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[20][20];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int c = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (100 - m + 1 - j + 1  <= a[1][1])
				c = j;
			break;
		}
	}
	cout << c << ' ';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (100 - m + 1 - j + 1  <= a[1][1])
				r = i;
			break;
		}
	}
	cout << r;
	return 0;
}
