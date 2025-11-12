#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();i++)
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=c)
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define MOD(a)   (((a)%mod+mod)%mod)
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=MOD((a)-(b))
#define MUL(a,b) (a)=MOD((a)*(b))
#define SZ(a)    ((int)(a).size())
#define ALL(a)   (a).begin(),(a).end()
#define ppc(a)   __builtin_popcountll(a)
#define DBG(a)     cout<<#a<<": "<<a<<endl
#define AST(a,l,r) assert(a>=l),assert(a<=r)
#define int long long
using namespace std;

namespace Yyydrasil {

    const int N = 1e4 + 10 + 5, M = 1e6 + 5, K = 10 + 5;
    struct E { int u, v, w, flag; } edge[M];
    int n, m, k, u, v, w, c[K], ans;

    int fa[N], sz[N];
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    int kruskal(int p) {
        int res = 0;
        REP(i, 1, n + k) fa[i] = i, sz[i] = 1;
        REP(i, 1, m) {
            int u = find(edge[i].u);
            int v = find(edge[i].v);
            if (u != v && (edge[i].u > n ? ((p >> (edge[i].u - n - 1)) & 1) : true)) {
                if (sz[u] > sz[v]) swap(u, v);
                fa[u] = v;
                sz[v] += sz[u];
                edge[i].flag = true;
                res += edge[i].w;
            }
        }
        return res;
    }

    void main() {
        cin >> n >> m >> k;
        REP(i, 1, m) {
            cin >> u >> v >> w;
            edge[i] = {u, v, w, false};
        }
        sort(edge + 1, edge + 1 + m, [](E a, E b) { return a.w < b.w; });
        ans = kruskal(0);
        int tot = 0;
        REP(i, 1, m) {
            if (edge[i].flag) {
                edge[++tot] = edge[i];
            }
        }
        m = tot;
        REP(i, 1, k) {
            cin >> c[i];
            REP(j, 1, n) {
                cin >> w;
                edge[++m] = {n + i, j, w, false};
            }
        }
        sort(edge + 1, edge + 1 + m, [](E a, E b) { return a.w < b.w; });
        REP(p, 0, (1 << k) - 1) {
            int res = 0;
            REP(i, 1, k) res += ((p >> (i - 1)) & 1) * c[i];
            MIN(ans, res + kruskal(p));
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
