#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e4+20,maxm=2e6+10,maxk=15;
int fa[maxn];
int n,m,k;
void init()
{
    for(int i=1;i<maxn;++i)
    {
        fa[i]=i;
    }
}
int fr(int x)
{
    return x==fa[x]?x:fa[x]=fr(fa[x]);
}
void join(int x,int y)
{
    int xr=fr(x),yr=fr(y);
    if(xr!=yr)
    {
        fa[xr]=yr;
    }
}
struct edge
{
    int x,y,w,id;
    edge()=default;
    edge(int x,int y,int w):x(x),y(y),w(w),id(id){}
    bool operator<(const edge&o)
    {
        return w<o.w;
    }
    bool operator>(const edge&o)
    {
        return w>o.w;
    }
}E[maxm];
int c[maxk],a[maxk][maxn];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    init();
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        E[i]=edge(u,v,w);
    }
    int is=1;
    for(int i=1;i<=k;++i)
    {
        scanf("%lld",&c[i]);
        if(c[i]!=0)
        {
            is=0;
        }
        for(int j=1;j<=n;++j)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    if(k<=0)
    {
        int ans=0;
        sort(E+1,E+1+m);
        for(int i=1;i<=m;++i)
        {
            int x=E[i].x,y=E[i].y,w=E[i].w;
            if(fr(x)!=fr(y))
            {
                ans+=w;
                join(x,y);
            }
        }
        printf("%lld\n",ans);
    }
    else if(is)
    {
        int ans=0;
        for(int i=1;i<=k;++i)
        {
            for(int j=1;j<=n;++j)
            {
                E[++m]=edge(n+i,j,a[i][j]);
            }
        }
        sort(E+1,E+1+m);
        int cnt=0;
        for(int i=1;i<=m;++i)
        {
            int x=E[i].x,y=E[i].y,w=E[i].w;
            if(fr(x)!=fr(y))
            {
                ans+=w;
                join(x,y);
            }
        }
        printf("%lld\n",ans);
    }
    else if(k<=5)
    {
        int ans=0;
        int q=m;
        for(int o=0;o<=(1<<k)-1;++o)
        {
            init();
            m=q;
            int tmp=0;
            int cc=0;
            priority_queue<edge,vector<edge>,greater<>>q;
            for(int i=1;i<=m;++i)
            {
                q.emplace(E[i]);
            }
            for(int i=1;i<=k;++i)
            {
                if((o>>(i-1))&1)
                {
                    for(int j=1;j<=n;++j)
                    {
                        q.emplace(n+i,j,a[i][j]);
                    }
                    ++cc;
                }
            }
            int cnt=0;
            for(int i=1;i<=m;++i)
            {
                int x=q.top().x,y=E[i].y,w=E[i].w;
                if(fr(x)!=fr(y))
                {
                    tmp+=w;
                    join(x,y);
                    ++cnt;
                }
                if(cnt==cc+n-1)
                {
                    break;
                }
            }
            ans=max(ans,tmp);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
