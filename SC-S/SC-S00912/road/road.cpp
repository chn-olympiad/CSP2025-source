/* start road */ 
#include<bits/stdc++.h>
#define fup(i, bg, ed) for(int i = (bg); i <= (ed); i++)
#define fdn(i, bg, ed) for(int i = (bg); i >= (ed); i--)
typedef long long lld;
using namespace std;

struct AutoIO {
    AutoIO() {
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    ~AutoIO() {
        cout.flush();
        #ifdef Local
        cerr << 1. * clock() / CLOCKS_PER_SEC << "ms" << "\n";
        #endif
    }
}__cdl_auto_io;

const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 12;

int n, m, k;
struct Edge {
    int u, v, w, tp;
    friend bool operator < (const Edge& l, const Edge& r) {
        return l.w < r.w;
    }
};

vector<Edge> E, mst;
int c[K];
int f[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void init(int n) { iota(f + 1, f + n + 1, 1); }

main() {
    cin >> n >> m >> k;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        E.push_back({ u, v, w, 0 });
    }
    sort(E.begin(), E.end());
    init(n);
    lld ans = 0;
    for(auto[u, v, w, _] : E) {
        if(find(u) != find(v)) {
            f[find(u)] = find(v);
            ans += w;
            mst.push_back({ u, v, w, 0 });
        }
    }
    fup(i, 1, k) {
        cin >> c[i];
        fup(j, 1, n) {
            int w;
            cin >> w;
            mst.push_back({ i+n, j, w, i });
        }
    }

    sort(mst.begin(), mst.end());

    // cerr << ans << endl;
    for(int S = 0; S < 1 << k; S++) {
        lld res = 0;
        fup(i, 1, k) if(S >> (i-1) & 1) res += c[i];
        init(n + k);
        for(auto[u, v, w, tp] : mst) if(!tp || (S >> (tp-1) & 1)) {
            if(find(u) != find(v)) {
                res += w;
                f[find(u)] = find(v);
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;

}

/* finish road */ 