#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using std::priority_queue;
const int maxn=11000;
const int maxk=15;
struct p2 {
    int v,w;
    bool operator<(const p2 &b) const {
        return w<b.w;
    }
    bool operator>(const p2 &b) const {
        return w>b.w;
    }
};
int n,m,k;
std::vector<p2>u[maxn];
int c[maxk],a[maxk][maxn];
int flagA=1;
char vis[maxn];
long long sct(){
    long long res=0;
    memset(vis,0,sizeof(char)*(n+30));
    priority_queue<p2,std::vector<p2>,std::greater<p2> >q;
    int size=u[1].size();
    for(int i=0;i<size;i++)
        q.push((u[1])[i]);
    vis[1]=1;
    while(!q.empty()){
        p2 t=q.top(); q.pop();
        if(vis[t.v]==1) continue;
        res+=t.w;
        vis[t.v]=1;
        size=u[t.v].size();
        for(int i=0;i<size;i++){
            p2 v=(u[t.v])[i];
            q.push({v.v,v.w});
        }
    }
    return res;
}
// int h[maxk];
long long ans=1152921504606846976;
void dfs(int x){
    if(x>k){
        ans=std::min(ans,sct());
        return;
    }
    // h[x]=0;
    dfs(x+1);
    // h[x]=1;
    for(int i=1;i<=n;i++){
        u[i].push_back({n+x,a[x][i]});
        u[n+x].push_back({i,a[x][i]});
    }
    u[n+x].push_back({n+k+2+x,c[x]});
    u[n+k+2+x].push_back({n+x,c[x]});
    dfs(x+1);
    u[n+x].pop_back();
    u[n+k+2+x].pop_back();
    for(int i=1;i<=n;i++){
        u[i].pop_back();
        u[n+x].pop_back();
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int U,V,W;
        scanf("%d%d%d",&U,&V,&W);
        u[U].push_back({V,W});
        u[V].push_back({U,W});
    }
    for(int i=1;i<=k;i++){
        int tempflag=0;
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                tempflag=1;
        }
        if(tempflag==0)
            flagA=0;
    }
    if(k<=0){
        printf("%lld",sct());
    } else if(flagA==1){
        for(int x=1;x<=k;x++){
            for(int i=1;i<=n;i++){
                u[i].push_back({n+x,a[x][i]});
                u[n+x].push_back({i,a[x][i]});
            }
            u[n+x].push_back({n+k+2+x,c[x]});
            u[n+k+2+x].push_back({n+x,c[x]});
        }
        printf("%lld",sct());
    } else{
        dfs(1);
        printf("%lld",ans);
    }
    return 0;
}