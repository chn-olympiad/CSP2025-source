#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[1000010], v[1000010], w[1000010], c[15], r[15][10010];
long long sum;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> r[i][j];
		}
	}
	sort(w + 1, w + m + 1);
	for (int i = 1; i <= m - 1; i++) {
		sum += w[i];
	}
	cout << sum;
	return 0;
}