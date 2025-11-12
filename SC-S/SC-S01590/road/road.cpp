#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+4, S=1026; // mind! s is biger than 1003
#define pb push_back
#define For(i, s, e) for(int i = (s); i <= (e); ++i)
#define ifor(i, s, e) for(int i = (s); i >= (e); --i)
inline ll read() {
    ll x(0); bool f(0); char ch = getchar();
    while(!isdigit(ch)) f = ch == '-', ch = getchar();
    while(isdigit(ch)) x = x * 10 + (ch^48), ch = getchar();
    return f ? -x : x;
}
inline void wt(ll x, bool md=1) {
    if(x < 0) putchar('-'), x = -x;
    short stack[64], top(0);
    do stack[++ top] = x % 10, x /= 10; while(x);
    while(top) putchar(stack[top --] | 48);
    md ? putchar('\n') : putchar(' ');
}
bool mst;
struct node{ll fi; int se;}a[N];
struct Edge{int u, v; ll w; inline bool operator<(const Edge&v)const{return w<v.w;}};
typedef vector < Edge > vi;
int n, m, k, U;
vi e[S];
void merge(vi &u, vi &v, vi &a) {
    vi tmp;
    int n = u.size(), m = v.size(); // I think is n - 1
    for(int i = 0, j = 0; i < n || j < m; ) {
        if((j >= m) || (i < n && u[i].w < v[j].w)) tmp.pb(u[i]), ++ i;
        else tmp.pb(v[j]), ++ j;
    } swap(tmp, a);
} // mind! u may equal to a
int fa[N];
inline int find(int x) {return x ^ fa[x] ? fa[x] = find(fa[x]) : x;}
void init(int n) {For(i, 1, n) fa[i] = i;} 
ll MST(vi &e) {
    init(n); vi tmp; ll res(0); int cnt(0);
    for(auto x : e) {
        int u = x.u, v = x.v; ll w = x.w;
        if(find(u) != find(v)) {
            fa[find(u)] = find(v);
            res += w;
            tmp.pb(x);
            if(++ cnt == n - 1) {swap(e, tmp); return res;}
        }
    } swap(e, tmp); return res;
}
ll ans, c[S];
bool med;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = read(), m = read(), k = read(), U = (1 << k) - 1;
    For(i, 1, m) {
        int u = read(), v = read(); ll w = read();
        e[0].pb({u, v, w});
    }
    sort(e[0].begin(), e[0].end());
    ans = MST(e[0]); // swap
    // wt(ans);
    // for(auto [u, v, w] : e[0]) printf("%d %d %lld\n", u, v, w);
    For(i, 0, k - 1) {
        c[1 << i] = read(); int id;
        For(j, 1, n) a[j] = {read(), j}; // mind j not i
        sort(a + 1, a + n + 1, [](const node&u, const node&v){return u.fi < v.fi;});
        c[1 << i] += a[1].fi, id = a[1].se;
        For(j, 2, n) {
            e[1 << i].pb({id, a[j].se, a[j].fi});
        }
        // printf("view %d, cnt = %lld\n", i + 1, c[1 << i]);
        // for(auto [u, v, w] : e[1 << i]) printf("%d %d %lld\n", u, v, w);
    }
    For(s, 1, U) {
        int id = s & (-s);
        merge(e[s ^ id], e[id], e[s]);
        c[s] = c[s ^ id] + c[id];
        // printf("view %d, cnt = %lld\n", s, c[s]);
        // for(auto [u, v, w] : e[s]) printf("%d %d %lld\n", u, v, w);
        ans = min(ans, c[s] + MST(e[s])); // c[s] not c[id]
    }
    wt(ans);
    cerr << fabs(&mst - &med) / 1024 / 1024 << " MB\n";
    return 0;
}