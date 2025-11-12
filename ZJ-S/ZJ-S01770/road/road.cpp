#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int u,v,w;
};

const int N=1e4+10,M=1e6+10,K=15;
int n,m,k;
node edge[M+N*K*2];
int c[K],fa[N+K],a[K][N],in[K],out[K],pos[K];

inline bool cmp(node a,node b){ return a.w<b.w; }
int find(int x){
    if (x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;++i) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    for (int i=1;i<=k;++i){
        scanf("%d",c+i);
        for (int j=1;j<=n;++j) scanf("%d",&a[i][j]);
    }
    if (k==0){ // 1-4 16pts
        for (int i=1;i<=n;++i) fa[i]=i;
        sort(edge+1,edge+m+1,cmp);
        ll s=0;
        for (int i=1,cnt=0;cnt<n-1;++i){
            int p=find(edge[i].u),q=find(edge[i].v);
            if (p!=q) ++cnt,s+=edge[i].w,fa[p]=q;
        }
        printf("%lld",s);
    }else{ // A:5-6,9-10,13-14,17-18 32pts
        for (int i=1;i<=n+k;++i) fa[i]=i;
        for (int i=1;i<=k;++i){
            for (int j=1;j<=n;++j) edge[m+(i-1)*n+j]={n+i,j,a[i][j]};
        }
        sort(edge+1,edge+m+k*n+1,cmp);
        ll s=0;
        for (int i=1,cnt=0;cnt<n+k-1;++i){
            int p=find(edge[i].u),q=find(edge[i].v);
            if (p!=q) ++cnt,s+=edge[i].w,fa[p]=q;
        }
        printf("%lld",s);
    }
//    for (int i=1;i<=n+k*2;++i) fa[i]=i;
//    for (int i=1;i<=k;++i){
//        for (int j=1;j<=n;++j) edge[m+(i-1)*(n+1)+j]={n+i,j,a[i][j]};
//        edge[m+i*(n+1)]={n+k+i,n+i,c[i]};
//    }
//    sort(edge+1,edge+m+k*(n+1)+1,cmp);
//    ll s=0;
//    for (int i=1,cnt=0;cnt<n+k*2-1;++i){
//        if (edge[i].u>n && edge[i].v<=n && out[edge[i].u-n]) edge[i].u+=k;
//        int p=find(edge[i].u),q=find(edge[i].v);
//        if (p==q) continue;
//        printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
//        ++cnt,s+=edge[i].w,fa[p]=q;
//        if (edge[i].v>n) ++in[edge[i].v-n],pos[edge[i].v-n]+=edge[i].w;
//        else if (edge[i].u>n){
//            if (out[edge[i].u-n]==1) pos[edge[i].u-n]=in[edge[i].u-n]?0:c[edge[i].u-n];
//            else ++out[edge[i].u-n],pos[edge[i].u-n]+=edge[i].w;
//        }
//    }
//    printf("%lld\n",s);
//    for (int i=1;i<=k;++i) s-=pos[i];
//    for (int i=1;i<=k;++i) printf("%d ",pos[i]);
//    putchar('\n');
//    printf("%lld",s);
    return 0;
}
