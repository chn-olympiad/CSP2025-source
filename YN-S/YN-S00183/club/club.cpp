#include <bits/stdc++.h>

using namespace std;

const int ll = 1e5 + 5;
int t, st, a[ll][4], b[4], c[ll][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int q = 1; q <= t; q++) {
		int n = 0, sum = 0, st = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for (int i = 1; i <= n; i++) {
			st = 0;
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] == max(a[i][1], max(a[i][2], a[i][3]))) {
					for (int f = 1; f <= n; f++) {
						if (a[f][j] > a[i][j] && a[i][j] != 0) {
							for (int e = 1; e <= 3; e++) {
								if (a[i][e] + a[f][j] > a[f][e] + a[i][j] && e != j && i != f) {
									st++;
									break;
								}
							}
						}
						if (a[f][j] == a[i][j] && a[f][j] != 0) {
							for (int e = 1; e <= 3; e++) {
								if (a[i][e] + a[f][j] > a[f][e] + a[i][j]) {
									st++;
								}
							}
						}
					}
					if (st < n / 2) {
						b[j] += a[i][j];
						break;
						st = 0;
					} else {
						a[i][j] = 0;
						st = 0;
					}
				}
			}
		}
		cout << b[1] + b[2] + b[3] << endl;
		for (int i = 1; i <= 3; i++) {
			b[i] = 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}