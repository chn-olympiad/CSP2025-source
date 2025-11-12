#include <bits/stdc++.h>
namespace Cosh_X
{
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> PII;
    const ll N = 1e4 + 50, M = 2e6 + 50, K = 15, INF = 0x3f3f3f3f;
    inline ll read()
    {
        ll x = 0, f;
        char ch = getchar();
        while (!isdigit(ch) && ch != '-')
            ch = getchar();
        f = (ch == '-' ? (ch = getchar(), -1) : 1);
        while (isdigit(ch))
        {
            x = (x << 1) + (x << 3) + ch - '0';
            ch = getchar();
        }
        return x * f;
    }
}
using namespace Cosh_X;
ll n, m, k;
struct Union_Find
{
    ll f[N];
    inline void init()
    {
        for (ll i = 1; i <= n + k; i++)
            f[i] = i;
    }
    inline ll find(ll x)
    {
        if (f[x] == x)
            return x;
        else
            return f[x] = find(f[x]);
    }
    inline void merge(ll x, ll y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return;
        f[x] = y;
    }
} uf;
struct Edge
{
    ll w, u, v;
} e[M], e1[N];
inline bool cmp(Edge a, Edge b)
{
    if (a.w == b.w)
        return a.u < b.u;
    return a.w < b.w;
}
ll cnt[K], ww[K];
ll solve()
{
    uf.init();
    ll ans = 0, tot = 0, num = n;
    for (ll i = 1; i <= m; i++)
    {
        if (tot == num - 1)
            break;
        ll u = e[i].u, v = e[i].v, w = e[i].w;
        if (uf.find(u) == uf.find(v))
            continue;
        uf.merge(u, v);
        tot++;
        ans += w;
        if (u > n)
            num++, cnt[u - n]++, ww[u - n] = w;
    }
    for (ll i = 1; i <= k; i++)
    {
        if (cnt[i] == 1)
            ans -= ww[i];
    }
    return ans;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for (ll i = 1; i <= m; i++)
    {
        ll u = read(), v = read(), w = read();
        e[i] = {w, u, v};
    }
    for (ll i = 1; i <= k; i++)
    {
        ll c = read();
        for (ll j = 1; j <= n; j++)
        {
            ll w = read();
            e1[j] = {w, n + i, j};
        }
        sort(e1 + 1, e1 + 1 + n, cmp);
        e1[1].w += c;
        for (ll j = 1; j <= n; j++)
            e[++m] = e1[j];
    }
    sort(e + 1, e + 1 + m, cmp);
    cout << solve() << '\n';
    return 0;
}

// g++ road.cpp -O2 -std=c++14 -Wall -o road