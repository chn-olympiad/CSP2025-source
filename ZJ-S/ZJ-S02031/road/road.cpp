#include <bits/stdc++.h>
#define int long long
const int Maxn=2e4+11,Maxm=1e6+21;
using namespace std;
int n,m,k;
struct Edge
{
    int nxt,to,w;
}sid[Maxm<<2];
int head[Maxn],tot;
void add(int u,int v,int w)
{
    sid[++tot]={head[u],v,w};
    head[u]=tot;
}
int c[21];
int a[21][Maxn];
pair<int,pair<int,int> > bian[Maxm<<2];
int cnt;
int ans;
int fa[Maxn];
int Find(int x)
{
    if(x==fa[x]){
        return x;
    }
    return fa[x]=Find(fa[x]);
}
void K()
{
    for(int i=1;i<=cnt;i++){
        int w=bian[i].first;
        pair<int,int> T=bian[i].second;
        int u=Find(T.first),v=Find(T.second);
        if(u==v){
            continue;
        }
        ans+=w;
        fa[v]=u;
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >>n>>m>>k;
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
        bian[i]={w,{u,v}};
    }
    cnt=m;
    for(int i=1;i<=k;i++){
        cin >>c[i];
        ans+=c[i];
        for(int j=1;j<=n;j++){
            cin >>a[i][j];
            add(n+i,j,a[i][j]);
            add(j,n+i,a[i][j]);
            bian[++cnt]={a[i][j],{n+i,j}};
        }
    }
    sort(bian+1,bian+cnt+1);
    K();
    cout <<ans;
}

