#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

inline int read() {
	int num = 0, sign = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		sign = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch && ch <= '9')
		num = (num << 1) + (num << 3) + ch - '0', ch = getchar();
	return sign < 0 ? -num : num;
}
const int MAXN = 1e4 + 8;
int n, m, k, dsu[MAXN], a[MAXN];
int head[MAXN], cnt;

struct Edge {
	int u, v, w, nxt;
	bool operator<(const Edge &rhs) const {
		return w < rhs.w;
	}
} edges[MAXN];

inline void add_edge(int u, int v, int w) {
	edges[++cnt] = {u, v, w, head[u]}, head[u] = cnt;
}

inline int find(int u) {
	return dsu[u] == u ? u : dsu[u] = find(dsu[u]);
}

void unite(int u, int v) {
	dsu[find(u)] = find(v);
}

int kruskal() {
	int ret = 0, cnt = 0;
	for (auto [u, v, w, _] : edges) {
		if (cnt == n - 1)
			return ret;
		if (find(u) != find(v)) {
			unite(u, v), cnt++, ret += w;
		}
	}
	return ret;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1, u, v, w; i <= m; i++)
		u = read(), v = read(), w = read(), add_edge(u, v, w), add_edge(v, u, w);
	for (int i = 1, c; i <= k; i++)  {
		c = read();
		for (int j = 1, w; j <= n; j++)
			a[j] = read();
		for (int u = 1; u <= n; u++)
			for (int v = u + 1; v <= n; v++)
				add_edge(u, v, a[u] + a[v] + c), add_edge(v, u, a[u] + a[v] + c);
	}
	sort(edges + 1, edges + m + k * n + 1);
	for (int i = 1; i <= n; i++)
		dsu[i] = i;
	cout << kruskal();

	return 0;
}