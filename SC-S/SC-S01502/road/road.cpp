#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 15, M = 1e6 + 1e5 + 5, K = 10;
int n, m, k, uu[M], vv[M], ww[M];

struct edge {
	int u, v, w;
	inline bool operator < (const edge &ano) {
		return w < ano.w;
	}
} e[M], tmp[M], aux[K + 1][N];
int ecnt;

int c[K + 1];

int fa[N];

int fa_find(int u) {return u == fa[u] ? u : fa[u] = fa_find(fa[u]);}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> uu[i] >> vv[i] >> ww[i];
		e[i].u = uu[i], e[i].v = vv[i], e[i].w = ww[i];
	}
	
	for (int i = 1; i <= n; i ++) fa[i] = i;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i ++) {
		int fu = fa_find(e[i].u), fv = fa_find(e[i].v);
		if (fu == fv) continue;
		tmp[++ ecnt] = e[i];
		if (i & 1) swap(fu, fv);
		fa[fu] = fv;
	}
	
	for (int i = 1; i <= ecnt; i ++)
		uu[i] = tmp[i].u, vv[i] = tmp[i].v, ww[i] = tmp[i].w;
	m = ecnt;
	
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++) {
			int w; cin >> w;
			aux[i][j] = (edge){j, i + n, w};
		}
		sort(aux[i] + 1, aux[i] + n + 1);
	}
	
	ll ans = 1e18;
	for (int S = 0; S < (1 << k); S ++) {
		for (int i = 1; i <= n + k; i ++) fa[i] = i;
		for (int i = 1; i <= m; i ++)
			e[i].u = uu[i], e[i].v = vv[i], e[i].w = ww[i];
		ecnt = m;
		ll nowans = 0;
		for (int j = 1; j <= k; j ++) if (S >> (j - 1) & 1) {
			nowans += c[j];
			int now1 = 1, now2 = 1, tmpcnt = 0;
			while (now1 <= ecnt && now2 <= n) {
				if (now1 > ecnt) {
					tmp[++ tmpcnt] = aux[j][now2 ++];
				} else if (now2 > n) {
					tmp[++ tmpcnt] = e[now1 ++];
				} else if (aux[j][now2].w < e[now1].w) {
					tmp[++ tmpcnt] = aux[j][now2 ++];
				} else {
					tmp[++ tmpcnt] = e[now1 ++];
				}
			}
			for (int i = 1; i <= tmpcnt; i ++)
				e[i] = tmp[i];
			ecnt = tmpcnt;
		}
		
		for (int i = 1; i <= ecnt; i ++) {
			int fu = fa_find(e[i].u), fv = fa_find(e[i].v);
			if (fu == fv) continue;
			nowans += e[i].w;
			if (i & 1) swap(fu, fv);
			fa[fu] = fv;
		}
		ans = min(ans, nowans);
	}
	
	cout << ans << "\n";
	
	return 0;
}