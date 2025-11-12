/*
start at 15:02
finish at 15:24
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10020, M = 1000100, K = 10;
int n, m, k;
struct Edge{
    int u, v, w;
    void rdin() {scanf("%d%d%d", &u, &v, &w);}
    Edge() {}
    Edge(int x, int y, int z)
        : u(x), v(y), w(z) {}
    bool operator<(const Edge &_)const{
        return w < _.w;
    }
} G[M], a[1 << K][N], Gp[K][N];
int ln[1 << K], Lg[1 << K];
int fa[N], b[K];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
ll ans = 4e18;
void init() {
    sort(G + 1, G + m + 1);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    ll ret = 0;
    for (int i = 1; i <= m; ++i) {
        int x = G[i].u, y = G[i].v, w = G[i].w, fx = find(x), fy = find(y);
        if (fx == fy) continue;
        fa[fx] = fy, a[0][++ln[0]] = G[i], ret += w;
    }
    if (ln[0] == n - 1) ans = min(ans, ret);
    return;
}
void sov(int S) {
    int u = Lg[-S & S], T = S - (-S & S);
    m = 0;
    for (int i = 1, j = 1; i <= ln[T] || j <= n; ) {
        if (j > n || i <= ln[T] && a[T][i] < Gp[u][j]) G[++m] = a[T][i], ++i;
        else G[++m] = Gp[u][j], ++j;
    }
    ll ret = 0;
    for (int i = 0; i < k; ++i) if (S >> i & 1) ret += b[i];
    for (int i = 1; i <= n + k; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        int x = G[i].u, y = G[i].v, w = G[i].w, fx = find(x), fy = find(y);
        if (fx == fy) continue;
        fa[fx] = fy, a[S][++ln[S]] = G[i], ret += w;
    }
    if (ln[S] == n + __builtin_popcount(S) - 1 && ret < ans) ans = ret;
    return;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) G[i].rdin();
    for (int i = 0; i < k; ++i) {
        scanf("%d", b + i), Lg[1 << i] = i;
        for (int j = 1, x; j <= n; ++j) scanf("%d", &x), Gp[i][j] = Edge(n + i + 1, j, x);
        sort(Gp[i] + 1, Gp[i] + n + 1);
    }
    init();
    for (int S = 1; S < (1 << k); ++S) sov(S);
    printf("%lld\n", ans);
    return 0;
}