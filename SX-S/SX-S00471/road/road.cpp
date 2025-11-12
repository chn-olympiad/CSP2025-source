#include <bits/stdc++.h>
using namespace std;
int  n, m, u, v, w, k, cnt, fa[10005], sum;

inline int query(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = query(fa[x]);
}

struct node {
	int u, v, w;
} e[1000005];

inline void add(int u, int v, int w) {
	e[++cnt] = {u, v, w};
}

inline bool cmp(node x, node y) {
	return x.w < y.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	memset(e, 0x3f3f3f3f, sizeof e);
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	sort(e + 1, e + cnt + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (query(e[i].u) == query(e[i].v))
			continue;
		else {
			fa[query(e[i].u)] = query(e[i].v);
			sum += e[i].w;
		}
	}
	cout << sum;
	return 0;
}

