#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}
const int N=1e4+5,M=1e6+5;
int n,m,k,ans;
struct edge{
    int u,v,w;
    bool operator<(const edge &x)const{
        return w<x.w;
    }
}e_all[M];
struct dsu{
    int fa[N+10];
    void init(int n){
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
    int find(int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }
    bool merge(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return 0;
        fa[x]=y;
        return 1;
    }
};
int c[10],f[1<<10],C[1<<10],a[10][N],lg[1<<10];
vector<edge>g[1<<10],b[10];
int get_all(){
    int res=0;
    dsu d;d.init(n);
    for(int i=1;i<=m;i++){
        if(d.merge(e_all[i].u,e_all[i].v)){
            res+=e_all[i].w;
            g[0].push_back(e_all[i]);
        }
    }
    return res;
}
vector<edge>merge(vector<edge>x,vector<edge>y){
    vector<edge>res;
    for(auto i=x.begin(),j=y.begin();i!=x.end()||j!=y.end();)
        if((j==y.end())||(i!=x.end()&&(*i)<(*j)))res.push_back(*i),++i;
        else res.push_back(*j),++j;
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    // n=1e4;m=1e6;k=10;
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        // int u=(i-1)%n+1,v=u%n+1,w=1e9;
        e_all[i]={u,v,w};
    }
    sort(e_all+1,e_all+1+m);
    for(int i=0;i<k;i++){
        c[i]=read();
        // c[i]=1e9;
        for(int j=1;j<=n;j++){
            a[i][j]=read();
            // a[i][j]=1e9;
            b[i].push_back({j,n+i+1,a[i][j]});
        }
        sort(b[i].begin(),b[i].end());
    }
    ans=f[0]=get_all();
    lg[0]=-1;for(int s=1;s<1<<k;s++)lg[s]=lg[s>>1]+1;
    for(int s=1;s<1<<k;s++){
        int p=lg[s&-s];
        auto G=merge(g[s^(1<<p)],b[p]);
        f[s]=C[s]=C[s^(1<<p)]+c[p];
        dsu d;d.init(n+k);
        for(auto [u,v,w]:G){
            if(d.merge(u,v)){
                f[s]+=w;
                g[s].push_back((edge){u,v,w});
            }
        }
    }
    for(int i=0;i<1<<k;i++)
        ans=min(ans,f[i]);
    printf("%lld\n",ans);
    return 0;
}