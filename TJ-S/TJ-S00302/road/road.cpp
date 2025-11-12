#include <bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, f = 1, c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') f = -1, c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
    return f == 1 ? x : -x;
}

#define ll long long

const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 10 + 2;
ll ans = 0, cost[K];
int n, m, k, tot, a[N], fa[N], sz[N], attach[K];
struct Edge {
    int u, v, w;
    bool isadd;
    bool operator<(const Edge & r) const {
        return w < r.w;
    }
} edge[M], e[M];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y;
    sz[y] += sz[x];
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(); m = read(); k = read();
    for (int i = 1; i <= m; i++) edge[i].u = read(), edge[i].v = read(), edge[i].w = read();
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (find(u) != find(v)) {
            merge(u, v);
            e[++tot] = {u, v, w, false};
            ans += w;
        }
    }
    for (int i = 0; i < k; i++) {
        cost[i] = read();
        for (int j = 1; j <= n; j++) a[j] = read();
        int mn = *min_element(a + 1, a + n + 1), id = 0;
        cost[i] += mn;

        for (int j = 1; j <= n; j++) if (!id && a[j] == mn) {
            id = j;
        } else {
            e[++tot] = {i, j, a[j], true};
        }
        attach[i] = id;
        //printf("%d %d %lld\n", i, attach[i], cost[i]);
    }

    //printf("tot:%d ans:%lld\n", tot, ans);
    sort(e + 1, e + tot + 1);
    for (int mask = 1; mask < 1 << k; mask++) {
        for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
        ll cur = 0;
        for (int i = 0; i < k; i++) if (mask >> i & 1) cur += cost[i];
        for (int i = 1; i <= tot; i++) {
            int u, v, w;
            if (e[i].isadd) {
                if (!(mask >> e[i].u & 1)) continue;
                u = attach[e[i].u];
                v = e[i].v;
                w = e[i].w;
            } else {
                u = e[i].u;
                v = e[i].v;
                w = e[i].w;
            }
            if (find(u) != find(v)) {
                merge(u, v);
                cur += w;
            }
        }
        ans = min(ans, cur);
    }
    printf("%lld\n", ans);
    return 0;
}

