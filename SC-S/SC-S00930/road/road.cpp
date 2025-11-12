#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+50,M=2e6+50,K=11;
int n,m,k,c[K],a[K][N];
struct edge{int u,v,w;}ie[M],e[K][N];
bool operator<(edge a,edge b){return a.w<b.w;}
namespace mst{
    int fa[N],siz[N];
    int gf(int u){
        if(u==fa[u])return u;
        int rt=u,v;
        for(;rt!=fa[rt];)rt=fa[rt];
        for(;u!=rt;u=v)v=fa[u],fa[u]=rt;
        return rt;
    }
    int mg(int u,int v){
        if((u=gf(u))==(v=gf(v)))return 0;
        if(siz[u]<siz[v])swap(u,v);
        siz[u]+=v,fa[v]=u;
        return 1;
    }
    void init(int ln){
        for(int i=0;i<ln+5;i++)fa[i]=i,siz[i]=1;
    }
}
ll ans=1e18;
int us[K];
struct node{int u,i;};
bool operator<(node a,node b){
    return e[a.u][a.i].w>e[b.u][b.i].w;}
void dfs(int i=1){
    if(i==k+1){
        ll res=0,pt=n-1;
        priority_queue<node>pq;
        pq.push({0,1});
        // cerr<<"calc:";
        for(int i=1;i<=k;i++)
            if(us[i]){
                pq.push({i,1});
                res+=c[i],pt++;
                // cerr<<i<<' ';
            }
        // cerr<<'\n';
        mst::init(n+k);
        for(int ct=0;ct<pt;){
            assert(pq.size());
            node u=pq.top();pq.pop();
            // cerr<<e[u.u][u.i].u<<' '
            //     <<e[u.u][u.i].v<<' '
            //     <<e[u.u][u.i].w<<' ';
            if(mst::mg(e[u.u][u.i].u,e[u.u][u.i].v)){
                // cerr<<"YES";
                res+=e[u.u][u.i].w,ct++;
            }
            // cerr<<"\n";
            if(e[u.u][++u.i].u){
                // cerr<<"readd:"<<u.u<<"\n";
                pq.push(u);
            }
        }
        // cerr<<"res:"<<res<<"\n";
        ans=min(ans,res);
        return;
    }
    us[i]=1,dfs(i+1);
    us[i]=0,dfs(i+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++)
        cin>>u>>v>>w,ie[i]={u,v,w};
    int ck=0;
    for(int i=1,ps;i<=k;i++){
        cin>>c[ck+1],ps=-1;
        for(int j=1;j<=n;j++){
            cin>>a[ck+1][j];
            if(!a[ck+1][j])ps=j;
        }
        if(ps!=-1&&c[ck+1]==0){
            for(int j=1;j<=n;j++)
                ie[++m]={ps,j,a[ck+1][j]};
        }else{
            ++ck;
            for(int j=1;j<=n;j++){
                // cerr<<a[ck][j]<<'\n';
                e[ck][j]={n+ck,j,a[ck][j]};
            }sort(e[ck]+1,e[ck]+n+1);
        }
    }k=ck;
    sort(ie+1,ie+m+1);
    mst::init(n+k);
    for(int i=1,ct=0;i<=m;i++)
        if(mst::mg(ie[i].u,ie[i].v))
            e[0][++ct]=ie[i];
    if(!k){
        ans=0;
        for(int i=1;i<n;i++)
            ans+=e[0][i].w;
        cout<<ans<<"\n";
    }else dfs(),cout<<ans<<'\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}