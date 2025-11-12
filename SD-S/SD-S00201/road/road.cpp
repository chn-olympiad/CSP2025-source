#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10; 
int n, m, k;
vector<pair<int, int>> g[N];
int c[20];
int a[20][N];
int d[N];

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	int sum = 0;
	for (int i = 1; i <= m; i ++ ) {
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		sum += w;
	}
	for (int i = 1; i <= k; i ++ ) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++ ) cin >> a[i][j];
	}
	cout << sum << endl;
	return 0;
}

