#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e4+5,M=1e6+5,K=1e1+5;
int fa[N];
int root(int x){
    if(x==fa[x]){
        return x;
    }
    return root(fa[x]);
}
struct edge{
    int f,t,w;
}e[M<<1];
bool cmp(edge abcd,edge dcba){
    return abcd.w<dcba.w;
}
//vector<edge> g[N];
int n,m,done[N];
int ans,cnt;
int k;
int c[K],a[K][N];

void kruskal(){
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        if(cnt==n-1) return;
        for(int j=0;j<m;j++){
            int f=e[j].f,t=e[j].t,w=e[j].w;
            int e1=root(f),e2=root(t);
            if(e1==e2) continue;
            fa[e1]=e2;
            cnt++;
            ans+=w;
        }
    }
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m*2;i+=2){
//        cin>>u>>v>>w;
//        g[u].push_back({u,v,w});
//        g[v].push_back({v,u,w});
        cin>>e[i].f>>e[i].t>>e[i].w;
        e[i+1].f=e[i].f,e[i+1].t=e[i].t,e[i+1].w=e[i].w;
    }
    for(int i=1;i<=k;i++) cin>>c[i];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    kruskal();
    printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
