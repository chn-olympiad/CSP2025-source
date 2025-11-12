#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<LL,int>PLI;
const int N=1e4+30;
const int M=2e6+5;
int n,m,k;
struct Edge{
    int u,v,w,id;
    Edge(){u=v=w=id=0;}
    Edge(int _u,int _v,int _w,int _id){
        u=_u,v=_v,w=_w,id=_id;
    }
}g[M];
int f[N];
int a[N],c[N];
int cmp(Edge x,Edge y){
    return x.w<y.w;
}
int find(int x){
    if(f[x]!=x) return f[x]=find(f[x]);
    return f[x];
}
int p[N];
PLI s[N];
LL get(){
    for(int i=1;i<=n+k;i++) f[i]=i;
    LL sum=0;
    for(int i=1;i<=m;i++){
        if(!p[g[i].id]) continue;
        int u=find(g[i].u),v=find(g[i].v);
        if(u==v) continue;
        f[u]=v;
        sum+=g[i].w;
    }
    // for(int i=1;i<=n;i++) printf("%d ",find(i));
    // puts("");
    // printf("!%d %d %d\n",p[1],p[2],sum);
    return sum;
}
void calc(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
        g[i].id=0;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[j]);
            g[++m]=Edge(n+i,j,a[j],i);
        }
    }
    sort(g+1,g+m+1,cmp);
    p[0]=1;
    LL ans=get();
    // printf("%lld\n",ans);
    for(int i=1;i<=k;i++){
        p[i]=1;
        s[i]=make_pair(get()+c[i],i);
        p[i]=0;
    }
    sort(s+1,s+k+1);
    for(int i=1;i<=k;i++){
        LL last=0;
        int id=s[i].second;
        p[id]=1;
        LL t=last+get()+c[id];
        if(t>ans) p[id]=0;
        else{
            last+=c[id];
            ans=t;
        }
    }
    printf("%lld\n",ans);
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T=1;
    while(T--) calc();
    return 0;
}
//g++ road.cpp -o a -O2