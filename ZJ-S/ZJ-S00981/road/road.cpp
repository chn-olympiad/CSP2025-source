#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int N=100010;
typedef long long ll;
bool MBE;
struct Edge{
    int u,v,w;
}E[2000010],E2[2000010];
bool cmp(Edge a,Edge b){return a.w<b.w;}
int n,m,k;
int fa[N];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int a[11][N];
ll Kruskal(int n,int m){
    ll res=0;
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(E+1,E+m+1,cmp);
    for(int i=1;i<=m;i++){
        int x=E[i].u,y=E[i].v,w=E[i].w;
        if(find(x)==find(y))continue;
        res+=w;
        fa[find(x)]=find(y);
    }
    return res;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)cin>>E[i].u>>E[i].v>>E[i].w;
    for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)cin>>a[i][j];
    sort(E+1,E+m+1,cmp);
    ll ans=0;
    int tot=0;
    for(int i=1;i<=m;i++){
        int x=E[i].u,y=E[i].v,w=E[i].w;
        if(find(x)==find(y))continue;
        ans+=(ll)w;
        fa[find(x)]=find(y);
        tot++;
        E2[tot].u=x;E2[tot].v=y;E2[tot].w=w;
    }
    for(int S=0;S<(1<<k);S++){
        int _=tot;
        for(int i=1;i<=tot;i++)E[i]=E2[i];
        ll s=0;
        int cnt=n;
        for(int i=1;i<=k;i++){
            if((S>>(i-1))&1){
                cnt++;
                s+=(ll)a[i][0];
                for(int j=1;j<=n;j++){
                    _++;
                    E[_].u=cnt;E[_].v=j;E[_].w=a[i][j];
                }
            }
        }
        ans=min(ans,s+Kruskal(cnt,_));
    }
    cout<<ans<<"\n";
    return;
}
bool MED;
signed main(){
    // freopen("ex.in","r",stdin);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Tc=1;
    // cin>>Tc;
    while(Tc--)solve();
    // cerr<<"Time : "<<1000*clock()/CLOCKS_PER_SEC<<" ms\n";
    // cerr<<"Memory : "<<fixed<<setprecision(2)<<abs(&MBE-&MED)/1048576.0<<" MB\n";
    return 0;
}