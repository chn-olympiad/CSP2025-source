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

const int N = 1e4 + 50, M = 1e6 + 6, K = 12;

struct edge {
	int u, v, w;
} e[M], T[N], G[M];

int n, m, k, tot, fa[N], siz[N], c[K], a[K][N], id[K][N];
ll ans = 2e18;

inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
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
		T[++tot] = e[i];
	}
	L(i, 0, k - 1) {
		cin >> c[i];
		L(j, 1, n) {
			cin >> a[i][j];
			id[i][j] = j;
		}
		sort(id[i] + 1, id[i] + n + 1, [=](int x, int y) {
			return a[i][x] < a[i][y];
		});
	}
	L(s, 0, (1 << k) - 1) {
		ll res = 0;
		int p[k + 1] = {0}, ad = 0;
		iota(fa + 1, fa + n + k + 2, 1);
		fill(siz + 1, siz + n + k + 2, 1);
		L(i, 0, k - 1) {
			if (s >> i & 1) res += c[i], ad++;
		}
		for (tot = 0; tot < n + ad - 1; ) {
			int u = 0, v = 0, w = 2e9, x = k;
			L(i, 0, k - 1) {
				if (!(s >> i & 1) || p[i] + 1 > n) continue;
				if (a[i][id[i][p[i] + 1]] < w) {
					w = a[i][id[i][p[i] + 1]];
					u = i + n + 1, v = id[i][p[i] + 1];
					x = i;
				}
			}
			if (p[k] + 1 < n && T[p[k]].w < w) {
				w = T[p[k] + 1].w, u = T[p[k] + 1].u, v = T[p[k] + 1].v;
				x = k;
			}
			p[x]++;
			int fu = find(u), fv = find(v);
			if (fu == fv) continue;
			tot++;
			if (siz[fu] > siz[fv]) swap(fu, fv);
			fa[fu] = fv;
			siz[fv] += siz[fu];
			res += w;
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
	return 0;
}
