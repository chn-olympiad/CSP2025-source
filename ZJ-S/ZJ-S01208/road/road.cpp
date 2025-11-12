#include<bits/stdc++.h>
using namespace std; 

namespace Main {

#define int long long 
#define ld long double
#define all(x) begin(x), end(x) 
#define rep(i, l, r) for(int i(l), END##i(r); i <= END##i; ++ i) 
#define per(i, r, l) for(int i(r), END##i(l); i >= END##i; -- i) 

const int inf = 0x3f3f3f3f3f3f3f3f; 

template<class T>
inline void cmax(T& x, const T& y) { x = max(x, y); }
template<class T>
inline void cmin(T& x, const T& y) { x = min(x, y); }

const int N = 2e4 + 10, M = 12;  

int n, m, K; 
vector<tuple<int, int, int> >eg; 
int c[M], db[M]; 
int a[M][N]; 

struct Dsu {
    int fa[N], siz[N]; 
    void init(int len) {
        iota(fa, fa + len + 1, 0); 
        fill(siz, siz + len + 1, 1); 
    } 
    int find(int x) {
        while (x ^ fa[x]) 
            x = fa[x] = fa[fa[x]]; 
        return x; 
    } 
    bool merge(int u, int v) {
        u = find(u); v = find(v); 
        if (u == v) return 0; 
        if (siz[u] > siz[v]) swap(u, v); 
        fa[u] = v; siz[v] += siz[u]; 
        return 1; 
    }
}d; 

void MST(int ndct, vector<tuple<int, int, int> >& edge) {
    static vector<tuple<int, int, int> >used; 
    used.clear(); 
    d.init(ndct); 
    for (auto [w, u, v] : edge) 
        if (d.merge(u, v)) 
            used.emplace_back(w, u, v); 
    edge.swap(used); 
} 

int ans;
vector<tuple<int, int, int> >nweg, reg; 
void Combine() {
    int i = 0, j = 0; 
    reg.clear(); 
    while (i < eg.size() && j < nweg.size()) 
        if (get<0>(eg[i]) < get<0>(nweg[j])) 
            reg.emplace_back(eg[i ++]); 
        else reg.emplace_back(nweg[j ++]); 
    while (i < eg.size()) 
        reg.emplace_back(eg[i ++]); 
    while (j < nweg.size()) 
        reg.emplace_back(nweg[j ++]); 
}
void solve() {
    rep(i, 1, (1 << K) - 1) {
        int ndct = n + 1, res = 0; 
        nweg.clear(); 
        rep(j, 1, K) if ((i >> (j - 1)) & 1) {
            res += c[j] + a[j][db[j]]; 
            rep(t, 1, n) 
                nweg.emplace_back(a[j][t], t, db[j]); 
        } 
        sort(all(nweg)); 
        Combine(); 
        MST(ndct, reg); 
        for (auto [w, u, v] : reg) 
            res += w; 
        // if (res == 5179873076) {
        //     printf ("get : %lld\n", K); 
        //     rep(j, 1, K) if ((i >> (j - 1)) & 1)
        //         printf ("%lld ", j); 
        //     puts(""); 
        // }
        cmin(ans, res); 
    }
}

void ERoRain() {
    scanf ("%lld%lld%lld", &n, &m, &K); 
    rep(i, 1, m) {
        int u, v, w; 
        scanf ("%lld%lld%lld", &u, &v, &w); 
        eg.emplace_back(w, u, v); 
    } 
    rep(i, 1, K) {
        scanf ("%lld", c + i); 
        db[i] = 1; 
        rep(j, 1, n) {
            scanf ("%lld", a[i] + j); 
            if (a[i][j] < a[i][db[i]]) 
                db[i] = j; 
        }
    }
    sort(all(eg));
    MST(n, eg); 
    for (auto [w, u, v] : eg) ans += w; 
    solve(); 
    printf ("%lld\n", ans); 
}

signed main() {
    ld start_time = clock(); 
    int T = 1; 
    while (T --) ERoRain(); 
    fprintf (stderr, "Time : %Lf\n", (clock() - start_time) / CLOCKS_PER_SEC); 
    return 0; 
}

} signed main() {
    freopen("road.in", "r", stdin); 
    freopen("road.out", "w", stdout); 
    Main::main(); 
    return 0; 
}