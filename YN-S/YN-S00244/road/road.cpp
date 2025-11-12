#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e4 + 15;
int n, m, k;

int w[maxn][maxn] = {INT_MAX}, xz[maxn], jf[11][maxn];

signed main() {
	freopen("reolace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {

		int a, b, c;
		cin >> a >> b >> c;
		w[a][b] = w[b][a] = c;
	}

	for (int i = 1; i <= n; i++) {

	}

	for (int i = 1; i <= k; i++) {

		cin >> xz[i];

		for (int j = 1; j <= n; j++) {

			cin >> jf[i][j];

			for (int q = 1; q <= n; q++) {

				if (q == j) {
					continue;
				} else {
					w[q][j] = w[j][q] = min(w[q][j], jf[i][q] + jf[i][j] + xz[i]);
				}
			}
		}
	}

	int e = 0;

	for (int i = 1; i < n; i++) {

		e += w[i][i + 1];
	}

	cout << e;
	return 0;
}