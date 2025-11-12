#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;

struct edge {
	int u, v, w;
	friend bool operator < (edge a, edge b) {
		return a.w < b.w;
	}
};

int n, m, k;
long long ans, res;
int fa[N], c[15];
int a[15][N];
vector<pair<int, int>> g[N + 15];
edge e[M];

int find (int x) {
	return x == fa[x] ? x : find(fa[x]);
}

void kruskal (void) {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(e + 1, e + n + 1);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, fu = find(u), fv = find(v);
		if (fu != fv)
			cnt++, fa[fu] = fv, ans += e[i].w, g[u].push_back({v, e[i].w}), g[v].push_back({u, e[i].w});
		if (cnt == n - 1)
			return ;
	}
}

void dfs (int x, int id, int fa) {
//	cout << x << ' ' << fa << '\n';
	if (!x)
		return ;
	for (auto i : g[x]) {
		if (i.first == fa) {
			if (i.second > a[id][x])
				res -= i.second - a[id][x];
		}
		else if (i.first)
			dfs(i.first, id, x);
	}
}

bool dfs1 (int x, int id, int fa) {
	if (!x)
		return 0;
	bool del = 0;
	for (auto &i : g[x])
		if (i.first == fa) {
			if (i.second > a[id][x]) {
				i.first = 0;
				del = 1;
				g[x].push_back({id + n, a[id][x]});
				g[id + n].push_back({x, a[id][x]});
			}
		}
		else if (i.first) {
			bool tmp = dfs1(i.first, id, x);
			if (tmp)
				i.first = 0;
		}
	return del;
}

namespace solveA {
	int plc[15];
	void solve (void) {
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				if (!a[i][j])
					plc[i] = j, cout << i << ' ' << j << '\n';
		for (int i = 1; i <= k; i++) {
			res = ans;
			dfs(plc[i], i, 0);
			ans = res;
			dfs1(plc[i], i, 0);
//			g[plc[i]].push_back({i + n, a[i][plc[i]]});
//			g[i + n].push_back({plc[i], a[i][plc[i]]});
		}
		cout << ans << '\n';
	}
}

int main (void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	int mx = 0;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		mx = max(mx, c[i]);
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	kruskal();
	if (!mx && k) {
		solveA::solve();
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		int id = 0, tmp = ans;
		for (int j = 1; j <= n; j++) {
			res = ans, dfs(j, i, 0);
//			cout << res + c[i] + a[i][j] << ' ' << i << ' ' << j << '\n';
			if (tmp > res + c[i] + a[i][j])
				tmp = res + c[i] + a[i][j], id = j;
		}
		if (id) {
			dfs1(id, i, 0);
			g[id].push_back({i + n, a[i][id]});
			g[i + n].push_back({id, a[i][id]});
			ans = tmp;
		}
	}
//	cout<<'\n';
//	dfs(1, 0, 0);
//	for (int i = 1; i <= n + k; i++) {
//		for (auto j : g[i])
//			cout << j.first << ' ';
//		cout << '\n';
//	}
	cout << ans << '\n';
	return 0;
}
//前4个点直接最小生成树
//特殊性质：先最小生成树，然后对于每个乡镇考虑除了代价为0的点，每个点删原来距离代价为0的点比较近的边连到乡镇上
//n^2k做法：最小生成树，然后每个乡镇枚举与其相连的点，然后以此点为根dfs，然后与特殊性质相同

