#include <bits/stdc++.h>
using namespace std;
long long n, m, k, u[100020], v[100020], w[100020], c[20], a[100020][20], minw = INT_MAX, zbw, sum, a1[100020], cnt;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		if (minw > w[i]) {
			minw = w[i];
			zbw = i;
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[j][i];
		}
	}
	while (1) {
		a1[u[zbw]] = 1;
		a1[v[zbw]] = 1;
		minw = INT_MAX;
		sum += w[zbw];
		w[zbw] = INT_MAX;
		int hhh = 0;
		for (int i = 1; i <= m; i++) {
			if (a1[i] == 0) {
				hhh = 1;
				break;
			}
		}
		if (hhh == 0)
			break;
		for (int i = 1; i <= m; i++) {
			if (minw > w[i]) {
				minw = w[i];
				zbw = i;
			}
		}
		if (cnt >= m) {
			cout << 0;
			return 0;
		}
	}
	cout << sum;
	return 0;
}
