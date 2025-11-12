#include <bits/stdc++.h>
using namespace std;
const int N = -1145141919;
int a[100005][3];

int dx(int d, int x) {
	return d > x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;

	while (t--) {
		int n, res = N, last = n % 2;
		bool lz = true;
		cin >> n;
		int xn = n / 2;

		for (int i = 0; i < n; i++) {

			cin >> a[i][0] >> a[i][1] >> a[i][2];

			if (a[i][1] != 0) {
				lz = false;
			}
		}

		if (lz == true) {
			int lres = 0;
			int alz[100005];

			for (int i = 0; i < n; i++) {

				alz[i] = a[i][0];
			}

			sort(alz, alz + n, dx);

			for (int i = 0; i < xn; i++) {

				//cout << alz[i] << " ";
				lres += alz[i];
			}

			cout << lres << endl;
			continue;

		}

		vector<vector<vector<int> > > tmd(2, vector<vector<int> >(xn + 1, vector<int>(xn + 1, N)));
		tmd[0][0][0] = 0;

		for (int i = 0; i < n; i++) {

			int c = i % 2;
			int xt = (i + 1) % 2;

			for (int j = 0; j <= xn; j++) {

				for (int k = 0; k <= xn; k++) {

					tmd[xt][j][k] = N;
				}
			}

			for (int j = 0; j <= xn; j++) {

				for (int k = 0; k <= xn; k++) {

					if (tmd[c][j][k] == N) {
						continue;
					}

					int ls = i - j - k;

					if (ls < 0 || ls > xn) {
						continue;
					}

					if (j + 1 <= xn) {
						tmd[xt][j + 1][k] = max(tmd[xt][j + 1][k], tmd[c][j][k] + a[i][0]);
					}

					if (k + 1 <= xn) {
						tmd[xt][j][k + 1] = max(tmd[xt][j][k + 1], tmd[c][j][k] + a[i][1]);
					}

					if (ls + 1 <= xn) {
						tmd[xt][j][k] = max(tmd[xt][j][k], tmd[c][j][k] + a[i][2]);
					}
				}
			}
		}

		for (int j = 0; j <= xn; j++) {

			for (int k = 0; k <= xn; k++) {

				int ls = n - j - k;

				if (ls >= 0 && ls <= xn) {
					res = max(res, tmd[last][j][k]);
				}
			}
		}

		cout << res << endl;
	}

	return 0;
}