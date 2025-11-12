#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll N=1e4+5,M=1e6+5,K=15;

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
    freopen("road2.in","r",stdin);
    freopen("road.out","w",stdout);
    vector<Edge> e,tmp;
    cin>>n>>m>>k;
    for(ll i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    kruskal(n,e);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    ll ans=INF;
    for(int i=0;i<1<<k;i++){
    }
    cout<<ans<<"\n";
}