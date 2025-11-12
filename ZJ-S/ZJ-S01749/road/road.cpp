#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxm = 2e6 + 10;
constexpr int maxn = 2e4 + 10;
constexpr int maxk = 1e1 + 10;
constexpr int inf = LLONG_MAX>>1;
int n , m , k;
typedef struct edge
{
    int x , y , wei;
    bool operator<(const edge &e) const
    {
        return this->wei < e.wei;
    }
}edge;
edge edges[maxm];
int c[maxn];
int vi[maxk][maxn];
int fa[maxn];
void init(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
}
int find_root(int x)
{
    if(fa[x] == x) return x;
    int root = find_root(fa[x]);
    fa[x] = root;
    return root;
}
void join(int x , int y)
{
    int xr = find_root(x) , yr = find_root(y);
    if(xr == yr) return;
    fa[xr] = yr;
}
int kruskal1(int n , int m)
{
    init(n);
    sort(edges + 1 , edges + m + 1);
    int total_weight = 0 , edge_cnt = 0;
    for(int i = 1; i <= m; ++i)
    {
        edge e = edges[i];
        if(find_root(e.x) != find_root(e.y))
        {
            ++edge_cnt;
            total_weight += e.wei;
            join(e.x , e.y);
        }
        if(edge_cnt == n - 1)
        {
            break;
        }
    }
    return edge_cnt == n - 1 ? total_weight : -1;
}
void sub1()
{
    int ans = kruskal1(n , m);
    printf("%lld\n",ans);
}
int kruskal2(int n , int m)
{
    init(n);
    sort(edges + 1 , edges + m + 1);
    int total_weight = 0;
    for(int i = 1; i <= m; ++i)
    {
        edge e = edges[i];
        if(find_root(e.x) != find_root(e.y))
        {
            total_weight += e.wei;
            join(e.x , e.y);
        }
        bool flag = 1;
        for(int i = 1; i <= n; ++i)
        {
            if(find_root(i) != find_root(1))
            {
                flag = 0;
            }
        }
        if(flag)
        {
            break;
        }
    }
    return total_weight;
}
void subA()
{
    for(int i = 1; i <= k; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int id = m + (i - 1) * n + j;
            edges[id] = {n + i , j , vi[i][j]};
        }
    }
    int ans = kruskal2(n + k , m + n * k);
    printf("%lld\n",ans);
}
void solve()
{

}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%lld%lld%lld",&n,&m,&k);
    int u , v , w;
    bool suba = 1;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        edges[i] = {u , v , w};
    }
    for(int i = 1; i <= k; ++i)
    {
        scanf("%lld",c + i);
        if(c[i] != 0)
        {
            suba = 0;
        }
        for(int j = 1; j <= n; ++j)
        {
            scanf("%lld",&vi[i][j]);
        }
    }
    //cerr << suba << endl;
    if(k == 0)
    {
        sub1();
    }
    else if(suba)
    {
        subA();
    }
    else
    {
        solve();
    }
    return 0;
}
