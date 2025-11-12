#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 15, M = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, k, nm, fa[N], c[15];
ll ans = inf, now;
bool ok[N];
struct edges {
    int u, v, w;
}e[M], ne[M];
inline void read(int &x) {
    x = 0;
    char c = getchar();
    while('0' > c || c > '9') c = getchar();
    while('0' <= c && c <= '9') {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
}
inline int getfa(int x) {
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
inline bool Merge(int x, int y) {
    x = getfa(x), y = getfa(y);
    if(x == y) return false;
    fa[x] = y;return true;
}
inline void chkmin(ll &x, ll y) {
    if(x > y) x = y;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n), read(m), read(k);
    for(int i = 1; i <= m; i++) {
        read(e[i].u), read(e[i].v), read(e[i].w);
    }
    sort(e + 1, e + m + 1, [&](edges x, edges y) {return x.w < y.w;});
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        if(Merge(e[i].u, e[i].v)) {
            ne[++nm] = e[i];
            // cerr << "ok " << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
        }
    }
    for(int i = 1, w; i <= k; i++) {
        read(c[i]);
        for(int j = 1; j <= n; j++) {
            read(w);
            ne[++nm] = {i + n, j, w};
        }
    }
    m = nm;
    for(int i = 1; i <= m; i++) e[i] = ne[i];
    sort(e + 1, e + m + 1, [&](edges x, edges y) {return x.w < y.w;});
    for(int i = 1; i <= n; i++) ok[i] = true;
    // exit(0);
    int ct = 0, tar;
    for(int s = (1 << k) - 1; ~s; s--) {
        now = 0ll;
        tar = n + __builtin_popcount(s) - 1;
        for(int i = 1; i <= k; i++) {
            if(s >> i - 1 & 1) now += c[i], ok[n + i] = true;
            else ok[n + i] = false;
        }
        for(int i = 1; i <= n + k; i++) fa[i] = i;
        ct = 0;
        for(int i = 1; i <= m; i++) if(ok[e[i].u] && ok[e[i].v] && Merge(e[i].u, e[i].v)) {
            now += e[i].w, ct++;
            if(now >= ans || ct == tar) break ;
        }
        chkmin(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}