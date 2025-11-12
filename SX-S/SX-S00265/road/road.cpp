#include <bits/stdc++.h>
using namespace std;
long long n, m, k, cnt, c[15], a[10005], flag, sum, fa[20005], l[20005], u, v, w;

struct node {
	int s, to, w;
} e[4000005];

inline void add(int u, int v, int w) {
	cnt++;
	e[cnt].s = u;
	e[cnt].to = v;
	e[cnt].w = w;
}

inline int find(int x) {
	if (fa[x] == x)
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

inline void merge(int x, int y) {
	fa[find(x)] = find(y);
}

inline bool cmp(node x, node y) {
	return x.w < y.w;
}

int main() {

	cin >> n >> m >> k;
	for (int i = 0; i <= n + k; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		add(0, n + i, c[i]);
		add(n + i, 0, c[i]);
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
			add(n + i, j, a[j]);
			add(j, n + i, a[j]);
		}
	}
	sort(e + 1, e + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		if (find(e[i].s) != find(e[i].to)) {
			if (e[i].s > n)
				l[e[i].s] += e[i].w;
			if (e[i].to > n)
				l[e[i].to] += e[i].w;
			merge(e[i].s, e[i].to);
			sum += e[i].w;
		}
		for (int j = 1; j <= n; j++) {
			if (find(j) != find(1))
				flag = 1;
		}
		if (flag == 0) {
			for (int j = 1; j <= k; j++) {
				if (find(j) != find(1))
					sum -= l[n + j];
				break;
			}
		}
		cout << sum + 1;

		return 0;
	}