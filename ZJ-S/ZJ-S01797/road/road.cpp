#include <bits/stdc++.h>
using namespace std;
#define int long long
#define itn long long

constexpr int maxn = 1e4+20;
constexpr int maxm = 2e6+10;
constexpr int maxk = 20;
int c[maxk][maxn];
typedef struct edge
{
    int u,v,w;
    bool operator<(const edge&x)const
    {
        return w<x.w;
    }
} edge;
edge edges[maxm];
edge edgetmp[maxm<<1];
int fa[maxn];
itn n,m,k;
void init()
{
    for(int i = 1; i<=n; ++i)
    {
        fa[i] = i;
    }
}
int fr(int x)
{
    return fa[x] == x?x:fa[x] = fr(fa[x]);
}
void join(int x,int y)
{
    int xr = fr(x),yr = fr(y);
    if(xr!=yr) fa[xr] = yr;
}
typedef struct pt
{
    int p,w;
    bool operator<(const pt& x)const
    {
        return w>x.w;
    }
}pt;
vector<pt> gra[maxn];
vector<pt> gratmp[maxn];
priority_queue<pt> pq;
bool vis[maxn];
int prim(int qwq)
{
    int res = 0;
    int cnt = 0;
    while(!pq.empty())
    {
        pq.pop();
    }
    for(int i = 1;i<=n;++i)
    {
        vis[i] = 0;
    }
    pq.push({1,0});
    while(!pq.empty())
    {
        int u = pq.top().p;
        int w = pq.top().w;
        pq.pop();
        if(vis[u]) continue;
        res += w;
        vis[u] = 1;
        ++cnt;
        if(cnt == qwq) return res;
        for(pt pn:gra[u])
        {
            int v = pn.p;
            int ww = pn.w;
            if(!vis[v])
            {
                pq.push({v,ww});
            }
        }
    }
    return res;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 1; i<=m; ++i)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        edges[i] = {u,v,w};
        gra[u].push_back({v,w});
        gra[v].push_back({u,w});
    }
    itn C = 0;
    int pos = n;
    for(int i = 1; i<=k; ++i)
    {
        ++pos;
        for(int j = 1; j<=n+1; ++j)
        {
            scanf("%lld",&c[i][j]);
            gra[pos].push_back({j,c[i][j]});
            gra[j].push_back({pos,c[i][j]});
        }
        if(c[i][1] == 0) ++C;
    }
    int ans = LLONG_MAX/2;
    if(C == k)
    {
        for(int j = 1; j<=m; ++j)
        {
            edgetmp[j] = edges[j];
        }
        int res = 0;
        int tmp = m;
        for(int cnt = 1; cnt<=k; ++cnt)
        {
            for(int j = 1; j<=n; ++j)
            {
                for(int k = j+1; k<=n; ++k)
                {
                    edgetmp[++tmp] = {j,k,c[cnt][j+1]+c[cnt][k+1]};
                }
            }
        }
        sort(edgetmp+1,edgetmp+tmp+1);
        init();
        int cnt = 0;
        for(int i = 1; i<=tmp; ++i)
        {
            int u = edgetmp[i].u;
            int v = edgetmp[i].v;
            int w = edgetmp[i].w;
            if(fr(u)!=fr(v))
            {
                join(u,v);
                res += w;
                ++cnt;
            }
            if(cnt == n-1) break;
        }
        ans = min(ans,res);
    }
    else
    {
        for(int i = 0; i<=(1<<k)-1; ++i)
        {
            for(int j = n+1;j<=n+k;++j)
            {
                vis[j] = 1;
            }
            int situ = i;
            int cnt = 0;
            int res = 0;
            int ccnt = 0;
            while(situ>0)
            {
                ++cnt;
                if(situ&1)
                {
                    ++ccnt;
                    res += c[cnt][1];
                    vis[n+cnt] = 0;
                }
                situ>>=1;
            }
            cnt = 0;
            res += prim(n+ccnt);
            ans = min(ans,res);
        }
    }
    printf("%lld",ans);
    return 0;
}
