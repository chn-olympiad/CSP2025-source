#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using uli=unsigned long long int;
ifstream fin("road.in");
ofstream fout("road.out");
struct DSU{
  vector<size_t> fa;
  DSU(size_t n):fa(n){iota(fa.begin(),fa.end(),(size_t)0);}
  size_t find(size_t x){return fa[x]==x?x:fa[x]=find(fa[x]);}
  bool check(size_t x,size_t y){return find(x)==find(y);}
  void merge(size_t x,size_t y){fa[find(x)]=find(y);}
};
struct Edge{
  size_t u,v;
  ui w;
  friend bool operator<(Edge const& a,Edge const& b){return a.w<b.w;}
};
int main(void){
  ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
  size_t n,m,k;fin>>n>>m>>k;
  vector<Edge> edges(m);
  for (auto& i:edges){
    fin>>i.u>>i.v>>i.w;
    --i.u,--i.v;
  }
  vector<Edge> useful;
  vector<pair<ui,vector<ui>>> a(k);
  for (auto& i:a){
    fin>>i.first;
    i.second.resize(n);
    for (auto& j:i.second) fin>>j;
  }
  auto f=[&](ui enabled){
    auto e=useful;
    uli s=0;
    for (size_t i=0;i<k;++i) if ((enabled>>i)&1u){
      s+=a[i].first;
      for (size_t j=0;j<n;++j) e.push_back({i+n,j,a[i].second[j]});
    }
    sort(e.begin(),e.end());
    DSU ds(n+k);
    for (auto const& i:e) if (!ds.check(i.u,i.v)){
      ds.merge(i.u,i.v);
      s+=i.w;
    }
    return s;
  };
  sort(edges.begin(),edges.end());
  DSU ds(n);
  for (auto const& i:edges) if (!ds.check(i.u,i.v)){
    ds.merge(i.u,i.v);
    useful.emplace_back(i);
  }
  uli ans=numeric_limits<uli>::max();
  for (ui b=0;b<(1u<<k);++b) ans=min(ans,f(b));
  fout<<ans;
}

