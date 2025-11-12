#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u,v,w;
};
int n,m,k;
vector<Edge> edge;
int c[10005];
int a[10005][10005];
int fa[10005];
bool flag[10005];

void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}

bool cmp(Edge e1,Edge e2){
    return e1.w<e2.w;
}

int findFa(int x){
    return fa[x]==x?x:fa[x]=findFa(fa[x]);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    init();
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge.push_back(Edge{u,v,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            for(int h=j-1;h>=1;h--){
                edge.push_back(Edge{j,h,a[i][j]+a[i][h]});
            }
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    int ans=0;
    int cnt=0;
    int i=0;
    while(cnt<n&&i<=m){
        Edge e=edge[i];
        i++;
        if(flag[e.u]&&flag[e.v]){
            continue;
        }
        cnt+=(flag[e.v]);
        cnt+=(flag[e.u]);
        flag[e.u]=true,flag[e.v]=true;
        int u=findFa(e.u),v=findFa(e.v);
        if(u!=v){
            fa[u]=v;
        }
        ans+=e.w;
    }
    cout << ans;
    return 0;
}
