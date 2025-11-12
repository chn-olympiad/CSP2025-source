#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k, a[20][N], s[20], fa[N], cnt, ans;
struct node {
    int u, v, w;
}e[M];
bool cmp(node p, node q) {
    return p.w < q.w;
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i = 1; i <= m; i++) scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
    for(int i = 1; i <= k; i++) {
        scanf("%lld", &s[i]);
        for(int j = 1; j <= n; j++) scanf("%lld", &a[i][j]);
    }
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(find(u) == find(v)) continue;
        cnt++, ans += w;
        fa[find(u)] = find(v);
        if(cnt == n - 1) {
            printf("%lld", ans);
            return 0;
        }
    }
}