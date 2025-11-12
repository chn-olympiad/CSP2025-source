#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=5e4+5;
int fa[N];
int a[N];
int get_fa(int x){
    if(x==fa[x]){
        return x;
    }
    return fa[x]=get_fa(fa[x]);
}
void merge_(int x,int y){
    int xx=get_fa(x),yy=get_fa(yy);
    fa[xx]=yy;
}
int n,m,k;
struct node{
    int u,v,w;
    friend bool operator < (const node &p,const node &q){
        return p.w<q.w;
    }
}e[30000005];

struct edge{
    int v,w;
};
int len=0;
vector<edge> g[N];
int kluskaer(){
     int ans=0;
     for(int i=1;i<=len;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(get_fa(u)==get_fa(v)){
            continue;
        }
        ans+=w;
        merge_(u,v);
     }
     return ans;
}
bool vis[N];
/*
void DFS(int x){
    if(vis[x])return;
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
       int v=g[x][i].v,w=g[x][i].w;
       if(a[v]+a[x]<w){
            g[x][i].w=a[v]+a[x];
       }
       DFS(v);
    }
}*/
void DFS_(int x){
    if(vis[x])return;
    vis[x]=1;
    for(edge i:g[x]){
       int v=i.v,w=i.w;
       e[++len]=(node){x,v,w};
       DFS_(v);
    }
}
int read(){
    int k=0,f=1;
    char c;
    c=getchar();
    while(c<'0'&&c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=k*10+(c-'0');
        c=getchar();
    }
    return k;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int u,v,w;
        //cin>>u>>v>>w;
        u=read(),v=read(),w=read();
        g[u].push_back((edge){v,w});
        g[v].push_back((edge){u,w});
        fa[u]=u;
        fa[v]=v;
    }
    memset(a,0x3f,sizeof a);
    for(int i=1;i<=k;i++){
        int c;
        c=read();
        for(int j=1;j<=n;j++){
            a[j]=read();
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j==k)continue;
                g[j].push_back((edge){k,a[k]+a[j]});
                g[k].push_back((edge){j,a[k]+a[j]});
            }
        }
    }
    memset(vis,0,sizeof vis);
    DFS_(1);
    sort(e+1,e+1+len);
    cout<<kluskaer();
    return 0;
}
/*
4 4 1
 1 4 6
 2 3 7
  4 2 5
 4 3 4
 0 1 8 2 4
*/
