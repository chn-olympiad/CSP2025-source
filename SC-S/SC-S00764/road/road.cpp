#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,int> PLI;
typedef pair<int,int> PII;

const int N=1e4+10,M=1e6+10;
int n,m,K,idx=0,c[15],b[15][N];

PLI a[15][N];
vector<PII> e[N];

struct DSU{
    int fa[N];
    inline void init(){ iota(fa+1,fa+1+n,1); }
    inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]); }
    inline bool _merge(int u,int v){
        if(find(u)!=find(v))
            return fa[find(u)]=find(v),true;
        return false;
    }
}dsu;
struct Edge{
    int u,v,w;
}E[M];

bool vis[N];
LL dis[N],tag[15];
LL solve(int S){
    // printf("solve: %d\n",S);
    LL ret=0;
    vector<int> pt(K,1);
    for(int i=0;i<K;i++)
        if(S>>i&1) ret+=c[i],tag[i]=1e18;

    priority_queue<PLI,vector<PLI>,greater<PLI> > q;

    for(int i=1;i<=n;i++)
        dis[i]=1e18,vis[i]=false;

    q.push({dis[1]=0,1});
    for(int i=1;i<=n;i++){
        // cerr<<i<<endl;
        while(!q.empty() && vis[q.top().second]) q.pop();

        assert(!q.empty());
        auto [D,u]=q.top();

        for(int j=0;j<K;j++) if(S>>j&1){
            while(pt[j]<=n && vis[a[j][pt[j]].second]) pt[j]++;
            assert(pt[j]<=n);
            if(pt[j]<=n){
                LL val=tag[j]+a[j][pt[j]].first;
                if(D>val) D=val,u=a[j][pt[j]].second;
            }
        }

        // printf("%d %lld\n",u,D);
        vis[u]=true; ret+=D;
        for(auto [v,w]:e[u])
            if(!vis[v]) dis[v]=min(dis[v],(LL)w),q.emplace(dis[v],v);
        for(int j=0;j<K;j++) if(S>>j&1)
            tag[j]=min(tag[j],(LL)b[j][u]);
    }
    // printf("%lld\n",ret);
    return ret;
}
int main(){
    freopen("road.in","r",stdin);
    // freopen("test.in","r",stdin);
    freopen("road.out","w",stdout);
    // freopen("./down/road/road4.in","r",stdin);
    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
    for(int i=0;i<K;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
            scanf("%lld",&a[i][j].first),a[i][j].second=j,b[i][j]=a[i][j].first;
        sort(a[i]+1,a[i]+1+n);
    }
    sort(E+1,E+1+m,[&](const Edge &X,const Edge &Y){
        return X.w<Y.w;
    });
    dsu.init();
    for(int i=1;i<=m;i++){
        auto [u,v,w]=E[i];
        if(dsu._merge(u,v))
            ++idx,e[u].push_back({v,w}),e[v].push_back({u,w});
    }
    assert(idx==n-1);

    LL ans=1e18;
    for(int i=0;i<(1<<K);i++)
        ans=min(ans,solve(i));
    printf("%lld\n",ans);
    return 0;
}