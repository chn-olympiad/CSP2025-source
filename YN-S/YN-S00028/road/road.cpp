#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
int u[N], v[N], w[N], a[5005][5005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> a[i][j];
		}
	}
	sort(w + 1, w + m + 1);
	int minn = INT_MAX;
	for (int i = 1; i <= k; i++) {
		sort(a[i] + 2, a[i] + n + 1);
		if (a[i][1] + a[i][2] + a[i][3] < minn) {
			minn = a[i][1] + a[i][2] + a[i][3];
		}
	}
	cout << w[1] + w[2] + minn;
	return 0;
}