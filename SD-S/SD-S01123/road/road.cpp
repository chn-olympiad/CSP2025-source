#include <bits/stdc++.h>
#define ll long long
#define mid ((l + r) >> 1)
#define arr array<int, 3>

using namespace std;

constexpr int N = 1e4 + 5, M = 1e6 + 5, K = 1050;

int lowbit(int x) {
	return x & -x;
}

struct DSU {
	int fa[N << 1], sz[N << 1];
	
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	
	void init(int n) {
		iota(fa, fa + n + 1, 0);
		fill(sz, sz + n + 1, 1);
	}
	
	bool check(int x, int y) {
		return find(x) == find(y);
	}
	
	void merge(int x, int y) {
		if (sz[find(x)] < sz[find(y)]) {
			swap(x, y);
		}
		sz[find(x)] += sz[find(y)];
		fa[find(y)] = find(x);
	}
} D;

bool M1;

int n, m, k;
ll res;
int val[K][N], c[N];
arr E[M], e[K][N << 1], a[15][N << 1];

bool M2;

void kruskal1() {
	D.init(n);
	sort(E + 1, E + m + 1);
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		auto cur = E[i];
		if (D.check(cur[1], cur[2])) {
			continue;
		}
		res += cur[0];
		e[0][++cnt] = cur;
		D.merge(cur[1], cur[2]);
	}
}

void kruskal(int S) {
	int m = 0, x = __builtin_popcount(S), p = 0, cnt = 0;
	while ((1 << p) < lowbit(S) * 2) ++p;
	int n1 = n + x - 2, n2 = n, p1 = 0, p2 = 0;
	while (p1 < n1 && p2 < n2) {
		if (e[S ^ lowbit(S)][p1 + 1] < a[p][p2 + 1]) {
			E[++m] = e[S ^ lowbit(S)][++p1];
		} else {
			E[++m] = a[p][++p2];
		}
	}
	while (p1 < n1) E[++m] = e[S ^ lowbit(S)][++p1];
	while (p2 < n2) E[++m] = a[p][++p2];
	D.init(n + k);
	for (int i = 1; i <= m; ++i) {
		auto cur = E[i];
		if (D.check(cur[1], cur[2])) {
			continue;
		}
		res += cur[0];
		e[S][++cnt] = cur;
		D.merge(cur[1], cur[2]);
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		E[i] = {w, u, v};
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> val[i][j];
			a[i][j][0] = val[i][j];
			a[i][j][1] = n + i;
			a[i][j][2] = j;
		}
		sort(a[i] + 1, a[i] + n + 1);
	}
	
	kruskal1();
	ll ans = res;
	for (int s = 1; s < (1 << k); ++s) {
		res = 0;
		for (int i = 1; i <= k; ++i) {
			if ((s >> (i - 1)) & 1) {
				res += c[i];
			}
		}
		kruskal(s);
		ans = min(ans, res);
	}
	
	cout << ans << '\n';
	
	return 0;
}
