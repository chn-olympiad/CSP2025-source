#include <bits/stdc++.h>
using namespace std;

struct str {
	int v, w;
	str(): v(0), w(0) {};
	str(int _v, int _w): v(_v), w(_w) {};
};
vector<str>ve[10010];
int n, m, dis[20010], vis[20010], k;
map<int, int> mp;

void dfs(int u, int fa, int SS) {
	if (SS > n + k)
		return;
	vis[u] = 1;
	for (str e : ve[u]) {
		int v = e.v;
		if (vis[v])
			continue;
		dis[v] = min(dis[v], dis[u] + e.w);
		dfs(v, u, SS + 1);
	}
	vis[u] = 0;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int u, v, w, i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		ve[u].push_back(str(v, w));
		ve[v].push_back(str(u, w));
	}
	memset(dis, 0x3f, sizeof dis);
	for (int ii, i = 1; i <= k; i++) {
		cin >> ii;
		mp[i + n] = ii;
		for (int j = 1, kk; j <= n; j++) {
			cin >> kk;
			ve[j].push_back(str(i, kk));
			ve[i].push_back(str(j, kk));
		}
	}
	dis[0] = dis[1] = 0;
	dfs(1, 0, 1);
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << endl;
	}
	cout << maxx;
	return 0;
}