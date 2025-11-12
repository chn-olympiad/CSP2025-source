#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i=(a);i<(b);++i)
#define forv(v,adj,fs) for(int v:adj)if(v!=fs)
#define forvw(v,w,adj,fs) for(auto[v,w]:adj)if(v!=fs)
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;
const int _inf32 = 0x3f3f3f3f;
const i64 _inf64 = 0x3f3f3f3f3f3f3f3f;
#define ckmax(a,b) (a=max(a,b))
#define ckmin(a,b) (a=min(a,b))
#define pb emplace_back
#define FI first
#define SE second

const int MaxN = int(1e4+7);
const int V = MaxN+30;
const int MaxM = int(1e6+7);

int n, m, k; i64 cost[17];
vector<tuple<i64,int,int>> edges;

namespace dsu {
  int fa[V], cnt[V];
  int tot;
  int find(int x) {
    while (x^fa[x]) x = fa[x];
    return x;
  }
  class undo_type {
  public :
    int *p, v;
  };
  undo_type stk[V*2]; int top;
  void undo_push(int &x) {
    stk[top++] = {&x, x};
  }
  void init() {
    top = 0;
    tot = n+k;
    iota(fa, fa+tot, 0);
    fill(cnt, cnt+tot, 1);
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (cnt[u] > cnt[v]) swap(u, v);
    undo_push(fa[u]);
    undo_push(cnt[v]);
    fa[u] = v, cnt[v] += cnt[u];
  }
  void undo(int T = 2) {
    while (T--) {
      auto t = stk[--top];
      *t.p = t.v;
    }
  }
  bool same(int u, int v) { return find(u) == find(v); }
}

namespace work {
  i64 ans = _inf64;
  int vis[17];
  void DFS(int i, i64 sum) {
    if (sum >= ans) return;
    if (i == edges.size()) {
      // cerr << sum << endl;
      ans = sum;
      return;
    }
    auto [w, u, v] = edges[i];
    if (dsu::same(u, v)) {
      DFS(i+1, sum);
      return;
    }
    if (u < n && v < n) {
      dsu::merge(u, v);
      DFS(i+1, sum+w);
      dsu::undo();
    }
    else {
      int id = u-n;
      if (vis[id] == 1) {
        dsu::merge(u, v);
        DFS(i+1, sum+w);
        dsu::undo();
      }
      else {
        int tmp = vis[id];
        vis[id] = -1;
        // if (i == 0) {
        //   For (j, 0, dsu::tot) cerr << dsu::fa[j] << " \n"[j == dsu::tot-1];
        // }
        DFS(i+1, sum);
        vis[id] = tmp;
        if (vis[id] == 0) {
          // if (i == 0) {
          //   For (j, 0, dsu::tot) cerr << dsu::fa[j] << " \n"[j == dsu::tot-1];
          // }
          vis[id] = 1;
          dsu::merge(u, v);
          DFS(i+1, sum+w+cost[id]);
          dsu::undo();
          vis[id] = 0;
        }
      }
    }
  }

  void main() {
    scanf("%d%d%d", &n, &m, &k);
    For (i, 0, m) {
      int u, v; i64 w;
      scanf("%d%d%lld", &u, &v, &w);
      --u, --v;
      edges.pb(w,u,v);
    }
    For (i, 0, k) {
      int u = n+i;
      scanf("%lld", cost+i);
      For (j, 0, n) {
        i64 w;
        scanf("%lld", &w);
        edges.pb(w,u,j);
      }
    }
    sort(edges.begin(), edges.end());
    vector<tuple<i64,int,int>> redges;
    dsu::init();
    for (auto [w, u, v] : edges) {
      if (u < n && v < n) {
        if (dsu::same(u, v)) continue;
        dsu::merge(u, v);
        redges.pb(w,u,v);
      }
      else {
        redges.pb(w,u,v);
      }
    }
    edges = redges;
    dsu::init();
    DFS(0, 0);
    printf("%lld\n", ans);
  }
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  work::main();
  fclose(stdin);
  fclose(stdout);
  return 0;
}