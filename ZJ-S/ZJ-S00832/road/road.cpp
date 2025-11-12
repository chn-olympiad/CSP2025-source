#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6+10, M = 20010;
int n, m, k, idx, midx, h[N], tot, fa[M];
int deg[M], wei[M];
ll c[20], a[20][M];
struct Edge {int u, v; ll w;} e[N], t[N];
inline bool cmp (Edge &u, Edge &v) {return u.w < v.w;};

int find(int x) {
    if(x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(h, -1, sizeof h);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1, u, v, w; i <= m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    bool flaga = 1;
    for(int i = 1; i <= k; i ++) {
        cin >> c[i];
        if(c[i] > 0) flaga = 0;
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n + k; i ++) fa[i] = i;
    if(k == 0) {
        ll ans = 0;
        sort(e + 1, e + m + 1, cmp);
        for(int i = 1; i <= m; i ++) {
            int u = find(e[i].u), v = find(e[i].v);
            if(u == v) continue;
            fa[u] = v;
            ans += e[i].w;
        }
        cout << ans;
    } else if(flaga) {
        for(int i = 1, id; i <= k; i ++) {
            for(int j = 1; j <= n; j ++)
                if(a[i][j] == 0) id = j;
            for(int j = 1; j <= n; j ++)
                if(j != id) e[++ m] = {id, j, a[i][j]};
        }
        ll ans = 0;
        sort(e + 1, e + m + 1, cmp);
        for(int i = 1; i <= m; i ++) {
            int u = find(e[i].u), v = find(e[i].v);
            if(u == v) continue;
            fa[u] = v;
            ans += e[i].w;
        }
        cout << ans;
    } else if(m <= 1e5) {
        ll ans = 1e18, res = 0;
        for(int o = 0, i, j, u, v; o < (1 << k) - 1; o ++) {
            tot = n; midx = m; res = 0;
            for(i = 1; i <= m; i ++) t[i] = e[i];
            for(i = 1; i <= n; i ++) fa[i] = i;
            for(i = 1; i <= k; i ++) {
                if((o >> (i - 1)) & 1) {
                    res += c[i];
                    for(int j = 1; j <= n; j ++)
                        t[++ midx] = {n + i, j, a[i][j]};
                }
            }
            sort(t + 1, t + midx + 1, cmp);
            for(i = 1; i <= midx; i ++) {
                u = find(t[i].u), v = find(t[i].v);
                if(u == v) continue;
                fa[u] = v;
                res += t[i].w;
            }
            ans = min(res, ans);
        }
        cout << ans;
    } else {
        ll ans = 0;
        for(int i = 1; i <= k; i ++) {
            for(int j = 1; j <= n; j ++) {
                e[++ m] = {n + i, j, a[i][j]};
            }
        }
        sort(e + 1, e + m + 1, cmp);
        for(int i = 1; i <= m; i ++) {
            int u = find(e[i].u), v = find(e[i].v);
            if(u == v) continue;
            // cerr << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
            fa[u] == v;
            ans += e[i].w;
            if(u > n) deg[u] ++, wei[u] += e[i].w;
            if(v > n) deg[v] ++, wei[v] += e[i].w;
        }
        for(int i = 1; i <= k; i ++)
            if(deg[i + n] == 1) ans -= c[i] + wei[i + n];
        cout << ans;
    }

    
}