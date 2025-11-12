#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#define int long long
#define x first
#define y second
const int N = 1e3 + 5, M = 15, INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
int u, v, w;
int ans;
int cnt;
int c[M];
int a[M][N];
int g[N][N];
struct node {
	int u, v, w;
	bool operator < (const node& x) const {
		return w < x.w;
	}
}e[N * N * M];
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 10) write(x / 10);
	putchar(x % 10 + '0');
}

struct DSU {
	int fa[10005];
	void init() {
		for (int i = 1; i <= n; i++) 
			fa[i] = i;
	} 
	int find(int x) {
		return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
	} 
	void merge(int x, int y) {
		if (find(x) != find(y)) 
			fa[find(y)] = find(x);
	}
}d;

int kruskal() {
	int res = 0;
	d.init();
	std::sort(e + 1, e + 1 + cnt);
	for (int i = 1; i <= cnt; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (d.find(u) == d.find(v)) continue;
		d.merge(u, v);
		res += w;
	} 
	return res;
}

signed main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(g, 0x3f, sizeof g);
	n = read(), m = read(), k = read();
	ans = 1e18;
	if (k > 0) {
		while (m--) {
			u = read(), v = read(), w = read();
			g[u][v] = std::min(g[u][v], w);
		} 
		for (int i = 1; i <= k; i++) {
			c[i] = read();
			for (int j = 1; j <= n; j++) 
				a[i][j] = read();
		} 
		for (int i = 1; i <= k; i++) 
			for (int j = 1; j <= n; j++) 
				for (int l = 1; l <= n; l++) 
				g[j][l] = std::min(g[j][l], a[i][j] + a[i][l]);
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				if (g[i][j] != INF) e[++cnt] = {i, j, g[i][j]};
		ans = kruskal();
		write(ans);
		putchar('\n');
	} else {
		while (m--) {
			u = read(), v = read(), w = read();
			e[++cnt] = {u, v, w};
		} 
		ans = kruskal();
		write(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

