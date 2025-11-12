#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e4+27;
constexpr int maxm=2e6+13;
constexpr int inf=(LLONG_MAX>>1)-1;

int n,m,k;
int fa[maxn];
int c[14];
int a[14][maxn];
int max_c;
int fin(int x)
{
    return x==fa[x]?x:fa[x]=fin(fa[x]);
}
void uni(int x,int y)
{
    fa[fin(x)]=fin(y);
}
typedef struct ppp
{
    int u,v,w;
    bool operator<(const ppp &d)const
    {
        return w>d.w;
    }
} ppp;
ppp edge[maxm];
int u,v,w;
priority_queue<ppp>q;
void init()
{
    for(int i=1; i<=n+k; ++i)
    {
        fa[i]=i;
    }
    while(!q.empty())
    {
        q.pop();
    }
}

void sub1()
{
    init();
    for(int i=1; i<=m; ++i)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        q.push({u,v,w});
    }
    int K=0;
    int ans=0;
    while(!q.empty())
    {
        if(K==n-1)
        {
            break;
        }
        ppp l=q.top();
        q.pop();
        int xr=fin(l.u),yr=fin(l.v);
        if(xr!=yr)
        {
            ++K;
            ans+=l.w;
            uni(xr,yr);
        }
    }
    printf("%lld\n",ans);
}
void sub2()
{
    init();
    for(int i=1; i<=m; ++i)
    {
        q.push(edge[i]);
    }
    for(int i=1; i<=k; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            q.push({i+n,j,a[i][j]});
        }
    }
    int K=0;
    int ans=0;
    while(!q.empty())
    {
        if(K==n+k-1)
        {
            break;
        }
        ppp l=q.top();
        q.pop();
        int xr=fin(l.u),yr=fin(l.v);
        if(xr!=yr)
        {
            ++K;
            ans+=l.w;
            uni(xr,yr);
        }
    }
    printf("%lld\n",ans);
}
void init2(int mask)
{
    while(!q.empty())
    {
        q.pop();
    }
    for(int i=1; i<=n+k; ++i)
    {
        fa[i]=i;
    }
    for(int i=1; i<=m; ++i)
    {
        q.push(edge[i]);
    }
    for(int i=1; i<=k; ++i)
    {
        if(!(mask&(1<<(i-1))))
        {
            continue;
        }
        for(int j=1; j<=n; ++j)
        {
            q.push({i+n,j,a[i][j]});
        }
    }
}
void sub3()
{
    int ans=inf;
    for(int i=0; i<(1<<k); ++i)
    {
        int K=0;
        int need=0;
        int sum=0;
        for(int j=1;j<=k;++j)
        {
            if(i&(1<<(j-1)))
            {
                ++need;
                sum+=c[j];
            }
        }
        if(sum+n+need-1>ans)
        {
            goto mmm;
        }
        init2(i);
        while(!q.empty())
        {
            if(K==n+need-1)
            {
                break;
            }
            if(sum>ans)
            {
                goto mmm;
            }
            ppp l=q.top();
            q.pop();
            int xr=fin(l.u),yr=fin(l.v);
            if(xr!=yr)
            {
                ++K;
                sum+=l.w;
                uni(xr,yr);
            }
        }
        ans=min(ans,sum);
        mmm:;
    }
    printf("%lld\n",ans);
}
void init3(int mask)
{
    for(int i=1; i<=n+k; ++i)
    {
        fa[i]=i;
    }
    for(int i=1; i<=k; ++i)
    {
        if(!(mask&(1<<(i-1))))
        {
            continue;
        }
        for(int j=1; j<=n; ++j)
        {
            q.push({i+n,j,a[i][j]});
        }
    }
}
void sub4()
{
    vector<ppp>path;
    for(int i=1; i<=m; ++i)
    {
        q.push(edge[i]);
    }
    init();
    int K=0;
    int ans=0;
    while(!q.empty())
    {
        if(K==n-1)
        {
            break;
        }
        ppp l=q.top();
        q.pop();
        int xr=fin(l.u),yr=fin(l.v);
        if(xr!=yr)
        {
            ++K;
            uni(xr,yr);
            ans+=l.w;
            path.push_back(l);
        }
    }
    for(int i=0; i<(1<<k); ++i)
    {
        int need=0;
        int sum=0;
        int K=0;
        for(int j=1;j<=k;++j)
        {
            if(i&(1<<(j-1)))
            {
                ++need;
                sum+=c[j];
            }
        }
        if(sum+n+need-1>ans)
        {
            goto mmm;
        }
        init3(i);
        for(ppp r:path)
        {
            q.push(r);
        }
        while(!q.empty())
        {
            if(K==n+need-1)
            {
                break;
            }
            if(sum>ans)
            {
                goto mmm;
            }
            ppp l=q.top();
            q.pop();
            int xr=fin(l.u),yr=fin(l.v);
            if(xr!=yr)
            {
                ++K;
                sum+=l.w;
                uni(xr,yr);
            }
        }
        ans=min(ans,sum);
        mmm:;
    }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    if(k==0)
    {
        sub1();
    }
    else
    {
        for(int i=1; i<=m; ++i)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            edge[i].u=u;
            edge[i].v=v;
            edge[i].w=w;
        }
        for(int i=1; i<=k; ++i)
        {
            scanf("%lld",&c[i]);
            max_c=max(max_c,c[i]);
            for(int j=1; j<=n; ++j)
            {
                scanf("%lld",&a[i][j]);
            }
        }
        if(max_c==0)
        {
            sub2();
        }
        else if(k<=5)
        {
            sub3();
        }
        else
        {
            sub4();
        }
    }

    return 0;
}

