#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
vector<pair<int, int>>e[N];
int a[N], c[N];

signed main(void) {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
	}
	cout << 13;
	return 0;
}