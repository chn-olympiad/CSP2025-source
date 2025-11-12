#include<bits/stdc++.h>
using namespace std;

struct Edge{
  int u,v,w;
};

vector<Edge> e; 
int c[12],a[12][10005];
int fa[10005];

int ff(int x){
  return fa[x]==x?x:fa[x]=ff(fa[x]); 
}

int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout); 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=1;i<=m;++i){
    int u,v,w;
    cin>>u>>v>>w;
    e.push_back({u,v,w});
  }
  if(!k){
    for(int i=1;i<=n;++i){
      fa[i]=i;
    }
    sort(e.begin(),e.end(),[](Edge a,Edge b){
      return a.w<b.w;
    });
    long long ans=0;
    for(auto it:e){
      int u=it.u,v=it.v;
      if(ff(u)!=ff(v)){
        fa[ff(u)]=ff(v);
        ans+=it.w;
      }
    }
    cout<<ans<<"\n";
    return 0;
  }
  for(int i=1;i<=k;++i){
    cin>>c[i];
    int p;
    for(int j=1;j<=n;++j){
      cin>>a[i][j];
      if(a[i][j]==0){
        p=j;
      }
    }
    for(int j=1;j<=n;++j){
      if(p!=j){
        e.push_back({p,j,a[i][j]});
      }
    }
  }
  for(int i=1;i<=n;++i){
    fa[i]=i;
  }
  sort(e.begin(),e.end(),[](Edge a,Edge b){
    return a.w<b.w;
  });
  long long ans=0;
  for(auto it:e){
    int u=it.u,v=it.v;
    if(ff(u)!=ff(v)){
      fa[ff(u)]=ff(v);
      ans+=it.w;
    }
  }
  cout<<ans<<"\n";
}

