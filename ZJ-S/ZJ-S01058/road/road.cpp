#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int w=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) w=w*10+ch-'0',ch=getchar();
    return w;
}
const int N=10015,M=1000005;
int n,m,k;
struct edges{
    int u,v,ww;
}e[M];
int ecnt;
bool cmp(edges e1,edges e2){return e1.ww<e2.ww;}
int fa[N];
inline int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int c[15];
edges ce[15][N];
int hd[15],ed[15];
main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        e[i]={read(),read(),read()};
    }
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans=0;
    for(int i=1;i<=m;i++){
        if(find(e[i].u)==find(e[i].v)) continue;
        int u=e[i].u,v=e[i].v;
        ce[0][++ecnt]=e[i];
        fa[find(u)]=find(v);
        ans+=e[i].ww;
    }
    m=ecnt;
    ed[0]=ecnt;
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++) ce[i][j]={i+n,j,read()};
        sort(ce[i]+1,ce[i]+1+n,cmp);
        ed[i]=n;
    }
    // printf("ed %lld\n",ed[0]);
    // printf("fans %lld\n",ans);
    for(int s=1;s<(1<<k);s++){
        for(int i=1;i<=n+k;i++) fa[i]=i;
        for(int i=0;i<=k;i++) hd[i]=0;
        int sum=0;
        for(int i=0;i<k;i++) if((s>>i)&1) sum+=c[i+1];
        int mcnt=0;
        while(1){
            int cs=-1;
            for(int i=0;i<=k;i++){
                if(i&&((s>>(i-1))&1)==0) continue;
                while(hd[i]<ed[i]&&find(ce[i][hd[i]+1].u)==find(ce[i][hd[i]+1].v)) hd[i]++;
                if(hd[i]==ed[i]) continue;
                if(cs==-1||ce[cs][hd[cs]+1].ww>ce[i][hd[i]+1].ww) cs=i;
            }
            if(cs==-1) break;
            hd[cs]++;
            int u=ce[cs][hd[cs]].u,v=ce[cs][hd[cs]].v;
            sum+=ce[cs][hd[cs]].ww;
            fa[find(u)]=find(v);
            mcnt++;
        }
        // printf("%lld %lld\n",hd[0],hd[1]);
        for(int i=1;i<n;i++) assert(find(i)==find(i+1));
        // printf("mcnt  %lld\n",mcnt);
        // printf("%lld %lld\n",s,sum);
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}