#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;
template<typename T>inline void read(T&x){
  x=0;bool f=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
  while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
  if(f)x=~x+1;
}
#define ll long long
const int N=2e6+5;
const ll inf=10000000000000000;
struct edge{
  int u,v;ll w;
}e[N],t[N];
int cnt,tot,fa[N],n,m,k;
int find(int x){if(fa[x]!=x)fa[x]=find(fa[x]);return fa[x];}
ll a[11][10005],c[11],sum,res;
void kr(int tp){
  sum=0;
  sort(e+1,e+cnt+1,[](const edge&a,const edge&b){return a.w<b.w;});
  for(int i=1;i<=n+k;++i)fa[i]=i;
  for(int i=1;i<=cnt;++i){
    int u=e[i].u,v=e[i].v;ll w=e[i].w;
    int fu=find(u),fv=find(v);
    if(fu==fv)continue;
    fa[fu]=fv;
    sum+=w;
    if(tp)t[++tot]=e[i];
  }
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  read(n);read(m);read(k);
  for(int i=1;i<=m;++i)read(e[i].u),read(e[i].v),read(e[i].w);
  for(int i=1;i<=k;++i){
    read(c[i]);
    for(int j=1;j<=n;++j)read(a[i][j]);
  }
  cnt=m,kr(1);
  res=inf;
  for(int cur=0;cur<(1<<k);++cur){
    ll ret=0;
    for(int i=1;i<=tot;++i)e[i]=t[i];
    cnt=tot;
    for(int i=1;i<=k;++i)
      if(cur&(1<<(i-1))){
        ret+=c[i];
        for(int j=1;j<=n;++j)e[++cnt]=(edge){n+i,j,a[i][j]};
      }
    kr(0);res=min(res,ret+sum);
  }
  printf("%lld",res);
  return 0;
}
