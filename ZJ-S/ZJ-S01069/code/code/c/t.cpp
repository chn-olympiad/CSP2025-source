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
#define siz(x) (int)x.size()
using ull=unsigned long long;
const int N=4e5+3, M=5.4e6+3, K=2.8e6+3;
mt19937_64 rnd(3478324);
int n, m, l[N], r[N], vcnt, ans[N];
char str[M];
vector<char> s[N], t[N];
ull w[M], d[N], st[N];
vector<int> pm[N], pq[N];
vector<int> pi[M], pim[M];

int tr1[K][26], tot1, rt[K], tr2[K][26], tot2, tg[K], tg2[K];

void read(vector<char> &s){
  cin>>str;
  int len=strlen(str);
  s.resize(len);
  rep(i, 0, len-1) s[i]=str[i]-'a';
}

void get(vector<char> &s, vector<char> &t, int &l, int &r){
  rep(i, 0, siz(s)-1) if(s[i]!=t[i]) r=i;
  per(i, siz(s)-1, 0) if(s[i]!=t[i]) l=i;
}

void f(int p, int x){
  if(p){
    tg[p]+=x;
    tg2[p]+=x;
  }
}

void pushdown(int p){
  rep(i, 0, 25) f(tr2[p][i], tg[p]);
  tg[p]=0;
}

int merge(int x, int y){
  if(!x || !y) return x+y;
  pushdown(x), pushdown(y);
  rep(i, 0, 25){
    int &v1=tr2[x][i], &v2=tr2[y][i];
    v1=merge(v1, v2);
  }
  if(siz(pi[y])){
    if(siz(pi[x])<siz(pi[y])) pi[x].swap(pi[y]), swap(tg2[x], tg2[y]);
    for(auto id:pi[y]){
      ans[id]+=tg2[y];
      ans[id]-=tg2[x];
      pi[x].emplace_back(id);
    }
    pi[y].clear();
  }
  return x;
}

void dfs(int u){
  rep(i, 0, 25) if(tr1[u][i]){
    int v=tr1[u][i];
    dfs(v);
    rt[u]=merge(rt[u], rt[v]);
  }
  for(auto id:pim[u]){
    int p=rt[u];
    rep(i, r[id]+1, siz(s[id])-1)
      p=tr2[p][s[id][i]];
    if(!p) continue;
    f(p, 1);
  }
}

void push(int u){
  for(auto x:pi[u]) ans[x]+=tg2[u];
  pushdown(u);
  rep(i, 0, 25) if(tr2[u][i]){
    int v=tr2[u][i];
    push(v);
  }
  tg[u]=tg2[u]=0;
}

signed main(){
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
  rep(i, 1, 5e6) w[i]=rnd();
  rep(i, 1, n+m){
    read(s[i]), read(t[i]);
    if(siz(s[i])!=siz(t[i])) continue;
    get(s[i], t[i], l[i], r[i]);
    rep(j, l[i], r[i]){
      st[i]+=w[j-l[i]+1]*(s[i][j]+3);
      st[i]+=w[j-l[i]+1+(r[i]-l[i]+1)]*(t[i][j]+3);
    }
    d[++vcnt]=st[i];
  }
  sort(d+1, d+vcnt+1), vcnt=unique(d+1, d+vcnt+1)-d-1;
  rep(i, 1, n+m){
    if(siz(s[i])!=siz(t[i])) continue;
    st[i]=lower_bound(d+1, d+vcnt+1, st[i])-d;
    if(i<=n) pm[st[i]].emplace_back(i);
    else pq[st[i]].emplace_back(i);
  }
  rep(col, 1, vcnt){
    auto &qm=::pm[col], &qd=::pq[col];
    rep(i, 1, tot1){
      pim[i].clear();
      rep(j, 0, 25) tr1[i][j]=0;
      rt[i]=0;
    }
    rep(i, 1, tot2){
      rep(j, 0, 25) tr2[i][j]=0;
      tg[i]=tg2[i]=0;
      pi[i].clear();
    }
    tot1=1, tot2=0;
    for(auto id:qd){
      int p=1;
      per(i, l[id]-1, 0){
        int &ch=tr1[p][s[id][i]];
        if(!ch) ch=++tot1;
        p=ch;
      }
      if(!rt[p]) rt[p]=++tot2;
      int q=rt[p];
      rep(i, r[id]+1, siz(s[id])-1){
        int &ch=tr2[q][s[id][i]];
        if(!ch) ch=++tot2;
        q=ch;
      }
      pi[q].emplace_back(id);
    }
    for(auto id:qm){
      int p=1;
      per(i, l[id]-1, 0)
        p=tr1[p][s[id][i]];
      if(!p) continue;
      pim[p].emplace_back(id);
    }
    dfs(1);
    push(rt[1]);
  }
  rep(i, n+1, n+m) cout<<ans[i]<<'\n'; 
  cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
}