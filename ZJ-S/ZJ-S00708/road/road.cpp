#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+20;
const int M=1e6+10;
const int K=11;
const int inf=1e9;
int n,m,k;
ll sum;
struct Edge{
    int u,v,w,n;
    bool operator<(const Edge &x)const{return w<x.w;}
}e[M<<1],ee[(M<<1)+(N*20)];
int h[N],tot,new_tot,hh[N];
ll res=inf;
void add(int u,int v,int w){
    e[++tot]={u,v,w,h[u]};
    h[u]=tot;
}
void add_new(int u,int v,int w){
    ee[++new_tot]={u,v,w,hh[u]};
    hh[u]=new_tot;
}
int c[N];
vector<int> cc[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void kruskal(int n){
    sort(ee+1,ee+new_tot+1);
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=new_tot;++i){
        int u=ee[i].u,v=ee[i].v;
        int uu=find(u),vv=find(v);
        if(uu!=vv){
            sum+=ee[i].w;
            fa[uu]=vv;
        }
    }
}
vector<int> d;
void calc(){
    for(int i=1;i<=tot;++i) ee[i]=e[i];
    for(int i=1;i<=n+k;++i) hh[i]=h[i];
    new_tot=tot;
    sum=0;
    if(d.size()){
        for(auto x:d){
            sum+=c[x];
            for(int i=1;i<=n;++i){
                add_new(n+x,i,cc[x][i]);
                add_new(i,n+x,cc[x][i]);
            }
        }
    }
    kruskal(n+d.size());
    res=min(res,sum);
}
void dfs(int st){
    calc();
    for(int i=st;i<=k;++i){
        d.push_back(i);
        dfs(i+1);
        d.pop_back();
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;++i){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        cc[i]=vector<int>(n+1,0);
        for(int j=1,w;j<=n;++j){
            cin>>cc[i][j];
        }
    }
    for(int i=1;i<=tot;++i) ee[i]=e[i];
    for(int i=1;i<=n;++i) hh[i]=h[i];
    new_tot=tot;
    if(k==0){
        kruskal(n);
        cout<<sum<<"\n";
    }
    dfs(1);
    cout<<res<<"\n";
    return 0;
}