#include <bits/stdc++.h>
using namespace std;

const long long mx = 11000;
vector<int>vec;
int n, m, k, r, u, v, p, ans;
int dis[mx][mx], vis[mx][mx];

void dfs(int x) {
	for (int q = 1; q <= n; ++q)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (dis[i][j] < dis[i][q] + dis[q][j]) {
					dis[i][j] = dis[i][q] + dis[q][j];
					dis[j][i] = dis[i][q] + dis[q][j];
				}

			}
	dfs(x + 1);
	for (auto v : vec[x]) {
		r = v;
		break;
	}
	for (auto v : vec[x]) {
		vis[x][v] = 1;
		vis[v][x] = 1;
		if (dis[x][v] + dis[x][r] < dis[x][r]) {
			int t = min(dis[x][v], dis[x][r]);
			ans += t;
		}

	}
}

int main() {
	memset(dis, 0, sizeof dis);
	memset(vis, 0, sizeof vis);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> p;
		vec[u].push_back(v);
		vec[v].push_back(u);
		son[u] = v;
		son[v] = u;
		dis[u][v] = p;
	}

	dfs(1);
	cout << ans;
}
