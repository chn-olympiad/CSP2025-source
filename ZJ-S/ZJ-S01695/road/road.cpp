#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace Qiuyu3600 {
const int N = 1e4 + 100, M = 1e6 + 100, K = 12;
int n, m, k, c[K];
struct edge {int u, v, w; bool operator<(const edge &o) const {return w < o.w;};} ed0[M], ed1[K][N];
namespace dsu {
    int fa[N];
    void init() {for(int i = 1; i <= n + k; i ++) fa[i] = i;}
    int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
    bool merge(int u, int v) {
        if((u = find(u)) == (v = find(v))) return false;
        return fa[v] = u, true;
    }
}
edge ed[K][N * K]; int sz[K];
void merge(int d) {
    int i = sz[d], j = n, k = sz[d - 1] = sz[d] + n;
    while(i && j) {
        if(ed[d][i] < ed1[d][j]) ed[d - 1][k --] = ed1[d][j --];
        else ed[d - 1][k --] = ed[d][i --];
    }
    while(i) ed[d - 1][k --] = ed[d][i --];
    while(j) ed[d - 1][k --] = ed1[d][j --];
}
ll calc(int tot) {
    ll res = 0;
    dsu::init();
    for(int i = 1, c = 1; c < tot; i ++)
        if(dsu::merge(ed[0][i].u, ed[0][i].v)) res += ed[0][i].w, c ++;
    return res;
}
ll ans;
void dfs(int d, int tot, ll cur) {
    if(!d) return void(ans = min(ans, cur + calc(tot)));
    sz[d - 1] = sz[d]; for(int i = 1; i <= sz[d - 1]; i ++) ed[d - 1][i] = ed[d][i];
    dfs(d - 1, tot, cur);
    merge(d);
    dfs(d - 1, tot + 1, cur + c[d]);
}
void Hutao() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++)
        cin >> ed0[i].u >> ed0[i].v >> ed0[i].w;
    sort(ed0 + 1, ed0 + m + 1);
    dsu::init();
    for(int i = 1, c = 1; c < n; i ++)
        if(dsu::merge(ed0[i].u, ed0[i].v)) ed1[0][c ++] = ed0[i];
    for(int i = 1; i <= k; i ++) {
        cin >> c[i];
        for(int j = 1; j <= n; j ++)
            ed1[i][j].u = n + i, ed1[i][j].v = j, cin >> ed1[i][j].w;
        sort(ed1[i] + 1, ed1[i] + n + 1);
    }
    ans = ll(1e18);
    sz[k] = n - 1; for(int i = 1; i < n; i ++) ed[k][i] = ed1[0][i];
    dfs(k, n, 0ll);
    cout << ans;
}
}
int main() {
    #ifndef DB
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #endif
    int t = 1; while(t --) Qiuyu3600::Hutao();
    return 0;
}