#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e4+7, maxm = 1e6+7, maxk = 17;            // change
int n, m, k;
struct edge {
    int u, v, w;
    bool operator<(edge const &p) const {
        return w < p.w;
    }
} e[maxm], es[maxn * maxn];
int g[maxn][maxn];
int c[maxk];
int a[maxk][maxn];
bool b[maxn];
int ans;
int f[maxn];

int find(int u) {
    return (f[u] == u ? u : f[u] = find(f[u]));
}

int mst(void) {
    for (int i = 1; i <= n; i++)
        f[i] = i;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            es[++cnt] = {i, j, g[i][j]};
    sort(es + 1, es + cnt + 1);
    int q = 0, ret = 0;
    for (int i = 1; i <= cnt; i++) {
        int& u = es[i].u, v = es[i].v, w = es[i].w;
        u = find(u);
        v = find(v);
        if (u == v)
            continue;
        f[u] = v;
        q++;
        ret += w;
        if (q == n - 1)
            return ret;
    }
    return LLONG_MAX - INT_MAX;
}

// line 5 needs change

void dfs(int l) {
    if (l == k + 1) {
        int ret = 0;
        memset(g, 0x3f, sizeof g);
        for (int i = 1; i <= n; i++)
            g[i][i] = 0;
        for (int i = 1; i <= m; i++)
            g[e[i].u][e[i].v] = min(g[e[i].u][e[i].v], e[i].w);
        for (int i = 1; i <= k; i++) {
            if (!b[i])
                continue;
            for (int u = 1; u <= n; u++)
                for (int v = 1; v <= n; v++)
                    g[u][v] = min(g[u][v], a[i][u] + a[i][v]);
            ret += c[i];
        }
        ans = min(ans, mst() + ret);
        return;
    }
    if (c[l]) {
        b[l] = 0;
        dfs(l + 1);
    }
    b[l] = 1;
    dfs(l + 1);
    return;
}

signed main(signed argc, char const *argv[]) {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    ans = INT_MAX;
    dfs(1);
    cout << ans << endl;
    return 0;
}