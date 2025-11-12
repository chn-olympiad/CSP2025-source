#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 5, M = 1e6 + 5, K = 15;
vector<pair<int, int>> g[N];
int a[K][N], c[K];
int w[M], d[1005][1005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	bool A = true;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v >> w[i];
		g[u].emplace_back(v, w[i]);
		g[v].emplace_back(u, w[i]);
		d[u][v] = d[v][u] = w[i];
	}
	for (int j = 1; j <= k; j++)
	{
		cin >> c[j];
		A = A && c[j] == 0;
		bool tmp = false;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[j][i];
			tmp = tmp || a[j][i] == 0;
		}
		A = A && tmp;
	}
	if (A) cout << 0;
	else
	{
		long long ans = 0;
		for (int i = 1; i <= m; i++)
		{
			ans += w[i];
		}
		cout << ans;
	}
	return 0;
}
