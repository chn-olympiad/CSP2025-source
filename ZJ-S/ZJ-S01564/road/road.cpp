#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    int u, v;
    ll w;
};

struct BCJ {
    int n;
    vector<int> fa;

    void init(int _n) {
        n = _n;
        fa.resize(n);
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }

    int find(int u) {
        if (u == fa[u]) return u;
        return fa[u] = find(fa[u]);
    }

    bool connected(int u, int v) {
        return find(v) == find(u);
    }

    void merge(int u, int v) {
        fa[find(v)] = find(u);
    }
};

bool comp(const edge& i, const edge& j) {
    return i.w <= j.w;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll> > a(n, vector<ll>(n, INT_MAX));
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        a[u][v] = a[v][u] = min(a[u][v], w);
    }
    for (int i = 0; i < k; ++i) {
        ll c;
        cin >> c;

        vector<ll> d(n);
        for (int j = 0; j < n; ++j) {
            cin >> d[j];
            for (int l = 0; l < j; ++l) {
                ll w = d[l] + d[j] + c;
                a[l][j] = a[j][l] = min(a[j][l], w);
            }
        }
    }

    vector<edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i][j] != INT_MAX) {
                edge temp = {i, j, a[i][j]};
                edges.push_back(temp);
            }
        }
    }

    sort(edges.begin(), edges.end(), comp);

    int cnt = 0;
    ll res = 0;
    BCJ s;
    s.init(n);
    for (const edge& e : edges) {
        int u = e.u, v = e.v;
        ll w = e.w;
        
        if (s.connected(u, v)) continue;
        cnt++;
        res += w;
        s.merge(u, v);
        
        if (cnt == n - 1) break;
    }

    cout << res << '\n';

    return 0;
}
