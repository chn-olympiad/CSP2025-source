#include <cstdio>
#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int N = 5e4 + 10, M = 3e6 + 10, INF = 1e15;

int cnt;
int a[25][N], c[25], f[N], siz[N];

struct edge {
	int u, v, w;
} e[M];

int read() {
	int num = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		num = num * 10 + ch - '0';
		ch = getchar();
	}
	return num * f;
}

void add(int u, int v, int w) {
	e[++ cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int find(int x) {
	if (f[x] != x) return f[x] = find(f[x]);
	return x;
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (siz[u] > siz[v]) swap(u, v);
	f[u] = v;
	siz[v] += siz[u];
}

int build_tree(int x) {
	for (int i = 1; i <= x; i ++) f[i] = i, siz[i] = 1;
	sort(e + 1, e + cnt + 1, cmp);
	int sum = 0;
	for (int i = 1; i <= cnt; i ++) {
		if (find(e[i].u) != find(e[i].v)) {
//			cout << e[i].u << ' ' << f[e[i].v] << '\n';
			merge(e[i].u, e[i].v);
			sum += e[i].w;
		}
	}
	return sum;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i ++) {
		int u= read(), v = read(), w = read();
		add(u, v, w);
	}
	for (int i = 1; i <= k; i ++) {
		c[i] = read();
		for (int j = 1; j <= n; j ++)
			a[i][j] = read();
	}
	int ans = INF;
	for (int i = 0; i <= (1 << k) - 1; i ++) {
		int sum = 0;
		for (int j = 1; j <= k; j ++) {
			if ((1 << (j - 1)) & i) {
//				cout << j << ' ';
				sum += c[j];
				for (int p = 1; p <= n; p ++)
					add(n + j, p, a[j][p]);
			}
		}
//		cout << i << '\n';
//		cout << sum + build_tree(n + k) << '\n';
		ans = min(ans, sum + build_tree(n + k));
		for (int j = 1; j <= k; j ++)
			if ((1 << (j - 1)) & i)
				cnt -= n;
	}
	cout << ans << '\n';
	return 0;
}
