#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e4 + 5, M = 2e6 + 5, K = 10 + 5, T = (1 << 10) + 5;

int n, m, k;

struct node {
	int a, b, w;
	node() {}
	node(int A, int B, int W) {
		a = A, b = B, w = W;
	}
	bool operator<(const node &x) const {
		return w < x.w;
	}
} f[M], g[T][N], cur[M];
int len[T];

struct pnt {
	int to, w;
	bool operator<(const pnt &x) const {
		return w < x.w;
	}
} c[K][N];
int a[N];
ll val[T];

int fa[N];
int find(int x) {
	return (fa[x] < 0 ? x : fa[x] = find(fa[x]));
}
bool merge(int x, int y) {
	if ((x = find(x)) == (y = find(y))) {
		return 0;
	}
	if (fa[x] > fa[y]) {
		swap(x, y);
	}
	fa[x] += fa[y];
	fa[y] = x;
	return 1;
}
void init(int n) {
	for (int i = 1; i <= n; ++i) {
		fa[i] = -1;
	}
}

ll calc(node *a, node *b, int &len, int n, int m) {
	init(n);
	ll res = 0;
	len = 0;
	for (int i = 1; i <= m; ++i) {
		if (merge(a[i].a, a[i].b)) {
			res += a[i].w;
			cout << a[i].a << ' ' << a[i].b << ' ' << a[i].w << '\n';
		}
		b[++len] = a[i];
	}
	return res;
}

ll ans;

signed main() {
	assert(freopen("road.in", "r", stdin));
	assert(freopen("road.ans", "w", stdout));

	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> f[i].a >> f[i].b >> f[i].w;
	}
	sort(f + 1, f + m + 1);
	ans = calc(f, g[0], len[0], n, m);
	for (int i = 1; i <= k; ++i) {
		cin >> a[i];
		for (int j = 1; j <= n; ++j) {
			cin >> c[i][j].w;
			c[i][j].to = j;
		}
		sort(c[i] + 1, c[i] + n + 1);
	}
	for (int i = 1; i < (1 << k); ++i) {
		int t = __lg(i & (-i)) + 1;
		int lst = i ^ (i & (-i));
		int tot = __builtin_popcount(i);
		val[i] = val[lst] + a[t];
		for (int j = 1, p1 = 1, p2 = 1; j <= len[lst] + n; ++j) {
			if (p2 > n || p1 < lst[len] && g[lst][p1].w < c[t][p2].w) {
				cur[j] = g[lst][p1++];
			}
			else {
				cur[j] = node(c[t][p2].to, n + tot, c[t][p2].w);
				++p2;
			}
		}
		cout << "=====\n";
		// cout << calc(cur, g[i], len[i], n + tot, len[lst] + n) << '\n';
		ans = min(ans, val[i] + calc(cur, g[i], len[i], n + tot, len[lst] + n));
	}
	cout << ans << '\n';

	// cerr << 1. * clock() / CLOCKS_PER_SEC << '\n';

	return 0;
}