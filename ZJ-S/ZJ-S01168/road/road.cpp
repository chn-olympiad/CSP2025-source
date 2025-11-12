#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
};
bool operator<(const edge &a, const edge &b)
{
    return a.w < b.w;
}
constexpr long long MAXN = 1e4 + 20;
struct bcg
{
    long long fa[MAXN], siz[MAXN];
    void init()
    {
        fill(siz, siz + MAXN, 1);
        iota(fa, fa + MAXN, 0);
    }
    long long find(long long c)
    {
        return c == fa[c] ? c : fa[c] = find(fa[c]);
    }
    long long same(long long a, long long b)
    {
        return find(a) == find(b);
    }
    void unite(long long a, long long b)
    {
        a = find(a), b = find(b);
        if (same(a, b))
            return;
        if (siz[a] < siz[b])
            swap(a, b);
        fa[b] = a;
        siz[a] += siz[b];
    }
} b;
struct edge_1
{
    long long u, v, w;
    edge_1 *nxt_e;
};
edge_1 *beg[MAXN];
void add_edge(long long u, long long v, long long w)
{
    auto tmp = beg[u];
    beg[u] = new edge_1;
    beg[u]->nxt_e = tmp;
    beg[u]->u = u;
    beg[u]->v = v;
    beg[u]->w = w;
}
vector<edge> E;
void add_edge(const edge &i)
{
    E.emplace_back(i);
}
long long k_v[10][MAXN];
long long c[10];

int main()
{

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<edge> e(m);
    for (auto &i : e)
        scanf("%d%d%d", &i.u, &i.v, &i.w);
    b.init();
    sort(e.begin(), e.end());
    long long ans_chu = 0, ans = 1e18;
    for (auto &i : e)
    {
        if (!b.same(i.u, i.v))
        {
            b.unite(i.u, i.v);
            ans_chu += i.w;
            add_edge(i);
        }
    }
    ans = ans_chu;
    for (long long i = 0; i < k; i++)
    {
        scanf("%lld", &c[i]);
        for (long long j = 1; j <= n; j++)
        {
            scanf("%lld", &k_v[i][j]);
        }
    }
    for (int use = 1; use < 1 << k; use++)
    {
        auto E_me = E;
        long long ans_chu = 0;
        for (long long i = 0; i < k; i++)
        {
            if (use & (1 << i))
            {
                for (long long j = 1; j <= n; j++)
                {
                    E_me.push_back({j, n + i + 1, k_v[i][j]});
                }
                ans_chu+=c[i];
            }
        }
        b.init();
        sort(E_me.begin(), E_me.end());
        for (auto &i : E_me)
        {
            if (!b.same(i.u, i.v))
            {
                b.unite(i.u, i.v);
                ans_chu += i.w;
            }
        }
        ans=min(ans_chu,ans);
    }
    printf("%lld", ans);
}