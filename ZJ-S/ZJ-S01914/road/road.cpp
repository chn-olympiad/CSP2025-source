#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct edge{
    int u,v,w;
}e[N],b[N],a[N],f[15][20010];
int fa[N],n,m,k,c[15],pos[15],pp[15],np[15],tot;
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(edge nw){
    int X=find(nw.u),Y=find(nw.v);
    if(X==Y) return;
    a[++tot]=nw;
    fa[X]=Y;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(e+1,e+m+1,cmp);
    int cnt=0,ans=0;
    for(int i=1;i<=m;i++){
        int x=find(e[i].u);
        int y=find(e[i].v);
        if(x==y) continue;
        fa[x]=y;
        ans+=e[i].w;
        b[++cnt]=e[i];
    }
    int nv=0;
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&f[i][j].w);
            f[i][j].v=j;
        }
        sort(f[i]+1,f[i]+n+1,cmp);
        pp[i]=f[i][1].v;
        for(int j=2;j<=n;j++) f[i][j].u=pp[i];
    }
    for(int s=1;s<(1<<k);s++){
        int rs=0,nc=0,cnt=0;
        for(int j=1;j<=k;j++){
            if(s&(1<<(j-1))){
                np[++cnt]=j;
                pos[cnt]=2; 
                rs+=c[j];
                rs+=f[j][1].w;
            }
        }
        for(int j=1;j<=n;j++) fa[j]=j;
        tot=0;
        for(int j=1;j<=n-1;j++){
            for(int i=1;i<=cnt;i++){
                int nw=np[i];
                while(pos[i]<=n&&f[nw][pos[i]].w<=b[j].w){
                    merge(f[nw][pos[i]]);
                    pos[i]++;
                }
            }
            merge(b[j]);
        }
        for(int j=1;j<=n-1;j++) rs+=a[j].w;
        ans=min(ans,rs);
    }
    printf("%lld",ans);
}