// hm2ns & sakanaction & RADWIMPS
#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128 i128;
const int N=1e4+444;
struct work{
  int u;int v;
  i64 w;
};
vector<work> e;
vector<work> ue;
vector<work> ced;
vector<work> ap[100];
bool cmp(work x,work y){
  return x.w<y.w;
}
i64 cs[100];
i64 el[100][N];
int fa[N];
int _find(int u){
  return fa[u]==u?u:fa[u]=_find(fa[u]);
}
int main(){

  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++){
    int u,v,w;cin>>u>>v>>w;
    e.push_back(work{u,v,w});
  }
  sort(e.begin(),e.end(),cmp);
  int is0=1;
  for(int i=1;i<=k;i++){
    cin>>cs[i];
    if(cs[i]!=0)is0=0;
    for(int j=1;j<=n;j++){
      cin>>el[i][j];
      ap[i].push_back(work{i+n,j,el[i][j]});
    }
  }
  i64 ans=1e18;
  if(k<=5){
    for(int stat=0;stat<(1<<k);stat++){
      i64 tans=0;
      for(int tr=0;tr<k;tr++){
        if(((stat>>tr)&1)){
          for(work v:ap[tr+1]){
            ced.push_back(v);
          }
          tans+=cs[tr+1];
        }
      }
      sort(ced.begin(),ced.end(),cmp);
      int t1=0;int t2=0;
      while(t1<e.size()&&t2<ced.size()){
        if(e[t1].w<ced[t2].w){
          ue.push_back(e[t1]);
          t1++;
        }
        else{
          ue.push_back(ced[t2]);
          t2++;
        }
      }
      while(t1<e.size()){
        ue.push_back(e[t1]);
        t1++;
      }
      while(t2<ced.size()){
        ue.push_back(ced[t2]);
        t2++;
      }
      for(int i=1;i<=n+k;i++)fa[i]=i;
      for(work s:ue){
        int u=s.u;int v=s.v;int w=s.w;
        int tb1=_find(u);
        int tb2=_find(v);
        if(tb1!=tb2){
          fa[tb1]=tb2;
          tans+=w;
        }
      }
      ans=min(ans,tans);
      ue.clear();
      ced.clear();
    }
  }
  else if(is0){
    i64 tans=0;
    for(int i=1;i<=k;i++){
      for(work v:ap[i])
        e.push_back(v);
    }
    sort(e.begin(),e.end(),cmp);
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(work s:e){
      int u=s.u;int v=s.v;int w=s.w;
      int tb1=_find(u);
      int tb2=_find(v);
      if(tb1!=tb2){
        fa[tb1]=tb2;
        tans+=w;
      }
    }
    ans=min(ans,tans);
  }
  
  cout<<ans;

	return 0;
}
