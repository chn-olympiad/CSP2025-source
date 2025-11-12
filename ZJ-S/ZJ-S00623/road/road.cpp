#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+10,NN=2e6+10,M=12;
int n,m,k,c[M],a[M][N],fa[N],ct;
bool vis[M];
ll ans;
struct P{
    int x,y,w;
    bool operator<(const P& B)const{return w<B.w;}
}e[NN],e2[NN];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
ll kruskal(int n,int m){
    sort(e2+1,e2+m+1);ll res=0;int tot=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=getfa(e2[i].x),y=getfa(e2[i].y);
        if(x!=y) res+=e2[i].w,fa[x]=y,tot++;
        if(tot==n-1) return res;
    }
    return res;
}
ll calc(){
    // ll tmm=m,tp=n;
    // for(int i=1;i<=m;i++) e2[i]=e[i];
    int tmm=n-1,tp=n;
    for(int i=1;i<n;i++) e2[i]=e[i];
    for(int i=1;i<=k;i++)
        if(vis[i]){
            tp++;
            for(int j=1;j<=n;j++)
                // e2[++tmm]={tp,j,a[i][j]};
                ++tmm,e2[tmm].x=tp,e2[tmm].y=j,e2[tmm].w=a[i][j];
        }
    return kruskal(tp,tmm);
}
void dfs(int x,ll ct){
    if(ct>=ans) return;
    if(x>k){ans=min(ans,calc()+ct);return;}
    dfs(x+1,ct),vis[x]=1,dfs(x+1,ct+c[x]),vis[x]=0;
}
int rd(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
    return x;
}
int main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // int st=clock();
    // cin>>n>>m>>k;
    n=rd(),m=rd(),k=rd();
    ans=1e18;
    // for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].w;
    for(int i=1;i<=m;i++) e[i].x=rd(),e[i].y=rd(),e[i].w=rd();
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=getfa(e[i].x),y=getfa(e[i].y);
        if(x!=y) e[++ct]=e[i],fa[x]=y;
    }
    for(int i=1;i<=k;i++){
        // cin>>c[i];
        // for(int j=1;j<=n;j++) cin>>a[i][j];
        c[i]=rd();
        for(int j=1;j<=n;j++) a[i][j]=rd();
    }
    dfs(1,0);cout<<ans<<"\n";
    // int ed=clock();
    // cerr<<(double)(ed-st)/CLOCKS_PER_SEC;
    return 0;
}