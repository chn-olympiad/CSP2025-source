#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define maxn 1000007
const int INF = 1e9 + 7;
int n, m, k;
vector <array <int, 2> > q[maxn];
int a[14][maxn], c[15];
int fa[maxn], ans, f[maxn];
int find (int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int finda (int x) { return f[x] == x ? x : f[x] = finda(f[x]); }
vector <array <int, 3> > vis, gis;
priority_queue <array <int, 3> , vector <array <int, 3> > , greater <array <int, 3> > > dis;
vector <int> gtt[2000], gt;
int len;
void solve () {
	int cnt = 0;
	while (cnt < n && ! dis.empty()) {
		array <int, 3> x = dis.top();
		dis.pop();
		int w = x[0], u = x[1], v = x[2];
		if (find(fa[u]) == find(fa[v])) {
			continue;
		}
		vis.push_back({u, v, w});
		fa[find(fa[u])] = find(fa[v]);
		cnt ++;
	}
}
void solvea (int n) {
	int cnt = 0;
	while (cnt < n && ! dis.empty()) {
		array <int, 3> x = dis.top();
		dis.pop();
		int w = x[0], u = x[1], v = x[2];
		if (finda(f[u]) == finda(f[v])) {
			continue;
		}
		gis.push_back({u, v, w});
		f[finda(f[u])] = finda(f[v]);
		cnt ++;
	}
}
void dfs (int x) {
	if (x > k) {
		gtt[++ len] = gt;
		return ;
	}
	gt.push_back(x);
	dfs(x + 1);
	gt.pop_back();
	dfs(x + 1);
	return ;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i ++) {
		cin >> u >> v >> w;
		q[u].push_back({v, w});
		q[v].push_back({u, w});
		dis.push({w, u, v});
	}
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i ++) {
		fa[i] = i;
	}
	solve();
	dfs(1);
	ans = INF;
	for (int i = 1; i <= len; i ++) {
		int sum = 0;
		while (! dis.empty()) {
			dis.pop();
		}
		gis.clear();
		for (auto it : vis) {
			dis.push({it[2], it[0], it[1]});
		}
		for (int j = 1; j <= n + k; j ++) {
			f[j] = j;
		}
		for (auto it : gtt[i]) {
			sum += c[it];
			for (int j = 1; j <= n ; j ++) {
				dis.push({a[it][j], it + n, j});
			}
		}
		solvea(n + gtt[i].size());
		for (auto it : gis) {
			sum += it[2];
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}

