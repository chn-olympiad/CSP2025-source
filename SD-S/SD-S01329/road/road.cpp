#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 10005, M = 1000005;
int n, m, k, c[N], a[N][N], ans, b[N];
vector<pair<int, int> > e[N];
bool cmp(int a, int b) {
	return a > b;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].pb({v, w});
		b[i] = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		ans += b[i];
	}
	cout << ans;
	return 0;
}

