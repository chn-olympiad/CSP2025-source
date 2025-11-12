#include<bits/stdc++.h>
#define MAXN 10010
#define MAXM 1000010
using namespace std;
typedef long long ll;
struct edge{
    ll u,v,w;
}e[MAXM];
ll add[15][MAXN];
int fa[MAXN];
int n,m,k;
int getf(int u){
    return fa[u]==u?u:(fa[u]=getf(fa[u]));
}
ll yangfeiting=0; // %yangfeiting 
bool cmp(edge a,edge b){
    return a.w<b.w;
}
void chenduling(){
    // love duling everything is lucky---- chenduling 1018
    sort(e+1,e+m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        ll u=e[i].u,v=e[i].v,w=e[i].w;
        u=getf(u),v=getf(v);
        if(u!=v){
            yangfeiting+=w;
            fa[u]=v;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    printf("%lld",yangfeiting);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    if(k==0) chenduling();
    fclose(stdin);
    fclose(stdout);
    


    return 0;
}
