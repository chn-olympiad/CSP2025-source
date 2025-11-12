#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=1e4+5,M=1e6+5,K=13;
int n,m,k,pnow;
struct Edge{
    int u,v,w,r;
}old[M],now[N*K];
int fa[N+K],c[K];
int Find(int x){
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Work(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        old[i]={u,v,w,0};
    }
    sort(old+1,old+m+1,[](const Edge& e1,const Edge& e2){
        return e1.w<e2.w;
    });
    for(int i=1;i<=n;++i) fa[i]=i;
    pnow=0;
    for(int i=1;i<=m;++i){
        auto [u,v,w,r]=old[i];
        u=Find(u),v=Find(v);
        if(u==v) continue;
        fa[u]=v,now[++pnow]=old[i];
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j){
            int w;
            cin>>w;
            now[++pnow]={n+i,j,w,i};
        }
    }
    sort(now+1,now+pnow+1,[](const Edge& e1,const Edge& e2){
        return e1.w<e2.w;
    });
    i64 ans=1e18;
    for(int S=0;S<(1<<k);++S){
        i64 sum=0;
        for(int i=1;i<=n;++i) fa[i]=i;
        for(int i=1;i<=k;++i) if(S>>(i-1)&1){
            fa[n+i]=n+i;
            sum+=c[i];
        }
        if(sum>=ans) continue;
        for(int i=1;i<=pnow;++i){
            auto [u,v,w,r]=now[i];
            if(r&&!(S>>(r-1)&1)) continue;
            u=Find(u),v=Find(v);
            if(u==v) continue;
            // printf(" %d %d\n",u,v);
            fa[u]=v,sum+=w;
            if(sum>=ans) break;
        }
        // printf("%d %lld\n",S,sum);
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    Work();
    fclose(stdin),fclose(stdout);
    return 0;
}