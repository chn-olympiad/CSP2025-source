#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef array<int, 3> ai3;

const int K = 15, N = 1e4 + 5;

struct DSU{
    vector<int> f;
    DSU(int n) : f(n) {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    bool merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if(fa == fb) return false;
        f[fa] = fb;
        return true;
    }
};

vector<ai3> edge, ED;

int c[K], a[K][N];


signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k; cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }

    for(int i=1; i<=k; i++) {
        cin >> c[i];
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }

    ll res = 1e18;
    for(int S=0; S<(1<<k); S++) {
        ll ans = 0;
        ED = edge;
        for(int i=0; i<k; i++) {
            if(S >> i & 1) {
                ans += c[i+1];
                for(int j=1; j<=n; j++) {
                    ED.push_back({a[i+1][j], n+i+1, j});
                }
            }
        }

        cout << ans << "? \n";
        DSU ddf(n + k + 1);
        sort(ED.begin(), ED.end());

        for(auto x : ED) {
            int w = x[0], u = x[1], v = x[2];
            // cout << u << " " << v << " " << w << "\n";
            if(ddf.merge(u, v)) {
                ans += w;
            }
        }
        cout << ans << "!\n";
        res = min(res, ans);
    }

    cout << res << "\n";
    return 0;
}