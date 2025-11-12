#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10055, M = 2000005;
int n, m, k;
struct Edge {
    int u, v; ll w;
    bool operator<(const Edge& o) const {
        return w < o.w;
    }
} e[M], tr[N], ee[M];
int etot;
ll c[11], a[11][N];
int bfa[N];
int findf(int u) { return u == bfa[u] ? u : bfa[u] = findf(bfa[u]); }
ll sum, ans;
int sel[11];
void Solve() {
    ll now = 0;
    for (int i = 1; i < n; ++i) ee[i] = tr[i];
    etot = n - 1;
    for (int i = 1; i <= n; ++i) bfa[i] = i;
    for (int i = 1; i <= k; ++i) 
        if (sel[i]) {
            now += c[i];
            ll mn = a[i][1]; int uid = 1;
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] < mn) mn = a[i][j], uid = j;
            }
            now += mn;
            for (int j = 1; j <= n; ++j)
                if (j != uid) ee[++etot] = { uid, j, a[i][j] };
        }
    sort(ee + 1, ee + etot + 1);
    for (int i = 1; i <= etot; ++i) {
        int u = ee[i].u, v = ee[i].v;
        int fu = findf(u), fv = findf(v);
        if (fu != fv) {
            bfa[fu] = fv;
            now += ee[i].w;
        }
    }
    ans = min(ans, now);
}
void DFS(int u) {
    if (u == k + 1) return Solve();
    DFS(u + 1), sel[u] = 1, DFS(u + 1), sel[u] = 0;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; ++i) bfa[i] = i;
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v;
        int fu = findf(u), fv = findf(v);
        if (fu != fv) {
            bfa[fu] = fv;
            sum += e[i].w;
            tr[++etot] = e[i];
        }
    }
    ans = sum;
    DFS(1);
    cout << ans << '\n';
    return 0;
}