/*
jess1ca1o0g3 AFO on 2025.11.1
*/

#include<bits/stdc++.h>
#define i64 long long

using namespace std;
const int N=1e4+5,M=1e6+5;

void solve();
int n,m,k,fa[N],c[N],a[11][N];
i64 ans=1ll<<61;
struct edge{
  int u,v,w;
  bool operator< (edge A){
    return w<A.w;
  }
} e[M],e1[M+N*10];
//vector<pair<int,int>> a[N];

signed main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie();
  int Test=1;
//  scanf("%d",&Test);
  while(Test--) solve();
}

int find(int x){
  if(x==fa[x]) return x;
  fa[x]=find(fa[x]);
  return fa[x];
}

void solve(){
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++){
    cin>>e[i].u>>e[i].v>>e[i].w;
//    a[e[i].u].push_back({e[i].v,e[i].w});
//    a[e[i].v].push_back({e[i].u,e[i].w});
  }
  for(int i=1;i<=k;i++){
    cin>>c[i];
    for(int j=1;j<=n;j++) cin>>a[i][j];
  }
  for(int ss=0;ss<(1<<k);ss++){
    int x=ss,p=m;
    for(int i=1;i<=m;i++){
      e1[i].u=e[i].u;
      e1[i].v=e[i].v;
      e1[i].w=e[i].w;
    }
    int y=0;
    i64 sum=0;
    for(int i=1;x;x/=2,i++){
      if(x&1){
        sum+=c[i];
        y++;
        for(int j=1;j<=n;j++){
          p++;
          e1[p].u=j;
          e1[p].v=y+n;
          e1[p].w=a[i][j];
        }
      }
    }
    sort(e1+1,e1+p+1);
    for(int i=1;i<=n+y;i++) fa[i]=i;
    for(int i=1;i<=p;i++){
      int x=find(e1[i].u),y=find(e1[i].v);
      if(x!=y){
        fa[x]=y;
        sum+=e1[i].w;
      }
    }
    ans=min(ans,sum);
  }
  cout<<ans<<endl;
}