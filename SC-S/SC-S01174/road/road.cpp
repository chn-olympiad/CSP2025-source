#include <bits/stdc++.h>
#define db(x...) fprintf(stderr,x)
typedef long long ll;
const int N = 2e4 + 10, M = 2e6 + 10, K = 20;
const ll inf = 1e18 + 10;
struct Node {
    int u, v, w;
}E[M], stk[M];
bool cmp (Node x, Node y) { return x.w < y.w; }
int c[N], a[K][N], p[N];
int fa[N], h[N];
int n, m, k;
int find (int u) {
    if (fa[u] == u) return u;
    return fa[u] = find (fa[u]);
}
void merge (int u, int v) {
    u = find (u), v = find (v);
    if (u == v) return ;
    if (h[u] < h[v]) std::swap (u, v);
    fa[v] = u;
    if (h[u] == h[v]) h[u]++;
}
ll work () {
    ll ans = 0;
    int tot = 0;
    for (int i = 1; i <= m; i++) stk[++tot] = E[i];
    for (int i = 1; i <= n + k; i++) fa[i] = i;
    for (int i = 1; i <= k; i++)
        if (p[i])
            for (int j = 1; j <= n; j++)
                stk[++tot] = (Node) {i + n, j, a[i][j]};
    for (int i = 1; i <= k; i++) if (p[i]) ans += c[i];
    std::sort (stk + 1, stk + tot + 1, cmp);
    for (int i = 1; i <= tot; i++) {
        int u = stk[i].u, v = stk[i].v, w = stk[i].w;
        if (find (u) == find (v)) continue;
        ans += w;
        merge (u, v);
    }
    return ans;
}
ll ans = inf;
void dfs (int step) {
    if (step > k) {
        ans = std::min (ans, work ());
        return ;
    }
    dfs (step + 1);
    p[step] = 1;
    dfs (step + 1);
    p[step] = 0;
}
int main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf ("%d%d%d", &u, &v, &w);
        E[i] = (Node) {u, v, w};
    }
    for (int i = 1; i <= k; i++) {
        scanf ("%d", &c[i]);
        for (int j = 1; j <= n; j++) scanf ("%d", &a[i][j]);
    }
    dfs (1);
    printf ("%lld\n", ans);
    fclose (stdin);
    fclose (stdout);
    return 0;
}