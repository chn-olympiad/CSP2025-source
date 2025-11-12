#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); ++i)
#define per(i, j, k) for(int i=(j); i>=(k); --i)
using namespace std;
namespace DEBUG{
  template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
  template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d || *s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<",";
    _debug(s+1, nxt...);
  } 
  template<class T> ostream& operator<<(ostream &c, vector<T> v){
    c<<'[';
    for(auto x:v) c<<x<<", ";
    c<<']';
    return c;
  }
  #define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
} using namespace DEBUG;
#define int long long
const int N=1e4+23, inf=1e15;
struct edge{
  int u, v, w;
  edge(int a, int b, int c):u(a), v(b), w(c) {}
};

bool operator<(edge a, edge b){
  return a.w<b.w;
}

int n, m, k, f[N], fa[N], siz[N], ans=inf, c[12];
vector<edge> a[12];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void merge(int x, int y){
  x=find(x), y=find(y);
  if(siz[x]<siz[y]) siz[y]+=siz[x], fa[x]=y;
  else siz[x]+=siz[y], fa[y]=x;
}

vector<edge> calc(vector<edge> &e, int del){
  rep(i, 1, n+k) fa[i]=i, siz[i]=1;
  int sum=0;
  vector<edge> ae;
  for(auto &x:e){
    int u=x.u, v=x.v, w=x.w;
    if(find(u)!=find(v)){
      ae.emplace_back(x);
      merge(u, v);
      sum+=w;
    }
  } 
  ans=min(ans, sum+del);
  return ae;
}


vector<edge> nw;

void dfs(int i, vector<edge> e, int del){
  if(i==k+1) return;
  dfs(i+1, e, del);
  del+=c[i];
  nw=e;
  for(auto &x:a[i]) nw.emplace_back(x);
  inplace_merge(nw.begin(), nw.begin()+e.size(), nw.end());
  nw=calc(nw, del);
  dfs(i+1, nw, del);
}

signed main(){
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m>>k;
  vector<edge> e(m, edge(0, 0, 0));
  rep(i, 0, m-1) cin>>e[i].u>>e[i].v>>e[i].w;
  sort(e.begin(), e.end());
  e=calc(e, 0);
  rep(i, 1, k){
    cin>>c[i];
    rep(j, 1, n){
      int w; cin>>w;
      a[i].emplace_back(n+i, j, w);
    }
    sort(a[i].begin(), a[i].end());
  }
  dfs(1, e, 0);
  cout<<ans;
  cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
}