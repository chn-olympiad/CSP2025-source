#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
pair<int, int>l[10000][10000];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, u, v, w, sum = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		l[u][v] = {w, 1};
	}
	for (int i = 1; i <= (n + 1) * k; i++) {
		cin >> u;
	}
	for (int i = 1; i <= n; i++) {
		if (l[i - 1][i].second)
			sum += l[i - 1][i].first;
		if (l[i][1].second)
			sum += l[i][1].first;
	}
	cout << sum;
	return 0;
}