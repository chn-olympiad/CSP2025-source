#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen('clud.in', 'r', stdin);
	freopen('clud.out', 'w', stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 2) {
			int a[2][3] = {};
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
					cin >> a[i][j];
				}
			}
			int maxn = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == j)
						continue;
					maxn = max(maxn, a[0][i] + a[1][j]);
				}
			}
			cout << maxn;
		}
		if (n == 4) {
			int a[5][4] = {};
			for (int i = 1; i <= 4; i++) {
				for (int j = 1; j <= 3; j++) {
					cin >> a[i][j];
				}
			}
			int maxn = 0;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3 && j != i; j++) {
					for (int k = 1; k <= 3 && k != i && k != j; k++) {
						for (int m = 1; m <= 3; m++) {
							maxn = max(maxn, a[i][1] + a[j][2] + a[k][3] + a[4][m]);
						}
					}
				}
			}
			for (int i = 2; i <= 4; i++) {
				for (int j = 2; j <= 4 && j != i; j++) {
					for (int k = 1; k <= 3 && k != i && k != j; k++) {
						for (int m = 1; m <= 3; m++) {
							maxn = max(maxn, a[i][1] + a[j][2] + a[k][3] + a[1][m]);
						}
					}
				}
			}
			for (int i = 1; i <= 4; i++) {
				for (int j = 1; j <= 4 && j != i && j != 2; j++) {
					for (int k = 1; k <= 4 && k != i && k != j && k != 2; k++) {
						for (int m = 1; m <= 3; m++) {
							maxn = max(maxn, a[i][1] + a[j][2] + a[k][3] + a[2][m]);
						}
					}
				}
			}
			cout << maxn;
		}
	}
	return 0;
}