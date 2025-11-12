#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
const int M = 1e5 + 10;
const int K = 12;
int n, m, k, c[K], fa[N];
struct node {
	int u, v, w;
} e[N], ee[N];
node a[K][M];
int cnte[K], num[K];
inline bool cmp(node a, node b) {
	return a.w != b.w ? a.w < b.w : a.u < b.u;
}
inline void init() {
	for(int i = 1; i <= n + k; i ++)fa[i] = i;
}
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline int dele(int x) {
	int cnt = m;
	int ans = 0;
	for(int i = 1; i <= m; i ++)ee[i] = e[i];
	for(int i = 1; i <= n; i ++) ee[++ cnt] = a[x][i];
	sort(ee + 1, ee + cnt + 1, cmp);
	init();
	for(int i = 1; i <= cnt; i ++) {
		int u = find(ee[i].u), v = find(ee[i].v);
		if(u != v) {
			fa[u] = v;
			ans += ee[i].w;
			if(ee[i].u > n) {
				a[x][++ cnte[x]] = ee[i];
			}
		}
	}
	return ans;
}
inline int calc(int m) {
	int ans = 0;
	sort(ee + 1, ee + m + 1, cmp);
	init();
	for(int i = 1; i <= m; i ++) {
		int u = find(ee[i].u), v = find(ee[i].v);
		if(u != v) {
			fa[u] = v;
			ans += ee[i].w;
		}
	}
	return ans;
}
bool vis[K];
int ans = 1e18;
inline void dfs(int u) {
	if(u == k + 1) {
		int cnt = m, sum = 0;
		for(int i = 1; i <= m; i ++)ee[i] = e[i];
		for(int i = 1; i <= k; i ++)if(vis[i]) {
				sum += c[i];
				for(int j = 1; j <= cnte[i]; j ++)ee[++ cnt] = a[i][j];
			}
		ans = min(calc(cnt) + sum, ans);
		return;
	}
	if(num[u] > c[u]) {
		vis[u] = 1;
		dfs(u + 1);
	}
	vis[u] = 0;
	dfs(u + 1);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	sort(e + 1, e + m + 1, cmp);
	init();
	int cnt = 0;
	for(int i = 1; i <= m; i ++) {
		int u = find(e[i].u), v = find(e[i].v);
		if(u != v) {
			fa[u] = v;
			ee[++ cnt] = e[i];
		}
	}
	m = cnt;
	for(int i = 1; i <= m; i ++)e[i] = ee[i];
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		for(int j = 1; j <= n; j ++) {
			int w;
			cin >> w;
			a[i][j] = {n + i, j, w};
		}
		num[i] = dele(i);
	}
	dfs(1);
	cout << ans;
	return 0;
}
