#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k, ans;
ll u, v, w[1000010];
ll c[15], a[15][1010];
bool fff = false;
int vis[1000010];
vector <ll> e[1000010];

void dfs(int now, int end) {
	if (now == end) {
		fff = true;
		return;
	}
	for (ll j = 0; j < e[now].size(); ++j) {
		if (vis[e[now][j]] == 0 && e[now][j] != 0) {
			vis[e[now][j]] = 1;
			dfs(e[now][j], end);
			vis[e[now][j]] = 0;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j && e[i].size() == 0) {
				e[i].push_back(j);
			}
		}
	}
	for (ll i = 1; i <= m; ++i) {
		cin >> u >> v >> w[i];
		e[u][v] = 0, e[v][u] = 0;
		ans += w[i];
	}
	bool flag = true;
	for (ll i = 1; i <= k; ++i) {
		cin >> c[i];
		for (ll j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (c[i] != 0 || a[i][j] != 0)
				flag = false;
		}
	}
	if (flag == true) {
		ans = 0;
		for (ll i = 1; i <= k; ++i) {
			for (ll j = 1; j <= n; ++j) {
				e[j].push_back(c[i]), e[c[i]].push_back(j);
			}
		}
		for (ll i = 1; i <= n; ++i) {
			for (ll j = i + 1; j <= n; ++j) {
				fff = false;
				if (e[i][j] == 0) {
					memset(vis, 0, sizeof(vis));
					dfs(i, j);
					if (fff == false)
						ans += w[i];
				}
			}
		}
	}
	cout << ans;
	return 0;
}