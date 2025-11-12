#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define P emplace_back
bool MBE;
namespace SOLVER {
const int N = 1e4 + 25, inf = 2e9;
int n, m, K, f[N], sz[N], c[15]; ll ans = 1e18;
struct Edge {int u, v, w;}; bool cmp(Edge x, Edge y) {return x.w < y.w;}
vector<Edge> g1, g2, a[15];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
bool merge(int u, int v) {
    if((u = find(u)) == (v = find(v))) return 0;
    if(sz[u] > sz[v]) swap(u, v); f[u] = v, sz[v] += sz[u]; return 1;
}
void dfs(int p, vector<Edge> cur, ll ss) {
    if(p > K) {
        ll sum = 0; for(auto x : cur) sum += x.w;
        ans = min(ans, sum + ss); return;
    }
    dfs(p + 1, cur, ss); vector<Edge> res = cur; cur.clear();
    rep(i, 1, n + K) f[i] = i, sz[i] = 1; int p1 = 0, p2 = 0;
    while(p1 < res.size() || p2 < a[p].size()) {
        int v1 = p1 >= res.size() ? inf : res[p1].w, v2 = p2 >= a[p].size() ? inf : a[p][p2].w;
        Edge ret; if(v1 < v2) ret = res[p1++]; else ret = a[p][p2++];
        if(merge(ret.u, ret.v)) cur.P(ret);
    }
    dfs(p + 1, cur, ss + c[p]);
}
void MAIN() {
    cin >> n >> m >> K; 
    rep(i, 1, m) {int u, v, w; cin >> u >> v >> w; g1.P(Edge{u, v, w});}
    sort(g1.begin(), g1.end(), cmp); rep(i, 1, n + K) f[i] = i, sz[i] = 1; 
    g2.reserve(n); for(auto x : g1) if(merge(x.u, x.v)) g2.P(x);
    rep(i, 1, K) {
        cin >> c[i]; rep(j, 1, n) {int w; cin >> w; a[i].P(Edge{n + i, j, w});}
        sort(a[i].begin(), a[i].end(), cmp);
    }
    dfs(1, g2, 0); cout << ans << endl;
}
}
bool MED;
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    SOLVER::MAIN();
    cerr << (&MBE - &MED) / 1024 << " kb, " << clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
} // gfdg