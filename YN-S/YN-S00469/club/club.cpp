#include <bits/stdc++.h>
using namespace std;

int main() {
	long long b[1001][101], c[101];
	long long t, a[1001], f[101];
	long long n, o, w, h;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		o = 0;
		w = 0;
		h = 0;
		a[i] = 0;
		f[i] = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 3; k++) {
				cin >> b[j][k];
			}
		}
		for (int j = 1; j <= n; j++) {
			if (b[j][1] > b[j][2] && b[j][1] > b[j][3] && o < (n / 2)) {
				o++;
				a[i] += b[j][1];
			} else if (b[j][2] > b[j][1] && b[j][2] > b[j][3] && w < (n / 2 )) {
				w++;

				a[i] += b[j][2];
			} else if (b[j][3] > b[j][2] && b[j][3] > b[j][1] && h < (n / 2)) {
				h++;

				a[i] += b[j][3];
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 3; k++) {
				for (int l = 1; l <= n; l++) {
					for (int m = 1; m <= 3; m++) {
						if (j != l) {

							if (k == 1 && o < (n / 2)) {
								f[i] = max(f[i], b[j][k] + b[l][m]);

							} else if (k == 2 && w < (n / 2)) {
								f[i] = max(f[i], b[j][k] + b[l][m]);
							}
						} else if (k == 3 && h < (n / 2)) {
							f[i] = max(f[i], b[j][k] + b[l][m]);
						}
						if (f[i] == b[j][k] + b[l][m] && k == 1)
							o++;
						else if (f[i] == b[j][k] + b[l][m] && k == 2)
							w++;
						else if (f[i] == b[j][k] + b[l][m] && k == 3)
							h++;

					}
				}
			}
		}
		f[i] = max(f[i], a[i]);
	}


	for (int i = 1; i <= t; i++) {
		cout << f[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}