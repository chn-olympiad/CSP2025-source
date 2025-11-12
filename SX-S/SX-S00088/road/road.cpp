#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e6 + 5;
const int maxn = 1e4 + 5;
int n, m, k, h[maxm], tot, c[maxn], a[maxn][maxn];
int ans, fa[maxn];
bool vis[maxn];

int find(int x) {
	if (fa[x] != x)
		return fa[x] = find(fa[x]);
	return x;
}

struct node {
	int u, nxt, to, w, id;
} e[maxm];

void add(int u, int v, int w) {
	e[++tot].nxt = h[u];
	h[u] = tot;
	e[tot].to = v;
	e[tot].w = w;
	e[tot].u = u;
	e[tot].id = tot;
}

bool cmp(node aa, node bb) {
	return aa.w < bb.w;
}

void kcode() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	sort (e + 1, e + m + k *n + 1, cmp);
	for (int i = 1; i <= m + k; i++) {
		int u = find(e[i].u);
		int v = find(e[i].to);
		if (u != v) {
//			if (vis[e[i].u]) {
//				ans -= c[e[i].u];
//				cout << e[i].u << endl;
//				cout << c[e[i].u] << endl;
//				cout << 11111 << endl;
//			}
//			if (vis[e[i].to]) {
//				ans -= c[e[i].to];
//
//				cout << 11111 << endl;
//			}
//			if (e[i].u > n) {
//				vis[e[i].u] = 1;
//				cout << 11111 << endl;
//			}
//			if (e[i].to > n) {
//				vis[e[i].to] = 1;
//				cout << 11111 << endl;
//			}
			ans += e[i].w;
//			cout << e[i].id << endl;
			fa[v] = u;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			add(n + i, j, a[i][j] + c[i]);
		}
	}
	kcode();
	cout << ans << endl;
	return 0;
}
