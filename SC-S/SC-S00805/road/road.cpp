#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+15, M = 2e6;
int n, m, cnt = 0, fa[N];
struct edge {
    int u, v, w;
} e[M];
inline void adde(int u, int v, int w) {
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    return ;
}
inline int find(int u) {
    if (fa[u] == fa[fa[u]])
        return fa[u];
    return fa[u] = find(fa[u]);
}
inline void merge(int u, int v) {
    int fa1 = find(u),
        fa2 = find(v);
    fa[fa1] = fa[fa2];
    return ;
}
inline int ku() {
    int w = 0, cnt = 0;
    for (int i = 1; i <= m; i++)
        if (find(e[i].u) != find(e[i].v)) {
            w += e[i].w;
            cnt++;
            merge(e[i].u, e[i].v);
            if (cnt == n - 1)
                break;
        }
    return w;
}
inline bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adde(u, v, w);
    }
    for (int i = 0; i < n; i++) {
        int vv, d;
        scanf("%d", &vv);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &d);
            adde(1e4+1 + i, j, d);
        }
    }
    sort(e + 1, e + 1 + n, cmp);
    printf("%d", ku());
    return 0;
}