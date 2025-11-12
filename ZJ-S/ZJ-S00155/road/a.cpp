#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=1e4+3,M=1e6+3,K=10;

int n,m,k,c[K],a[K][N];
vector<tuple<int,int,int>> E,G;

namespace DSU{
    int fa[N+K];
    inline void init(){iota(fa+1,fa+1+n+k,1);}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    inline bool merge(int u,int v){
        if((u=find(u))!=(v=find(v)))return fa[u]=v,true;
        else return false;
    }
}

int main(){
    // freopen("road.in","r",stdin);
    // freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++)scanf("%d%d%d",&u,&v,&w),E.emplace_back(w,u,v);
    for(int i=0;i<k;i++){
        scanf("%d",c+i);
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    }
    sort(E.begin(),E.end()),DSU::init();
    for(auto[w,u,v]:E)if(DSU::merge(u,v))G.emplace_back(w,u,v);
    ll ans=LLONG_MAX;
    for(int s=0;s<(1<<k);s++){
        DSU::init(),E=G;
        ll sum=0;
        for(int i=0;i<k;i++)if((s>>i)&1){
            sum+=c[i];
            for(int j=1;j<=n;j++)E.emplace_back(a[i][j],j,n+i+1);
        }
        sort(E.begin(),E.end());
        for(auto[w,u,v]:E)if(DSU::merge(u,v))sum+=w;
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}