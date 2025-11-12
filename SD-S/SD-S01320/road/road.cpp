#include<bits/stdc++.h>
bool MED;
using namespace std;
#define ll long long
const int N=10005;
const int M=1000005;
const int K=15;
const ll inf=1e17;
int n,m,k,C[K],a[K][N];
struct edge{int x,y,z;}e[M],E[N],fE[M];
namespace solve1{
  int fa[N];
  int find(int x){return fa[x]==x?x:find(fa[x]);}
  void merge(int x,int y){x=find(x),y=find(y);fa[x]=y;}
  void solve(){
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+1+m,[&](edge a,edge b){return a.z<b.z;});
    int cnt=0;
    for(int i=1;i<=m;i++){
      if(find(e[i].x)!=find(e[i].y)){
        merge(e[i].x,e[i].y),E[++cnt]=e[i];
        if(cnt==n-1)break;
      }
    }
    for(int i=1;i<=k;i++){
      cin>>C[i];
      for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    int num;ll ans=inf,res,p;
    for(int S=0;S<(1<<k);S++){
      num=cnt,res=0,p=n;
      for(int i=1;i<=cnt;i++)fE[i]=E[i];
      for(int i=1;i<=k;i++)
        if((1<<(i-1))&S){
          res+=C[i];p++;
          for(int j=1;j<=n;j++)fE[++num]={i+n,j,a[i][j]};
        }
      sort(fE+1,fE+1+num,[&](edge a,edge b){return a.z<b.z;});
      for(int i=1;i<=n+k;i++)fa[i]=i;
      int cur=0;
      for(int i=1;i<=num;i++){
        if(find(fE[i].x)!=find(fE[i].y)){
          merge(fE[i].x,fE[i].y),res+=fE[i].z,cur++;
          if(cur==p-1)break; 
        }
      }
      if(cur==p-1)ans=min(ans,res);
    }
    cout<<ans<<"\n";
  }
} 
bool MST;
int main(){
  //fprintf(stderr,"%.3lf MB\n",(&MED-&MST)/1048576.0);
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin>>n>>m>>k;
  solve1::solve();
  return 0;
}
// ±º‰∏¥‘”∂»O(10* 2^k * n\log n) 64pts
