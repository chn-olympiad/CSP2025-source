#include <bits/stdc++.h>
using namespace std; bool _bg;
int n, m, k;
namespace S1 {
    int f[10020];
    inline int fnd(int x){
        return x == f[x]? x : f[x] = fnd(f[x]);
    }
    int c[12], a[12][10010];
    void sol1(){
        vector<tuple<int, int, int> > E;
        while (m--){
            int u, v, w;
            cin >> u >> v >> w;
            E.emplace_back(w, u, v);
        }
        sort(E.begin(), E.end());
        iota(f + 1, f + n + 1, 1);
        vector<tuple<int, int, int> > cs;
        for (auto uvw : E){
            int u = get<1>(uvw);
            int v = get<2>(uvw);
            int x = fnd(u), y = fnd(v);
            if (x ^ y){
                f[x] = y;
                cs.emplace_back(uvw);
            }
        }
        for (int i = 1; i <= k; ++i){
            cin >> c[i];
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j], cs.emplace_back(a[i][j], i + n, j);
        }
        // for (auto [w, u, v] : cs)clog << u << "," << v << "," << w << endl;
        sort(cs.begin(), cs.end());//1e4+5e4=6e4
        long long rs = 1e18;
        for (int s = 0; s < 1 << (k + 1); s += 2){
            long long S = 0;
            iota(f + 1, f + n + k + 1, 1);
            for (auto uvw : cs){
                int u = get<1>(uvw);
                if (u > n && (~s >> (u - n) & 1))continue;
                int v = get<2>(uvw);
                int x = fnd(u), y = fnd(v);
                if (x ^ y){
                    f[x] = y;
                    S += get<0>(uvw);
                }
            }
            for (int i = 1; i <= k; ++i)if (s >> i & 1)S += c[i];
            rs = min(rs, S);
        }
        cout << rs << endl;
        exit(0);
    }
}
bool _ed; int main(){
    double mmus = fabs(&_ed - &_bg) / 1024 / 1024;
    assert(mmus < 256); clog << mmus << "M" << endl;
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    // if (k <= 5)
    S1::sol1();
    return 0;
}