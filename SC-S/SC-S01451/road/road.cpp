#include <bits/stdc++.h>
using namespace std;

const int N = 1.1e4, M = 11, MAXE = 1.1e6 + 10;
int c[N], a[M][N], p[N];

int find(int x) {
	if (p[x] != x) {
		return p[x] = find(p[x]);
	}
	return p[x];
}

struct edge {
	int a, b, w;
} e[MAXE], E[MAXE];

int comp(edge a, edge b) {
	return a.w < b.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i < N; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	sort(e + 1, e + m + 1, comp);
	int K = 0;
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].a), v = find(e[i].b);
		if (u != v) {
			K++;
			p[u] = v;
			E[K] = e[i];
		}
	}
	for (int j = 0; j < k; j++) {
		cin >> c[j];
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
		}
	}
	long long ans = 1e18;
	for (int i = 0; i < (1 << k); i++) {
		int tot = K;
		for (int j = 1; j <= K; j++) {
			e[j] = E[j];
		}
		long long res = 0;
		int cnt = 0;
		for (int j = 0; j < k; j++) {
			if (i >> j & 1) {
				res += c[j], cnt++;
				for (int x = 1; x <= n; x++) {
					if (a[j][x] > E[K].w) continue;
					e[++tot] = {n + j + 1, x, a[j][x]};
				}
			}
		}
		for (int j = 1; j <= n + k + 1; j++) {
			p[j] = j;
		}
		sort(e + 1, e + tot + 1, comp);
		int T = 0;
		for (int j = 1; j <= tot; j++) {
			int u = find(e[j].a), v = find(e[j].b), w = e[j].w;
			if (u != v) {
				T++, res += w;
				p[u] = v;
			}
			if (T == cnt + n - 1) break;
		}
		ans = min(ans, res);
	}
	cout << ans << "\n";
	return 0;
}