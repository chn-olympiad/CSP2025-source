#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int maxn=1e4+10;
constexpr int maxk=15;
int ww[maxk][maxn];
int fa[maxn];
inline int read()
{
    signed ch=getchar_unlocked();
    while(!isdigit(ch))
    {
        ch=getchar_unlocked();
    }
    int x=0;
    while(isdigit(ch))
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar_unlocked();
    }
    return x;
}
void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
}
int findr(int u)
{
    return u==fa[u]?u:fa[u]=findr(fa[u]);
}
void bing(int u,int v)
{
    u=findr(u);
    v=findr(v);
    if(u==v) return;
    fa[u]=v;
}
struct edge
{
    int u,v,w;
    edge()=default;
    edge(int u,int v,int w):u(u),v(v),w(w){}
    bool operator<(const edge &x) const
    {
        return w>x.w;
    }
};
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read();
    int m=read();
    int k=read();
    priority_queue<edge> edges;
    while(m--)
    {
        int u=read();
        int v=read();
        int w=read();
        edges.emplace(u,v,w);
    }
    for(int i=1;i<=k;++i)
    {
        for(int j=0;j<=n;++j)
        {
            ww[i][j]=read();
        }
    }
    ll res=LLONG_MAX;
    for(int i=0;i<1<<k;++i)
    {
        ll ans=0;
        priority_queue<edge> tmp{edges};
        init(n+k+1);
        for(int j=0;j<k;++j)
        {
            if((i>>j)&1)
            {
                ans+=ww[j+1][0];
                for(int kk=1;kk<=n;++kk)
                {
                    tmp.emplace(j+1+n,kk,ww[j+1][kk]);
                }
            }
        }
        int cnt=0;
        while(cnt<n+__builtin_popcount(i)-1)
        {
            int u=tmp.top().u;
            int v=tmp.top().v;
            int w=tmp.top().w;
            tmp.pop();
            if(findr(u)==findr(v)) continue;
            ++cnt;
            ans+=w;
            bing(u,v);
        }
        res=min(res,ans);
    }
    printf("%lld\n",res);
}