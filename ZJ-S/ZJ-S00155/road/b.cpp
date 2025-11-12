#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
constexpr int N=1e4+3,M=1e6+3,K=10;

int n,m,k,V,c[K],a[K][N],id[K*N];
vector<tuple<int,int,int>> E,G;

vector<int> vals;
pii e[N*(K+1)];
int cnt[N*(K+1)];
inline void get(int &x){x=lower_bound(vals.begin(),vals.end(),x)-vals.begin();}

namespace DSU{
    int fa[N+K],siz[N+K];
    inline void init(){iota(fa+1,fa+1+n+k,1),fill_n(siz+1,n+k,1);}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    inline bool merge(int u,int v){
        if((u=find(u))==(v=find(v)))return false;
        if(siz[u]>siz[v])swap(u,v);
        return fa[u]=v,siz[v]+=siz[u],true;
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++)scanf("%d%d%d",&u,&v,&w),E.emplace_back(w,u,v);
    for(int i=0;i<k;i++){
        scanf("%d",c+i);
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),vals.emplace_back(a[i][j]);
    }
    sort(E.begin(),E.end()),DSU::init();
    for(auto[w,u,v]:E)if(DSU::merge(u,v))G.emplace_back(w,u,v),vals.emplace_back(w);
    sort(vals.begin(),vals.end()),vals.erase(unique(vals.begin(),vals.end()),vals.end()),V=vals.size();
    for(auto&[w,u,v]:G)get(w);
    for(int i=0;i<k;i++)for(int j=1;j<=n;j++)get(a[i][j]);
    ll ans=LLONG_MAX;
    for(int s=0;s<(1<<k);s++){
        DSU::init(),fill_n(cnt,V+1,0);
        for(auto[w,u,v]:G)cnt[w]++;
        for(int i=0;i<k;i++)if((s>>i)&1)for(int j=1;j<=n;j++)cnt[a[i][j]]++;
        for(int i=0;i<V;i++)cnt[i+1]+=cnt[i];
        ll sum=0;
        for(auto[w,u,v]:G)e[--cnt[w]]=make_pair(u,v);
        for(int i=0;i<k;i++)if((s>>i)&1){
            sum+=c[i];
            for(int j=1;j<=n;j++)e[--cnt[a[i][j]]]=make_pair(j,n+i+1);
        }
        for(int w=0;w<V;w++)for(int i=cnt[w];i<cnt[w+1];i++)
            if(int u=e[i].first,v=e[i].second;DSU::merge(u,v))sum+=vals[w];
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}