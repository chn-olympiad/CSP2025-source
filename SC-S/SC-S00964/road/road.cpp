#include<bits/stdc++.h>
#define itn int
#define pii pair<int,int>
#define fi first
#define se second
#define el cout<<"\n"
#define N 10020
#define piii pair<int,pii>
#define int long long
using namespace std;
int n, m, k, fa[N], tw[15][N], u, v, w, gd[15][N], ans = 1145141919810114514, usd[15], vis[N], dis[N];
struct Road {
	int w, u, v;
};
vector<pii>e[N];
void init() {
	for (itn i = 1; i <= n + k; i++) {
		dis[i] = 1145141919810114514;
		vis[i] = 0;
	}
	dis[1] = 0;
}
int calc() {
	init();
	int ret = 0;
	for (int i = 1; i <= k; i++)
		ret += (usd[i] * tw[i][0]);
	priority_queue<pii, vector<pii>, greater<pii>>q;
	q.push({0, 1});
	while (!q.empty()) {
		pii u = q.top();
		q.pop();
		if (vis[u.se]) continue;
		ret += u.fi;
		vis[u.se] = 1;
		if (u.se <= n) {
			for (auto v : e[u.se])
				if (!vis[v.fi])
					if (v.se < dis[v.fi]) {
						dis[v.fi] = v.se;
						q.push({dis[v.fi], v.fi});
					}
			for (int v = 1; v <= k; v++)
				if (usd[v])
					if (!vis[n + v])
						if (tw[v][u.se] < dis[n + v]) {
							dis[n + v] = tw[v][u.se];
							q.push({dis[n + v], n + v});
						}
		} else
			for (int v = 1; v <= n; v++)
				if (!vis[v])
					if (tw[u.se - n][v] < dis[v]) {
						dis[v] = tw[u.se - n][v];
						q.push({dis[v], v});
					}

	}
	return ret;
}
void dfs(itn x) {
	if (x > k) {
		ans = min(ans, calc());
		return;
	}
	usd[x] = 0;
	dfs(x + 1);
	usd[x] = 1;
	dfs(x + 1);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)fa[i] = i;
	for (itn i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> tw[i][0];
		for (int j = 1; j <= n; j++)
			cin >> tw[i][j];
	}
	dfs(1);
	cout << ans;
	return 0;
}