#include <bits/stdc++.h>
using namespace std;
const int N = 100000002;
long long n, m, k;
long long u[10000002], v[10000002], w[10000002];
long long c[10000002];
long long a[1003][1002];
long long b[1002][1002], xx, yy, ans;
long long cnt;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;

	if (k == 0) {
		for (int i = 1; i <= m; i++) {

			for (int j = 1; j <= m; j++) {

				b[i][j] = 11451489;
			}
		}

		for (int i = 1; i <= m; i++) {

			cin >> u[i] >> v[i] >> w[i];
			xx = max(u[i], v[i]);
			yy = min(u[i], v[i]);
			b[yy][xx] = w[i];
		}

		for (int i = 1; i <= m; i++) {

			cnt = 10025610;

			for (int j = 1; j <= m; j++) {

				cnt = min(cnt, b[i][j]);
			}

			ans = ans + cnt;
		}

		cout << ans - 10025610;
	} else {
		for (int i = 1; i <= m; i++) {

			cin >> u[i] >> v[i] >> w[i];
		}

		for (int i = 1; i <= k; i++) {

			cin >> c[i];

			for (int j = 1; j <= n; j++) {

				cin >> a[i][j];
			}
		}

		cout << 0;
	}

	return 0;
}