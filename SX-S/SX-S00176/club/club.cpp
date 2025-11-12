#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int g = 0; g < t; g++) {
		int n;
		cin >> n;
		int a[4][n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
		}
		if (n == 2) {
			int mx = -1;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (j != i)
						mx = max(mx, a[i][1] + a[j][2]);
				}
			}
			cout << mx << endl;
		} else if (n == 4) {
			int mx = -1;
			int c[4];
			for (int i = 0; i < 4; i++) {
				c[i] = 0;
			}
			for (int i = 1; i <= 3; i++) {
				c[i]++;
				for (int j = 1; j <= 3; j++) {
					c[j]++;
					for (int k = 1; k <= 3; k++) {
						if (c[k] < 2) {
							c[k]++;
							for (int l = 1; l <= 3; l++) {
								if (c[l] < 2) {
									c[l]++;
									mx = max(mx, a[i][1] + a[j][2] + a[k][3] + a[l][4]);
									c[l]--;
								}
							}
							c[k]--;
						}

					}
					c[j]--;
				}
				c[i]--;
			}
			cout << mx << endl;
		} else {
			sort(a[1] + 1, a[1] + n + 1);
			int c = 0;
			for (int i = 1; i <= n / 2; i++) {
				c += a[1][i];
			}
			cout << c << endl;
		}
	}
	return 0;
}
