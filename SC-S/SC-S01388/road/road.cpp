#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using ll = long long int;
const int MAXN = 1e5 + 10;

struct DSU {
	std::vector <int> f;
	
	DSU (int l = 0) : f(l) {
		std::iota(f.begin(), f.end(), 0);
	}
	
	int find (int x) {
		if (f[x] == x) return x;
		else return f[x] = find(f[x]);
	}
	
	bool merge (int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return 0;
		else {
			f[fx] = fy;
			return 1;
		}
	}
	
	bool same (int x, int y) {
		return find(x) == find(y);
	}
};

ll ans = 1e18;
int n, m, k, c[20], a[20][MAXN], vis[20];
std::vector <int> g[MAXN];


struct edge {
	int u, v, w;
	bool operator < (const edge& t) {
		return w < t.w;
	}
};

std::vector <edge> e;

void subtask1 () {
	DSU ds(n + 1);
	std::sort(e.begin(), e.end());
	
	ll ans = 0;
	
	for (auto t : e) {
		int u = t.u, v = t.v, w = t.w;
		if (ds.merge(u, v))
			ans += w;
	}
	
	std::cout << ans;
}

void subtask2 () {
	e.reserve(n * n + m);
	
	DSU ds(n + 1);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int mn = 1e9;
			for (int l = 1; l <= k; l++) {
				mn = std::min(mn, a[l][i] + a[l][j]);
			}
			e.push_back({i, j, mn});
		}
	}
	
	std::sort(e.begin(), e.end());
	
	ll ans = 0;
	
	for (auto t : e) {
		int u = t.u, v = t.v, w = t.w;
		if (ds.merge(u, v))
			ans += w;
	}
	
	std::cout << ans;
}

void check () {
	DSU ds(n + 1);
	ll res = 0;
	
	std::vector <edge> ne = e;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int mn = 1e9;
			for (int l = 1; l <= k; l++) {
				if (vis[l])
					mn = std::min(mn, a[l][i] + a[l][j]);
			}
			ne.push_back({i, j, mn});
		}
	}
	
	for (int i = 1; i <= k; i++)
		if (vis[i])
			res += c[i];
	
	std::sort(ne.begin(), ne.end());
	
	
	for (auto t : ne) {
		int u = t.u, v = t.v, w = t.w;
		if (ds.merge(u, v))
			res += w;
	}
	
	ans = std::min(ans, res);
}

void dfs (int now) {
	if (now == k + 1)
		check();
	else {
		vis[now] = 0;
		dfs(now + 1);
		vis[now] = 1;
		dfs(now + 1);
	}
}

void subtask3 () {
	dfs(1);
	std::cout << ans;
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w; std::cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	
	bool flag = 1;
	
	for (int i = 1; i <= k; i++) {
		std::cin >> c[i];
		for (int j = 1; j <= n; j++)
			std::cin >> a[i][j];
		if (c[i])
			flag = 0;
	}
	
	if (k == 0) subtask1();
	else if (flag) subtask2();
	else subtask3();
	
	
	return 0;
}