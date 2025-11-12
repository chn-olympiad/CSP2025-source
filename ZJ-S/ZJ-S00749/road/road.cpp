#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 10005 , M = 1000005;
ll n, m, k , fa[N << 1] , c[15] , a[15][N] , lst = 0;
struct edge
{
    ll u , v , w;
    bool operator <(const edge &b) const
    {
        if(w != b.w) return w < b.w;
        if(u != b.u) return u < b.u;
        return v < b.v;
    }
};
set<edge> e;

ll find(ll x) { return fa[x] == x ? x : find(fa[x]);}

inline void add(ll x)
{
    for (ll i = 1; i <= n ; i++)e.insert({i, n + x, a[x][i]});
}

inline void del(ll x)
{
    for (ll i = 1; i <= n ; i++)e.erase({i, n + x, a[x][i]});
}

inline ll update(ll s)
{
    ll res = 0;
    for (ll i = 1; i <= k ; i++) if(s & (1 << (i - 1))) res += c[i];
    for (ll i = 1; i <= k ; i++) if((s & (1 << (i - 1))) ^ (lst & (1 << (i - 1))))
    {
        if(s & (1 << (i - 1))) add(i);
        else del(i);
    }
    lst = s;
    return res;
}

signed main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld %lld" , &n , &m , &k);
    for (ll i = 1, u, v, w; i <= m; i++)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        e.insert({u, v, w});
    }
    for (ll i = 1; i <= k ; i++)
    {
        scanf("%lld" , &c[i]);
        for (ll j = 1; j <= n; j++) scanf("%lld" , &a[i][j]);
    }
    ll ans = 0x3f3f3f3f3f3f3f3f, res;
    for (ll s = 0; s < (1 << k); s++)
    {
        res = update(s);
        iota(fa + 1 , fa + n + n + 1 , 1);
        for(auto [u , v , w] : e)
        {
            u = find(u), v = find(v);
            if(u != v) res += w, fa[u] = v;
        }
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
    return 0;
}
