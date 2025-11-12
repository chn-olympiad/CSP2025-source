#include <bits/stdc++.h>

#define int long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

constexpr int N = 1e4 + 10, M = 1e6 + 10, K = 11, inf = 1e18; 
int n, m, k, c1[K], c2[K][N], ans; 
int ppc(int x) {
	int ret = 0; 
	while (x > 0) ret += (x & 1), x >>= 1; 
	return ret; 
}
struct node {
	int u, v, w;
	bool operator < (const node &cmp) const {
		return w < cmp.w;
	}
} e[M << 1], ed[M << 1];
int anc[N << 1], sz[N << 1]; 
int find(int u) {
	if (anc[u] == u) return u;
	else return anc[u] = find(anc[u]); 
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u != v) {
		if (sz[u] < sz[v]) {
			anc[u] = v, sz[v] += sz[u], sz[u] = 0; 
		}
		else {
			anc[v] = u, sz[u] += sz[v], sz[v] = 0; 
		}
	}
}
int calc(int s) {
	int ret = 0, idx = n, tot = 0;
	for (int i = 1; i <= k; ++i)	
		if ((s >> (i - 1)) & 1) {
			ret += c1[i], ++idx; 
			for (int j = 1; j <= n; ++j) ed[++tot] = (node) {j, idx, c2[i][j]}; 
		}
	if (ret > ans) return ans; 
	for (int i = 1; i <= m; ++i) ed[++tot] = e[i]; 
	for (int i = 1; i <= idx; ++i) anc[i] = i, sz[i] = 1; 
	std::sort(ed + 1, ed + 1 + tot);
	for (int i = 1; i <= tot; ++i) {
		int u = ed[i].u, v = ed[i].v, w = ed[i].w;
		if (find(u) == find(v)) continue ;
		ret += w, merge(u, v); 
		if (ret > ans) return ans; 
	}
	return ret; 
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) std::cin >> e[i].u >> e[i].v >> e[i].w;
	bool fl = 1; 
	for (int i = 1; i <= k; ++i) {
		std::cin >> c1[i];
		if (c1[i] > 0) fl = 0; 
		for (int j = 1; j <= n; ++j) std::cin >> c2[i][j];  
	}
	if (fl) {
		ans = inf; 
		ans = min(ans, calc((1 << k) - 1)); 
		std::cout << ans << "\n";
		return 0; 
	}
	ans = inf; 
	for (int s = 0; s < (1 << k); ++s) {
		ans = min(ans, calc(s)); 
	}
	std::cout << ans << "\n"; 
	return 0;
}

