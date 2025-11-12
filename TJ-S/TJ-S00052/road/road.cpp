#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=1e6+2e5,NK=11;
typedef long long LL;
int ini(){
    int f=0,d=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        d=d*10+c-'0';
        c=getchar();
    }
    return d;
}
LL inl(){
    LL f=0,d=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        d=d*10+c-'0';
        c=getchar();
    }
    return d;
}
struct Edge{
    int u,v;
    LL w;
    bool operator<(const Edge& o)const{
        return w<o.w;
    }
}es[M];
int n,m,k;
LL c[NK];
LL a[NK][N];
LL ulans=0,nans=0;
int nn;
namespace TR{
    int nm;
    int fa[N];
    void init(){
        for(int i=1;i<=n+13;++i)   fa[i]=i;
    }
    int gef(int x){
        return fa[x]=x==fa[x]?x:gef(fa[x]);
    }
    bool cho[NK];
    Edge ne[M];
    void getans(){
        for(int i=1;i<=m;++i)   ne[i]=es[i];
        for(int j=1;j<=k;++j){
            if(cho[j]){
                ++nn;
                for(int i=1;i<=n;++i){
                    ne[++nm]={nn,i,a[j][i]};
                }
            }
        }
        LL trans=nans;
        if(trans>ulans) return;
        init();
        sort(ne+1,ne+1+nm);
        int noe=0;
        for(int p=1;p<=nm;++p){
            int f1=gef(ne[p].u),f2=gef(ne[p].v);
            if(f1==f2)  continue;
            fa[f1]=f2;if(trans>ulans) return;
            trans+=ne[p].w;
            ++noe;
            if(noe==nn-1)    break;
        }
         ulans=min(ulans,trans);
    }
    void dfs(int now){
        int pos=now;
        if(now>k){
            getans();
            return;
        }
        dfs(now+1);
        int lm=nm,ln=nn;/*
        for(int i=1;i<=n;++i){
            es[++nm]={pos,i,a[pos][i]};
        }*/
        nans+=c[now];
        cho[now]=1;
        dfs(now+1);
        nm=lm;
        nn=ln;
        nans-=c[now];
        cho[now]=0;
    }
    void main(){
        memset(cho,0,sizeof cho);
        ulans=0x3f3f3f3f3f3f3f3f;
        nm=m;nn=n;
        dfs(1);
        printf("%d\n",ulans);
    }
}
namespace TA{
    int nm;
    int fa[N];
    void init(){
        for(int i=1;i<=n+13;++i)   fa[i]=i;
    }
    int gef(int x){
        return fa[x]=x==fa[x]?x:gef(fa[x]);
    }
    bool cho[NK];
    Edge ne[M];
    void getans(){
        for(int i=1;i<=m;++i)   ne[i]=es[i];
        for(int j=1;j<=k;++j){
            if(cho[j]){
                ++nn;
                for(int i=1;i<=n;++i){
                    ne[++nm]={nn,i,a[j][i]};
                }
            }
        }
        LL trans=nans;
        if(trans>ulans) return;
        init();
        sort(ne+1,ne+1+nm);
        int noe=0;
        for(int p=1;p<=nm;++p){
            int f1=gef(ne[p].u),f2=gef(ne[p].v);
            if(f1==f2)  continue;
            fa[f1]=f2;if(trans>ulans) return;
            trans+=ne[p].w;
            ++noe;
            if(noe==nn-1)    break;
        }
         ulans=min(ulans,trans);
    }
    void dfs(int now){
        int pos=now;
        if(now>k){
            getans();
            return;
        }
        dfs(now+1);
        int lm=nm,ln=nn;/*
        for(int i=1;i<=n;++i){
            es[++nm]={pos,i,a[pos][i]};
        }*/
        nans+=c[now];
        cho[now]=1;
        dfs(now+1);
        nm=lm;
        nn=ln;
        nans-=c[now];
        cho[now]=0;
    }
    void main(){
        memset(cho,0,sizeof cho);
        ulans=0x3f3f3f3f3f3f3f3f;
        nm=m;nn=n;
        dfs(1);
        printf("%d\n",ulans);
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
   scanf("%d%d%d",&n,&m,&k);
    //(int i=1;i<=m;++i)   es[i].u=ini(),es[i].v=ini,es[i].w=inl();
    bool fa=1;
for(int i=1;i<=m;++i) scanf("%d%d%lld",&es[i].u,&es[i].v,&es[i].w);
    for(int i=1;i<=k;++i){
        scanf("%lld",&c[i]);
        if(c[i]!=0) fa=0;
        for(int j=1;j<=n;++j){
            scanf("%lld",&a[i][j]);
            if(a[i][j]!=0)  fa=0;
        }
    }
   if(fa)  TA::main();
    else
    TR::main();
    return 0;
}
