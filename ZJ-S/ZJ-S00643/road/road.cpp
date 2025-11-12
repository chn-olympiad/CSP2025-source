#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct awa{
    int u,v,id; ll w;
};
awa e[2000050],fs[2000050];
int n,m,k,ep;
ll c[20],ans=1e16;
int fa[200050],vd[200050];
int find(int x){
    return x==fa[x]? x:fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&fs[i].u,&fs[i].v,&fs[i].w); fs[i].id=0;
    }
    sort(fs+1,fs+m+1,[](awa fc,awa fd){
        return fc.w<fd.w;
    });
    for(int i=1;i<=n;i++) fa[i]=i,vd[i]=1;
    for(int i=1;i<=m;i++){
        int u=find(fs[i].u),v=find(fs[i].v);
        // cerr<<u<<" "<<v<<" "<<fs[i].w<<endl;
        if(u!=v){
            if(vd[u]>vd[v]) swap(u,v);
            fa[u]=v;
            if(vd[u]==vd[v]) vd[v]++;
            e[++ep]=fs[i];
            
        }
        // e[++ep]=fs[i];
    }
    
    // for(int i=1;i<=n;i++) cerr<<find(i)<<endl;

    int ttk=ep;
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            ++ep; ll tp; scanf("%lld",&tp);
            e[ep]=awa{n+i,j,i,tp};
        }
    }
    sort(e+1,e+ep+1,[](awa fc,awa fd){
        return fc.w<fd.w;
    });
    for(int st=0;st<=(1<<k)-1;st++){
        // cerr<<st<<endl;
        ll tans=0;
        for(int i=1;i<=k;i++){
            if(st&(1<<i-1)) tans+=c[i];
        }
        for(int i=1;i<=n+k;i++) fa[i]=i,vd[i]=1;
        for(int i=1;i<=ep;i++){
            if(e[i].id!=0&&!(st&(1<<e[i].id-1))) continue;
            int u=find(e[i].u),v=find(e[i].v);
            if(u!=v){
                tans+=e[i].w;
                if(vd[u]>vd[v]) swap(u,v);
                fa[u]=v;
                if(vd[u]==vd[v]) vd[v]++;
            }
        }
        ans=min(ans,tans);
    }
    printf("%lld",ans);
}