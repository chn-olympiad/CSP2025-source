#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct Node{
    int u,v,w;
    bool operator <(const Node x)const{
        return w<x.w;
    }
}e[N];
struct Line{
    int x,y,z;
    bool operator <(const Line &x)const{
        return z<x.z;
    }
}E[N];
bool b[15];
priority_queue<Node> heap[15];
int n,m,k,f[N],ret,cnt,c[20],a[20][N];
inline int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
inline void kruskal(){
    sort(e+1,e+1+m);
    for(int i=1;i<=m;i++){
        // int minn=1;
        // for(int j=2;j<=k;j++){
        //     if(heap[minn].top().w-b[minn]*c[minn]>=heap[j].top().w-b[j]*c[j])
        //         minn=j;
        // }
        // if(heap[minn].top().w-b[minn]*c[minn]<e[i].w){
        //     int fx=find(heap[minn].top().u);
        //     int fy=find(heap[minn].top().v);
        //     if(fx!=fy){
        //         f[fx]=fy;
        //         ret+=heap[minn].top().w-b[minn]*c[minn];
        //         cnt++,b[minn]=1;
        //         heap[minn].pop();
        //         if(cnt==n-1)return ;
        //         continue;
        //     }
        // }
        int fx=find(e[i].u),fy=find(e[i].v);
        if(fx!=fy){
            f[fx]=fy;
            // E[++cnt].x=e[i].u,E[cnt].y=e[i].v;
            // E[cnt].z=e[i].w;
            cnt++;
            ret+=e[i].w;
            if(cnt==n-1)return ;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n+k;i++)f[i]=i;
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    // for(int i=1;i<=k;i++){
    //     int c;
    //     scanf("%d",&c);
    //     for(int j=1;j<=n;j++){
    //         int t;
    //         scanf("%d",&t);
    //         e[++len]={j,n+i,t,1};
    //     }
    // }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
        // for(int j=1;j<=n;j++){
        //     for(int l=j+1;l<=n;l++){
        //         heap[i].push({a[i][j]+c[i],j,l});
        //     }
        // }
    }
    kruskal();
    // for(int i=1;i<=n;i++)
    //     for(auto j:E[i])
    //         printf("%d %d\n",j.u,j.v);
    printf("%d\n",ret);
    return 0;
}