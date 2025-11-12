#include <bits/stdc++.h>
using namespace std;
long long n, a[20020][5], m, b[2020], minn[2020], sum, minx = INT_MAX, qnm;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	while (n > 0) {
		n--;
		sum = 0;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			b[i] = 0;
			for (int j = 4; j <= 5; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][4] < a[i][j]) {
					a[i][4] = a[i][j];
					a[i][5] = j;
				}
			}
		}

		for (int i = 1; i <= m; i++) {
			b[a[i][5]]++;
			sum += a[i][4];
		}
		for (int hhh = 1; hhh <= m; hhh++) {
			int h = 0;
			for (int i = 1; i <= 3; i++) {
				if (b[i] > m / 2) {
					h = 1;
					while (b[i] > m / 2) {
						qnm = i;
						minx = INT_MAX;
						for (int j = 1; j <= m; j++) {
							minn[j] = INT_MAX;
							for (int s = 1; s <= 3; s++) {
								if (s == i) {
									continue;
								} else {
									if (minn[j] > a[j][i] - a[j][s]) {
										minn[j] = a[j][i] - a[j][s];
										qnm = s;
									}
								}
							}
							if (minx > minn[j] and minn[j] >= 0) {
								minx = minn[j];
							}
						}
						sum = sum - minx;
						b[i]--;
						b[qnm]++;
					}
				}

			}
			if (h == 0) {
				break;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
