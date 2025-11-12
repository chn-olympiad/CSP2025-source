#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define REP(i, a, b) for(int i = (int)(a); i <= (int)(b); i ++)
#define DOW(i, a, b) for(int i = (int)(a); i >= (int)(b); i --)
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define poly vector<int>
#define polyp vector<pii>
const int N = 1e5 + 5;
int n, m, k, tot, cnt, f[N], p[50], a[30][N];
int res[N];
// polyp e[N];
struct edge {
    int u, v, w;
    bool operator < (const edge& t) const {
        return w < t.w;
    }
};
edge e[N * 10], g[N * 10], G[N], F[1024][10005];
int pos[1024];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
void Solve() {
    cin >> n >> m >> k;
    REP(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    REP(i, 1, k) {
        cin >> p[i];
        REP(j, 1, n) cin >> a[i][j];
    }
    sort(e + 1, e + m + 1);
    REP(i, 1, n) f[i] = i;
    REP(i, 1, m) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        u = find(u), v = find(v);
        if(u == v) continue;
        f[u] = v, g[++ tot] = e[i];
    }
    long long bans = 1e18;
    REP(S, 0, (1 << k) - 1) {
        cnt = 0;
        long long ans = 0;
        // REP(i, 1, n) res[i] = 1e18;
        REP(i, 1, k) 
            if(S >> i - 1 & 1) 
                ans += p[i];
        REP(i, 1, k) {
            if(S >> i - 1 & 1) {
                REP(j, 1, n) 
                    G[++ cnt] = {n + i, j, a[i][j]};
                REP(j, 1, pos[S ^ (1 << i - 1)])
                    G[++ cnt] = F[S ^ (1 << i - 1)][j];
                break;
            }
        }
        // REP(i, 1, n) if(res[i] != 1e18) G[++ cnt] = {n + 1, i, res[i]};
        REP(i, 1, tot) G[++ cnt] = g[i];
        REP(i, 1, n + k) f[i] = i;
        stable_sort(G + 1, G + cnt + 1);
        REP(i, 1, cnt) {
            int u = G[i].u, v = G[i].v, w = G[i].w;
            u = find(u), v = find(v);
            if(u == v) continue;
            f[u] = v, ans += w;
            if(u > n || v > n) F[S][++ pos[S]] = G[i];
        }
        // if(S == 0) cerr << ans << '\n';
        bans = min(ans, bans);
    }
    cout << bans << '\n';
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}