#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll N=1e4+5,M=1e6+5,K=15;

mt19937 rd(time(0));

struct DSU{
    int fa[N],sz[N];
    void init(int x){
        for(int i=1;i<=x;i++){
            fa[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
    void unite(int u,int v){
        u=find(u),v=find(v);
        if(u==v) return;
        if(sz[u]>sz[v]) swap(u,v);
        fa[u]=v;
        sz[v]+=sz[u];
    }
};

struct Edge{
    ll u,v,w;
    bool operator<(const Edge &o) const {
        return w<o.w;
    }
};

int T,n,m,k;
ll c[N];
ll a[K][N];
vector<PLL> g[N];

ll kruskal(int n,vector<Edge> e){
    ll sum=0,cnt=0;
    DSU dsu;
    dsu.init(n+k);
    int m=e.size();
    sort(e.begin(),e.end());
    for(ll i=0,u,v,w;i<m;i++){
        u=e[i].u,v=e[i].v,w=e[i].w;
        if(dsu.find(u)==dsu.find(v)) continue;
        // cout<<u<<" "<<v<<" "<<w<<"\n";
        dsu.unite(u,v);
        sum+=w,cnt++;
        if(cnt==n-1) break;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int clock0=clock();
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    vector<Edge> e,tmp;
    cin>>n>>m>>k;
    for(ll i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    ll ans=INF,res,cnt;
    int idx[1<<K];
    iota(idx,idx+(1<<k),0);
    shuffle(idx,idx+(1<<k),rd);
    for(int i=0;i<1<<k;i++){
        res=0,cnt=0;
        tmp=e;
        for(int j=1;j<=k;j++){
            if(!(i>>j-1&1)) continue;
            res+=c[j],cnt++;
            for(int t=1;t<=n;t++) tmp.push_back({n+j,t,a[j][t]});
        }
        res+=kruskal(n+cnt,tmp);
        ans=min(ans,res);
        if(clock()-clock0>980) break;
        // cout<<res<<"\n";
    }
    cout<<ans<<"\n";
}