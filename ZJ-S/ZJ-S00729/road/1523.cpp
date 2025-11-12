#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie() -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= r; i++)
#define R(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e4 + 4, M = 1e6 + 6, K = 12, LG = 15;

struct edge {
	int u, v, w;
} e[M];

int n, m, k, fa[N], c[K], a[K][N];
int dfn[N], siz[N], dfc;
int rmq[K][LG][N];
ll mst, ans, res;
vector < pii > G[N];

inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void init(int u, int f) {
	dfn[u] = ++dfc;
	siz[u] = 1;
	L(i, 0, k - 1) rmq[i][0][dfc] = a[i][u];
	for (auto [v, w] : G[u]) {
		if (v != f) {
			init(v, u);
			siz[u] += siz[v];
		}
	}
}
inline int query(int t, int l, int r) {
	if (l > r) return 2e9;
	int w = __lg(r - l + 1);
	return min(rmq[t][w][l], rmq[t][w][r - (1 << w) + 1]);
}
inline void solve(int u, int f, int s) {
	for (auto [v, w] : G[u]) {
		if (v != f) {
			solve(v, u, s);
			ll alt = 1e18;
			L(i, 0, k - 1) {
				if (!(s >> i & 1)) continue;
				ll sub = query(i, dfn[v], dfn[v] + siz[v] - 1);
				ll out = min(query(i, 1, dfn[v] - 1), query(i, dfn[v] + siz[v], n));
				alt = min(alt, sub + out);
			}
			res -= max(0ll, w - alt);
			if (s == 1) cerr << u << ' ' << v << ": " << max(0ll, w - alt) << " qwq\n"
		}
	}
}

int main() {
	qio(), cin >> n >> m >> k;
	L(i, 1, m) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e + 1, e + m + 1, [](edge x, edge y) {
		return x.w < y.w;
	});
	iota(fa + 1, fa + n + 1, 1);
	L(i, 1, m) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu == fv) continue;
		fa[fu] = fv;
		mst += e[i].w;
		G[e[i].u].pb({e[i].v, e[i].w});
		G[e[i].v].pb({e[i].u, e[i].w});
	}
	ans = mst;
	L(i, 0, k - 1) {
		cin >> c[i];
		L(j, 1, n) {
			cin >> a[i][j];
		}
	}
	init(1, 0);
	L(t, 0, k - 1) {
		L(i, 1, LG - 1) {
			L(j, 1, n - (1 << i) + 1) {
				rmq[t][i][j] = min(rmq[t][i - 1][j], rmq[t][i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	L(s, 0, (1 << k) - 1) {
		res = mst;
		L(i, 0, k - 1) {
			if (s >> i & 1) res += c[i];
		}
		solve(1, 0, s);
		ans = min(ans, res);
	}
	cout << ans << '\n';
	return 0;
}
