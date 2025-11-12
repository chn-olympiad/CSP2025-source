#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("club1.in", "r", stdin);
	freopen("club.out", "w", stdout);

	long long t;
	cin >> t;
	for (long long i = 0; i < t; i++) {
		long long n, x[100001], y[100001], z[100001];
		long long SUM = 0;
		int sumx = 0, sumy = 0, sumz = 0;
		cin >> n;
		for (long long j = 0; j < n; j++) {
			cin >> x[j] >> y[j] >> z[j];
			sort(x, x + n);
			sort(y, y + n);
			sort(z, z + n);
			for (long long k = n - 1; k >= 0; k--) {
				if (x[k] > y[k] && x[k] > z[k] && sumx < (n / 2)) {
					SUM += x[k];
					sumx += 1;
				}
				if (x[k] > y[k] && x[k] > z[k] && y[k] > z[k] && sumx >= (n / 2) && sumy < (n / 2)) {
					SUM += y[k];
					sumy += 1;
				}
				if (x[k] > y[k] && x[k] > z[k] && z[k] > y[k] && sumx >= (n / 2) && sumz < (n / 2)) {
					SUM += z[k];
					sumz += 1;
				}
				if (y[k] > x[k] && y[k] > z[k] && sumy < (n / 2)) {
					SUM += y[k];
					sumy += 1;
				}
				if (y[k] > x[k] && y[k] > z[k] && x[k] > z[k] && sumy >= (n / 2) && sumx < (n / 2)) {
					SUM += x[k];
					sumx += 1;
				}
				if (y[k] > x[k] && y[k] > z[k] && z[k] > x[k] && sumy >= (n / 2) && sumz < (n / 2)) {
					SUM += z[k];
					sumz += 1;
				}
				if (z[k] > y[k] && z[k] > x[k] && sumz < (n / 2)) {
					SUM += z[k];
					sumz += 1;
				}
				if (z[k] > y[k] && z[k] > x[k] && y[k] > x[k] && sumz >= (n / 2) && sumy < (n / 2)) {
					SUM += y[k];
					sumy += 1;
				}
				if (z[k] > y[k] && z[k] > x[k] && x[k] > y[k] && sumz >= (n / 2) && sumx < (n / 2)) {
					SUM += x[k];
					sumx += 1;
				}
			}
			cout << SUM;
		}
	}
	return 0;
}