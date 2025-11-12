#include <bits/stdc++.h>
using namespace std;
int t = 0;
int n, a[100005][4], x[100005], y[100005], z[100005], xx = 0, yy = 0, zz = 0, k = 0, p = 0, l = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		xx = 0;
		yy = 0;
		zz = 0;
		k = 0;
		p = 0;
		l = 0;
		cin >> n;

		for (int i = 1; i <= n; i++) {

			cin >> a[i][1] >> a[i][2] >> a[i][3];

			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				x[k] = i;
				k++;
				xx += a[i][1];
			}

			if (a[i][2] > a[i][1] && a[i][2] >= a[i][3]) {
				y[p] = i;
				p++;
				yy += a[i][2];
			}

			if (a[i][3] > a[i][1] && a[i][3] > a[i][2]) {
				z[l] = i;
				l++;
				zz += a[i][3];
			}
		}

		if (k <= n / 2 && p <= n / 2 && l <= n / 2) {
			cout << xx + yy + zz << endl;
			continue;
		} else {
			int mx, dz;

			if (k > n / 2) {
				for (int j = 0; j <= k - n / 2 - 1; j++) {

					mx = 0x3f3f3f3f;
					dz = 0;

					for (int i = 0; i < k; i++) {

						if (mx > a[x[i]][1] - a[x[i]][2] || mx > a[x[i]][1] - a[x[i]][3]) {
							mx = min(a[x[i]][1] - a[x[i]][2], a[x[i]][1] - a[x[i]][3]);
							dz == i;
						}
					}

					xx -= mx;
				}
			}

			if (p > n / 2) {
				for (int j = 0; j <= p - n / 2 - 1; j++) {

					mx = 0x3f3f3f3f;
					dz = 0;

					for (int i = 0; i < p; i++) {

						if (mx > a[y[i]][2] - a[y[i]][3] || mx > a[y[i]][2] - a[y[i]][1]) {
							mx = min(a[y[i]][2] - a[y[i]][1], a[y[i]][2] - a[y[i]][3]);
							dz == i;
						}
					}

					yy -= mx;
				}
			}

			if (l > n / 2) {
				for (int j = 0; j <= l - n / 2 - 1; j++) {

					mx = 0;
					dz = 0;

					for (int i = 0; i < l; i++) {

						if (mx > a[z[i]][3] - a[z[i]][2] && mx > a[z[i]][3] - a[z[i]][1]) {
							mx = min(a[z[i]][3] - a[z[i]][1], a[z[i]][3] - a[z[i]][2]);
							dz == i;
						}
					}

					zz -= mx;
				}
			}

			cout << xx + yy + zz << endl;
		}
	}

	return 0;
}