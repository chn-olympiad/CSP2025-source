#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e4+100,maxm=1e6+10;

int n,m,k;

int start_up[15];

vector<pair<int,int>> gra[maxn];//to,w

int fa[maxn];

void init()
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
}

int findfa(int x)
{
    if(fa[x]==x)return x;
    else
    {
        return fa[x]=findfa(fa[x]);
    }
}

void hb(int x,int y)
{
    int xr=findfa(x);
    int yr=findfa(y);
    fa[xr]=yr;
}

typedef struct eg{
    int p1,p2,w;
    int nd=0;
    eg()
    {
        p1=0,p2=0,w=0,nd=0;
    }
    eg(int a,int b,int c,int d)
    {
        p1=a,p2=b,w=c,nd=d;
    }
    bool operator<(const eg &other)const
    {
        return w+(start_up[nd])>other.w+start_up[nd];
    }
}eg;

priority_queue<eg> qpqp;

bool vis[maxn];
bool visn[20];
int s2()
{
    init();
    int ans=0;
    int viscnt=0;
    viscnt++;
    vis[1]=1;
    for(auto item: gra[1])
    {
        int v=item.first;
        int w=item.second;
        if(v>n)
        {
            qpqp.emplace(1,v,w,v-n);
        }
        else{
            qpqp.emplace(1,v,w,0);
        }
    }
    while(viscnt<n)
    {
        auto t=qpqp.top();qpqp.pop();
        int x=t.p1,y=t.p2;
        if(findfa(x)==findfa(y))
            continue;

        int w=t.w;
        hb(x,y);
        if(t.nd)
        {
            visn[t.nd]=1;
        }
        ans+=w;
        for(auto item: gra[y])
        {
            int v=item.first;
            int w=item.second;
            if(start_up[v-n]!=0)
            {
                qpqp.emplace(y,v,w,v-n);
            }
            else
            {
                qpqp.emplace(y,v,w,0);
            }
        }
        if(y<=n)
        {
            viscnt++;
        }
        vis[x]=vis[y]=1;
    }
    for(int i=1;i<=k;++i)
    {
        if(visn[i])ans+=start_up[i];
    }
    return ans;
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
        gra[u].push_back({v,w});
        gra[v].push_back({u,w});
    }
    for(int i=1;i<=k;++i){
        scanf("%lld",&start_up[i]);
        for(int e=1;e<=n;++e){
                int tmp;
            scanf("%lld",&tmp);
            gra[i+n].push_back({e,tmp});
            gra[e].push_back({i+n,tmp});
        }
    }
    printf("%lld",s2());
    return 0;
}

