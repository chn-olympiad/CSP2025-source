#include<cstdio>
#include<algorithm>
#define N 10555
#define M 1000005
#define T 10
int n,m,k;
long long ans;
int p[N];
void init(){for(int i=1;i<=n+k;i++)p[i]=i;}
int qu(int o){if(p[o]-o)p[o]=qu(p[o]);return p[o];}
struct edge{
    int u,v,w;
    bool operator<(const edge z)const{
        return w<z.w;
    }
}mm[M];
struct node{
    int co;
    int ku[N],kv[N],kw[N];
    edge e[N];
    void fu(){
        for(int i=1;i<=n;i++)ku[i]=e[i].u,kv[i]=e[i].v,kw[i]=e[i].w;
    }
}chu[T+1];
struct pp{
    int ccnt;
    int ku[N],kv[N],kw[N];
    void add(int u,int v,int w){
        ccnt++;
        ku[ccnt]=u,kv[ccnt]=v,kw[ccnt]=w;
    }
}dp[(1<<T)+2];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&mm[i].u,&mm[i].v,&mm[i].w);
    std::sort(mm+1,mm+1+m);
    for(int i=1;i<=k;i++){
        scanf("%d",&chu[i].co);
        for(int j=1;j<=n;j++)scanf("%d",&chu[i].e[j].w),chu[i].e[j].u=i+n,chu[i].e[j].v=j;
        std::sort(chu[i].e+1,chu[i].e+n+1),chu[i].fu();
    }
    init();
    for(int i=1;i<=m;i++){
        int u=qu(mm[i].u),v=qu(mm[i].v),w=mm[i].w;
        if(u-v)p[u]=v,dp[0].add(u,v,w),ans+=w;
    }
    for(int t=1;t<1<<k;t++){
        long long nowc=0;
        for(int i=1;i<=k;i++)if((1<<i-1)&t)nowc+=chu[i].co;
        int xx=t-(t&-t),yy=0;
        for(int i=k;i;i--)if((1<<i-1)&t)yy=i;
        init();
        for(int i=1,j=1;i<=dp[xx].ccnt&&j<=n;){
            int u=0,v=0,w=0;
            if((j<=n&&chu[yy].kw[j]<dp[xx].kw[i])||i>dp[xx].ccnt)u=chu[yy].ku[j],v=chu[yy].kv[j],w=chu[yy].kw[j],j++;
            else u=dp[xx].ku[i],v=dp[xx].kv[i],w=dp[xx].kw[i],i++;
            u=qu(u),v=qu(v);
            if(u-v)p[u]=v,dp[t].add(u,v,w),nowc+=w;
        }
        // for(int i=1;i<=n+k;i++)if(p[i]==i)printf("%d ",i);puts("");
        ans=std::min(ans,nowc);
    }
    //for(int i=0;i<1<<k;i++)printf("(%d)",dp[i].ccnt);
    printf("%lld",ans);
}