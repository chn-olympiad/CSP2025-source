#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10,NN=2e6+10,M=22;
ll n,m,k,c[M],a[M][N],ans,fa[N],ct;
bool vis[M];
struct P{
    ll x,y,w;
    bool operator<(const P& B){return w<B.w;}
}e[NN],e2[NN];
ll getfa(ll x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
ll kruskal(ll n,ll m){
    sort(e2+1,e2+m+1);ll res=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        ll x=getfa(e2[i].x),y=getfa(e2[i].y);
        if(x!=y) res+=e2[i].w,fa[x]=y;
    }
    return res;
}
ll calc(){
    ll tmm=m,tp=n;
    for(int i=1;i<=m;i++) e2[i]=e[i];
    for(int i=1;i<=k;i++)
        if(vis[i]){
            tp++;
            for(int j=1;j<=n;j++)
                e2[++tmm]={tp,j,a[i][j]};
        }
    return kruskal(tp,tmm);
}
void dfs(ll x,ll ct){
    if(ct>=ans) return;
    if(x>k){ans=min(ans,calc()+ct);return;}
    dfs(x+1,ct),vis[x]=1,dfs(x+1,ct+c[x]),vis[x]=0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("baoli.out","w",stdout);
    cin>>n>>m>>k;ans=1e18;
    for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].w;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    dfs(1,0);cout<<ans<<"\n";
    return 0;
}