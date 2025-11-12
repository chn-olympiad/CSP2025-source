#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[20000], t[20][10], r[2000010][5], flag[2000000], mi, sum;

int main() {
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> r[i][1] >> r[i][2] >> r[i][3];
	}
	for (int i = 0; i < k; i++) {
		cin >> t[i][0];
		for (int j = 0; j < n; j++) {
			cin >> t[i][j];
			r[n + 10 * i - 1][3] = t[i][j];
			r[n + 10 * i - 1][1] = n + i - 1;
			r[n + 10 * i - 1][2] = j;
			r[n + 10 * i - 1][0] = t[i][0];
		}
	}
	int q = n + k - 1;
	for (int i = 1; i <= n - 1 ; i++) {
		for (int j = i + 1; j <= n; j++, q++) {
			r[q][3] = r[n + 10 * i - 1][0] + r[n + 10 * j - 1][0];
			r[q][1] = i;
			r[q][2] = j;
			r[q][0] = r[n + 10 * i - 1][0];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int mi1 = 1e9;
		for (int j = 0; j < q; j++) {
			if (q >= n && r[q][3] + r[q][0] > 0) {
				mi1 = min(mi1, r[q][3] + r[q][0]);
			} else if (r[q][3] > 0) {
				mi1 = min(mi1, r[q][3]);
			}
		}
		mi += mi1;
	}
	if (mi > 0) {
		cout << mi;
	} else {
		int z = 0;
		for (int i = 0; i < n - 1; i++) {
			z += r[i][0];
		}
		cout << z;
	}
	return 0;
}
