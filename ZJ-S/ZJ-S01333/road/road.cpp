#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
} E[10005], e[1000005], tmp[110005], ee[15][10005];
int c[15], a[15][10005], fa[10015], w[10015], tot;

int find_fa(int x) {
    return fa[x] ? (fa[x] = find_fa(fa[x])) : x;
}

bool merge(int u, int v) {
    u = find_fa(u); v = find_fa(v);
    if (u == v) return false;
    if (w[u] > w[v]) swap(u, v);
    fa[u] = v;
    w[v] += w[u];
	return true;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    long long res = LLONG_MAX;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + m + 1, [](Edge x, Edge y) {
        return x.w < y.w;
    });
    fill(w + 1, w + n + 1, 1);
    for (int j = 1; j <= m; j ++) {
        if (merge(e[j].u, e[j].v)) {
        	E[++ tot] = e[j];
        }
    }
    assert(tot == n - 1);
    tot = m;
    for (int i = 0; i < k; i ++) {
        cin >> c[i];
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            ee[i][j] = {j, n + i + 1, a[i][j]};
        }
        sort(ee[i] + 1, ee[i] + n + 1, [](Edge x, Edge y) {
            return x.w < y.w;
        });
    }
    for (int i = 0; i < (1 << k); i ++) {
    	for (int j = 1; j < n; j ++) e[j] = E[j];
        long long r = 0;
        fill(fa + 1, fa + n + k + 1, 0); fill(w + 1, w + n + k + 1, 1);
        tot = n - 1;
        for (int j = 0; j < k; j ++) {
            if (i & (1 << j)) {
                r += c[j];
                merge(e + 1, e + tot + 1, ee[j] + 1, ee[j] + n + 1, tmp + 1, [](Edge x, Edge y) {
            		return x.w < y.w;
        		});
                tot += n;
                for (int I = 1; I <= tot; I ++) e[I] = tmp[I];
            }
        }
        for (int j = 1; j <= tot; j ++) {
            if (merge(e[j].u, e[j].v)) {
                r += e[j].w;
            }
        }
        res = min(res, r);
    }
    cout << res << '\n';
    return 0;
}