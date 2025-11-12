#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u[10005], v[10005], w[1e9];
int c1[15], c2[15][10005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= k; i++)
	{
		cin >> c1[i];
		for (int j = 1; j <= n; j++)
			cin >> c2[i][j];
	}
	return 0;
}
