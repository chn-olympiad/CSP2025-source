#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	int n, m, x;
	int a[20][20];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (i == 1 && j == 1) {
				x = a[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

		}
	}
	return 0;
}