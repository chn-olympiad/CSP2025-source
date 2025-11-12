#include<bits/stdc++.h>
#define INF 0x7fffffff
typedef long long ll;
using namespace std;
bool st;
const int N=2e4+4,M=11,NM=1e6+5000;
int n,m,k,val[M],cst[M][N],mincst[M],minto[M];
struct edge{
    int u,v,w;
    bool operator <(const edge &rhs){
        return w<rhs.w;
    }
}e[NM],cha[NM];
int fa[N],tot=0;
ll ans=1e18;
inline int find(int x){
    return (x==fa[x])?x:fa[x]=find(fa[x]);
}
void solve1(){
    ll res=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fau=find(u),fav=find(v);
        if(fau==fav) continue;
        fa[fau]=fav; cha[++tot]=e[i]; res+=w;
    }ans=min(ans,res);
    for(int i=1;i<=tot;i++) e[i]=cha[i];
}
void solve2(ll res,int total){
    for(int i=1;i<=n;i++) fa[i]=i;
    if(res>ans) return;
    sort(e+1,e+total+1);
    for(int i=1;i<=total;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fau=find(u),fav=find(v);
        if(fau==fav) continue;
        fa[fau]=fav; res+=w;
        if(res>ans) return;
    }ans=min(ans,res);
}
bool en;
int main(){
    //printf("%.3lf",(&en-&st)/1024.0/1024.0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        e[i]=(edge){x,y,z};
    }
    solve1();
    //printf("%lld\n",ans);
    for(int i=1;i<=k;i++){
        scanf("%d",&val[i]);
        for(int j=1;j<=n;j++) scanf("%d",&cst[i][j]);
        mincst[i]=INF;
        for(int j=1;j<=n;j++){
            if(cst[i][j]<mincst[i]){
                mincst[i]=cst[i][j];
                minto[i]=j;
            }
        }
    }
    for(int i=(1<<k)-1;i>=1;i--){
        int total=tot;
        ll qaq=0;
        for(int j=1;j<=tot;j++) e[j]=cha[j];
        for(int j=1;j<=k;j++){
            if(!((i>>(j-1))&1)) continue;
            qaq+=val[j]+mincst[j];
            for(int zlx=1;zlx<=n;zlx++){
                if(total<tot) assert(0);
                e[++total]=(edge){minto[j],zlx,cst[j][zlx]};
            }
        }
        solve2(qaq,total);
    }printf("%lld",ans);
    return 0;
}
