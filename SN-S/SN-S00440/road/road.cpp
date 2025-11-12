#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define pb push_back
#define bs basic_string
#define sz(v) (int)(v).size()
#define cir(x) rep(__tmp, 1, x)
#define rd(x) scanf("%d", &(x))
#define all(v) (v).begin(), (v).end()
#define erg(i, pre, x) for(int i = (pre)[x];i;i = a[i].next)
#define rep(i, l, r) for(int i = (l), _tmp = (r);i <= _tmp;i++)
#define per(i, l, r) for(int i = (l), _tmp = (r);i >= _tmp;i--)
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, INF_BIT = 0x3f;

const int N = 1e4 + 15, M = 1e6 + 10, K = 15;

int n, m, k;
int u, v, w;
int c[K], x;

struct Edge{ int u, v, w; };
Edge e[M + N * K];
int ei;

int fa[N];
int sz[N];
inline int find(int x){ return fa[x] == x ? x : fa[x] = find(fa[x]); }

inline LL kruskal(int st, int tot){
    iota(fa + 1, fa + n + k + 1, 1ll);
    fill(sz + 1, sz + n + k + 1, 1ll);
    LL ret = 0;
    int cnt = 0;
    rep(i, 1, ei){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        // printf("%d %d %d\n", u, v, w);
        if(v > n && ((st >> (v - n - 1)) & 1) == 0) continue;
        int fx = find(u), fy = find(v);
        if(fx != fy){
            if(sz[fx] > sz[fy]) swap(fx, fy);
            fa[fx] = fy;
            sz[fy] += sz[fx];
            ret += w;
            cnt++;
            if(cnt == tot - 1) break;
        }
    }
    return ret;
}

LL ans = INF;

void solve(){
    rd(n), rd(m), rd(k);
    rep(i, 1, m) rd(u), rd(v), rd(w), e[++ei] = {u, v, w};
    rep(i, 1, k){
        rd(c[i]);
        rep(j, 1, n) rd(x), e[++ei] = {j, n + i, x};
    }
    
    sort(e + 1, e + ei + 1, [](Edge a, Edge b){return a.w < b.w;});
    rep(st, 0, (1 << k) - 1){
        LL s = 0;
        int tot = n;
        rep(i, 0, k - 1) if((st >> i) & 1) s += c[i + 1], tot++;
        // printf("st=%d s=%d kru=%d\n", st, s, kruskal(st, tot));
        ans = min(ans, s + kruskal(st, tot));
    }
    
    printf("%lld\n", ans);
}

int main(){
    // freopen("road3.in", "r", stdin);  //std=
    // freopen("road3.out", "w", stdout);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    solve();
    return 0;
}
