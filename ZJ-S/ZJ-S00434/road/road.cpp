#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e4+10;
constexpr int maxm=7e6+10;
constexpr int INF=LLONG_MAX/2;
int n,m,k;
typedef struct edge
{
    int x,y,w;
    bool operator<(const edge &b) const
    {
        return this->w<b.w;
    }
}edge;
edge edges[maxm];
int vill[15][maxn];
int villw[15];
int flag;
int root[maxn];
int ans;


int find_root(int x)
{
    return x==root[x]?x:root[x]=find_root(root[x]);
}

void sub1()
{
    sort(edges+1,edges+1+m);
    int cnt=0;
    for(int i=1;i<=m;++i)
    {
        int u=edges[i].x;
        int v=edges[i].y;
        int ur=find_root(u);
        int vr=find_root(v);
        int w=edges[i].w;
        if(ur!=vr)
        {
            root[ur]=vr;
            ans+=w;
            ++cnt;
            if(cnt==n-1)
            {
                break;
            }
        }
    }
    printf("%lld\n",ans);
}
int jj[1005][1005];
void sub2()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            jj[i][j]=INF;
        }
        jj[i][i]=0;
    }
    for(int i=1;i<=m;++i)
    {
        int x=edges[i].x,y=edges[i].y,w=edges[i].w;
        jj[x][y]=min(jj[x][y],w);
        jj[y][x]=min(jj[y][x],w);
    }
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int l=j+1;l<=n;++l)
            {
                jj[j][l]=min(jj[j][l],vill[i][j]+vill[i][l]);
                jj[l][j]=jj[j][l];
            }
        }
    }
    m=0;
    for(int i=0;i<n*n;++i)
    {
        int u=i%n+1;
        int v=i/n+1;
        if(u==v||jj[u][v]==INF) continue;
        edges[++m]={u,v,jj[u][v]};
    }
//    for(int i=1;i<=n;++i)
//    {
//        for(int j=1;j<=n;++j)
//        {
//            printf("%lld ",jj[i][j]);
//        }
//        printf("\n");
//    }
    sort(edges+1,edges+1+m);
    int cnt=0;
    for(int i=1;i<=m;++i)
    {
        int u=edges[i].x;
        int v=edges[i].y;
        int ur=find_root(u);
        int vr=find_root(v);
        int w=edges[i].w;
        if(ur!=vr)
        {
            root[ur]=vr;
            ans+=w;
            ++cnt;
            if(cnt==n-1)
            {
                break;
            }
        }
    }
    printf("%lld\n",ans);
}


signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        edges[i]={u,v,w};
    }
    for(int i=1;i<=n;++i)
    {
        root[i]=i;
    }
    for(int i=1;i<=k;++i)
    {
        scanf("%lld",&villw[i]);
        if(villw[i])
        {
            flag=1;
        }
        for(int j=1;j<=n;++j)
        {
            scanf("%lld",&vill[i][j]);
        }
    }
    if(k==0)
    {
        sub1();
    }
    else if(flag==0)
    {
        sub2();
    }

    return 0;
}
