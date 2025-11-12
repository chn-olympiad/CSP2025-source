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
} e[M], T[N];

int n, m, k, tot, fa[N], c[K], a[K][N], minv[K][N];
ll ans = 2e18;

inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
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
		T[++tot] = e[i];
	}
	L(i, 0, k - 1) {
		cin >> c[i];
		L(j, 1, n) {
			cin >> a[i][j];
		}
	}
	L(s, 0, (1 << k) - 1) {
		ll res = 0;
		L(i, 0, k - 1) {
			if (s >> i & 1) res += c[i];
		}
		L(i, 0, k - 1) copy(a[i], a[i] + n + 1, minv[i]);
		iota(fa + 1, fa + n + 1, 1);
		L(i, 1, n - 1) {
			int u = T[i].u, v = T[i].v, w = T[i].w;
			int fu = find(u), fv = find(v);
			L(j, 0, k - 1) {
				if (s >> j & 1) w = min(w, minv[j][fu] + minv[j][fv]);
			}
			res += w;
			fa[fu] = fv;
			L(j, 0, k - 1) minv[j][fv] = min(minv[j][fv], minv[j][fu]);
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
	return 0;
}
