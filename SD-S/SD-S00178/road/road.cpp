#include<bits/stdc++.h>
#define pp putchar(' ')
#define pn putchar('\n')
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define Fo(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>inline void read(T &x)
{
 x=0;int f=1,c=getchar();while(c<'0'||c>'9'){if(c=='-')f^=1;c=getchar();}
 while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48),c=getchar();}x=f?x:-x;
}
template<class T>inline void wr(T x)
{
 if(x<0){putchar('-'),x=-x;}static int buf[21],top=0;while(x){buf[++top]=x%10,x/=10;}
 if(!top){buf[++top]=0;}while(top){putchar(buf[top--]^'0');}
}
template<class T,class ...A>inline void read(T &x,A &...a){read(x),read(a...);}
namespace my_namespace
{
 using ll=long long;
 const ll INF=0x3f3f3f3f3f3f3f3f;
 const int N=1e4+5,M=1e6+5,K=10;
 int n,m,k,id[N];
 ll c[K],a[K][N],b[K][N],ans=0;
 vector<pair<int,ll>>g[N];
 inline void add(int u,int v,ll w){g[u].push_back({v,w});}
 int f[N];inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
 struct edge{int u,v,w;bool operator<(const edge &b) const {return w<b.w;};}e[M];
 inline void solve()
 {
  fo(i,1,n)f[i]=i;
  fo(i,1,m)read(e[i].u,e[i].v,e[i].w);
  sort(e+1,e+1+m);
  fo(i,1,m)
  {
   int fu=getf(e[i].u),fv=getf(e[i].v);
   if(fu!=fv)ans+=e[i].w,f[fu]=fv,add(e[i].u,e[i].v,e[i].w),add(e[i].v,e[i].u,e[i].w);
  }
 }
 ll dp[N][1030],tmp[1030];int dfn[N],siz[N],fa[N],idx;
 void dfs0(int u,int pa)
 {
  fa[u]=pa,siz[u]=1,dfn[u]=++idx;
  for(pair<int,int>edg:g[u])
  {
   int v=edg.first;
   if(v==pa)continue;
   dfs0(v,u),siz[u]+=siz[v];
  }
 }
 struct ST_table
 {
  int s[22][N];
  inline int query(int l,int r){int t=log2(r-l+1);return min(s[t][l],s[t][r-(1<<t)+1]);}
 }st[K]; 
 void dfs(int u)
 {
  fo(i,0,(1<<k)-1)dp[u][i]=0,tmp[i]=INF;
  fo(S,0,(1<<k)-1)fo(i,1,k)if(S&(1<<(i-1)))if(dfn[i]<dfn[u]||dfn[i]>dfn[u]+siz[u]-1)dp[u][S]=INF;
  for(pair<int,ll>edg:g[u])
  {
   int v=edg.first;
   if(v==fa[u])continue;
   dfs(v);ll w=edg.second;
   fo(S,0,(1<<k)-1)tmp[S]=dp[v][S]+w;
   fo(S,0,(1<<k)-1)
   {
    if(u<=k)tmp[S|(1<<(u-1))]=min(tmp[S+(1<<(u-1))],dp[v][S]+st[u].query(dfn[v],dfn[v]+siz[v]-1)+c[u]);
    fo(i,1,k)if(i!=u&&dfn[i]>=dfn[u]&&dfn[i]<=dfn[u]+siz[u]-1)
    {
     if(S&(1<<(i-1))!=0)tmp[S]=min(tmp[S],dp[v][S]+a[i][u]);
     else tmp[S|(1<<(i-1))]=min(tmp[S|(1<<(i-1))],dp[v][S]+c[i]+a[i][u]);
    }
   }
   fo(S,0,(1<<k)-1)if(dp[u][S]!=INF)dp[u][S]+=tmp[S];
  }
 }
 inline void mian()
 {
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  read(n,m,k);
  solve();if(!k){wr(ans),pn;return;}fo(i,1,n)id[i]=i;
  dfs0(1,0);fo(i,1,k){read(c[i]);fo(j,1,n)read(a[i][j]),b[i][j]=a[i][j];a[i][i]=INF;}
  sort(id+1,id+1+n,[&](int i,int j){return dfn[i]<dfn[j];});
  fo(x,1,k)
  {
   fo(i,1,n)st[x].s[0][i]=a[x][id[i]];
   fo(i,1,20)fo(j,1,n-(1<<i)+1)st[x].s[i][j]=min(st[x].s[i-1][j],st[x].s[i-1][j+(1<<(i-1))]);
  }
  dfs(1);fo(i,1,(1<<k))ans=min(ans,dp[1][i]);wr(ans),pn; 
 }
}
signed main(){my_namespace::mian();return 0;}

