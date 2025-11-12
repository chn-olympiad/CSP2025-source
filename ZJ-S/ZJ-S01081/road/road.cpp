// GEI LAO ZI GUO!!!
// BU YAO BEI KA CHANG!!!
// pls QAQ
#include <bits/stdc++.h>
using namespace std;
#define getchar getchar_unlocked
const int maxn = 10005, maxm = 1e6 + 5, maxk = 15;
int a[maxk][maxn], c[maxn], n, m, k;
struct Edge {
    int u, v, w;
    bool operator<(const Edge &oth) const {
        return w < oth.w;
    }
} e[maxm], pub[maxn], spc[maxk][maxn], cur[maxn * maxk];
// rp++
inline int read() {
    char c = getchar(); int f = 1;
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-') f = -f;
    int res = 0;
    for (; c >= '0' && c <= '9'; c = getchar())
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res;
}
#define mk make_pair
#define ll long long
#define open(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
int fa[maxn + maxk];
void init() { for (int i = 1; i <= n + k; i ++) fa[i] = i; }
int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
void mrg(int u, int v) { fa[find(u)] = find(v); }
ll solve(Edge *r, int n, int m, bool tp = 0) {
    ll ans = 0; init();
    for (int i = 1, cnt = 0; cnt < n - 1 && i <= m; i ++) {
        int u = r[i].u, v = r[i].v, w = r[i].w;
        if (find(u) == find(v)) continue;
        cnt ++; if (tp) pub[cnt] = r[i];
        mrg(u, v), ans += w;
    } return ans;
}
int main() { open(road);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i ++) e[i].u = read(), e[i].v = read(), e[i].w = read();
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= k; i ++) {
        c[i] = read();
        for (int j = 1, w; j <= n; j ++)
            w = read(), spc[i][j] = Edge { i + n, j, w };
        sort(spc[i] + 1, spc[i] + n + 1);
    }
    ll ans = solve(e, n, m, 1); int lim = (1 << k);
    // cerr << ans << '\n';
    for (int s = 1; s < lim; s ++) {
        ll p = 0; int len = n - 1, tot = n;
        for (int i = 1; i < n; i ++) cur[i] = pub[i];
        for (int i = 1; i <= k; i ++) if (s & (1 << i - 1)) {
            tot ++, p += c[i], merge(cur + 1, cur + len + 1, spc[i] + 1, spc[i] + n + 1, e + 1);
            len += n; for (int j = 1; j <= len; j ++) cur[j] = e[j];
        } ans = min(ans, p + solve(cur, tot, len));
    } printf("%lld\n", ans);
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/