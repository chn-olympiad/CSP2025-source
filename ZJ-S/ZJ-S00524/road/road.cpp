#include <bits/stdc++.h>
// #define int long long
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define rep(i, x, y) for (int i = (x); i >= (y); i--)
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define pb emplace_back
#define all(v) (v).begin(), (v).end()
#define A3 array<int, 3>
using namespace std;
const int N = 1e4 + 100;
using ll = long long;
int n, m, k;
int fa[N], siz[N];
void init() {
    For (i, 1, n + k) fa[i] = i, siz[i] = 1;
    return;
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x != y) {
        if (siz[x] > siz[y]) swap(x, y);
        fa[x] = y; siz[y] += siz[x];
    }
    return;
}
struct ds {
    A3 e[N];
    int tot;
} t[1030];
pii g[11][N];
int w[11];
void Main() {
    cin >> n >> m >> k;
    vector<A3> edge;
    For (i, 1, m) {
        int x, y, z; cin >> x >> y >> z;
        edge.pb(A3{z, x, y});
    }
    sort(all(edge));
    init();
    ll sum = 0;
    for (auto [z, x, y] : edge) {
        if (find(x) != find(y)) {
            sum += z;
            merge(x, y);
            t[0].e[++t[0].tot] = A3{z, x, y};
        }
    }
    ll ans = sum;
    For (i, 1, k) {
        cin >> w[i];
        For (j, 1, n) {
            cin >> g[i][j].fi; g[i][j].se = j;
        }
        sort(g[i] + 1, g[i] + n + 1);
    }
    For (s, 1, (1 << k) - 1) {
        int p = __lg(s), ss = (s ^ (1 << p));
        p++;
        init();
        ll res = 0;
        For (i, 0, k - 1) {
            if ((s >> i) & 1) {
                res += w[i + 1];
            }
        }
        int now1 = 1, now2 = 1;
        while (now1 <= t[ss].tot || now2 <= n) {
            if (now1 > t[ss].tot) {
                int x = n + p, y = g[p][now2].se, z = g[p][now2].fi;
                if (find(x) != find(y)) {
                    res += z;
                    merge(x, y);
                    t[s].e[++t[s].tot] = A3{z, x, y};
                }
                now2++;    
            } else if (now2 > n) {
                auto [z, x, y] = t[ss].e[now1];
                if (find(x) != find(y)) {
                    res += z;
                    merge(x, y);
                    t[s].e[++t[s].tot] = A3{z, x, y};
                }
                now1++;
            } else if (t[ss].e[now1][0] < g[p][now2].fi) {
                auto [z, x, y] = t[ss].e[now1];
                if (find(x) != find(y)) {
                    res += z;
                    merge(x, y);
                    t[s].e[++t[s].tot] = A3{z, x, y};
                }
                now1++;              
            } else {
                int x = n + p, y = g[p][now2].se, z = g[p][now2].fi;
                if (find(x) != find(y)) {
                    res += z;
                    merge(x, y);
                    t[s].e[++t[s].tot] = A3{z, x, y};
                }
                now2++;                  
            }
        }
        assert(t[s].tot == n + __builtin_popcount(s) - 1);
        ans = min(ans, res);
    }
    cout << ans;
    return;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) Main();
    return 0;
}