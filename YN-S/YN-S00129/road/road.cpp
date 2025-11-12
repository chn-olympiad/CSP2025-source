#include <bits/stdc++.h>
using namespace std;
int n, m, k, sum;
long long w[1000005], w1[1000005];
int u[10005], v[10005], a[15], c;
int mp[10005][10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {

		cin >> u[i] >> v[i] >> w[i];
		w1[i] = w[i];

	}

	for (int i = 1; i <= k; i++) {

		cin >> c;

		for (int j = 1; j <= n; j++) {

			cin >> a[j];
		}
	}

	sort(w1 + 1, w1 + m + 1);

	for (int i = 1; i <= m; i++) {

		int flag = 1;

		for (int k = 1; k <= n; k++) {

			if (mp[k][n] != 1) {
				flag = 0;
			}
		}

		if (flag) {
			cout << sum;
			return 0;
		}

		for (int j = 1; j <= m; j++) {

			if (w[j] == w1[i]) {
				mp[i][j] = 1;
				mp[j][i] = 1;
				sum = sum + w1[i];
				break;
			}
		}
	}

	return 0;
}