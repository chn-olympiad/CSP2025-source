#include<bits/stdc++.h>
using namespace std;
namespace IHAVENOEGG {
  #define ll long long
  const int N = 1e4 + 14;
  const int K = 11;
  const int M = 1e6 + 1e5 + 100;
  // vector<pair<int,int>>e[N];
  struct edge {
    int u, v; int w;
    bool operator<(const edge&o)const{
      return w < o.w;
    }
  } es[M], e[1024][N + K], be[K][N];
  ll dp[1024];
  int f[N + K], a[K][N], b[K];
  int get(int x) {
    if(f[x] == x) return x;
    return f[x] = get(f[x]);
  }
  bool link(int u, int v) {
    u = get(u), v = get(v);
    if(u == v) return 0;
    f[u] = v;
    return 1;
  }
  int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    iota(f + 1, f + n + 1, 1);
    for(int i = 1; i <= m; i++)
      cin >> es[i].u >> es[i].v >> es[i].w;
    bool fl = 0;
    for(int i = 1; i <= k; i++) {
      bool s = 0; cin>>b[i];
      for(int j = 1; j <= n; j++) {
        cin >> a[i][j];
        if(!a[i][j])
          s = 1;
      }
      if(!s) fl = 1;
    }
    if(!fl) {
      for(int i = 1; i <= k; i++) {
        int g = 1;
        for(int j = 1; j <= n; j++)
          if(!a[i][j])
            g = j;
        for(int j = 1; j <= n; j++)
          if(g != j)
            es[++m] = {g, j, a[i][j]};
      }
    }
    sort(es + 1, es + m + 1);
    ll res = 0; int tot = 0;
    for(int j = 1; j <= m; j++)
      if(link(es[j].u, es[j].v))
        e[0][++tot] = es[j], dp[0] += es[j].w;
    res = dp[0];
    if(fl) {
      for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++)
          be[i][j] = {n + i, j, a[i][j]};
        sort(be[i] + 1, be[i] + n + 1);
      }
      for(unsigned int msk = 1; msk < (1u << k); msk++) {
        int ppc = 0; unsigned int mx = msk;
        while(mx) {++ppc, mx ^= mx&-mx;}
        int i;
        for(int j = 0; j < k; j++)
          if((msk >> j) & 1) i = j + 1, dp[msk] += b[j + 1];
        mx = msk ^ (1u << (i - 1));
        merge(e[mx] + 1, e[mx] + n + ppc - 1, be[i] + 1, be[i] + n + 1, es + 1);
        iota(f + 1, f + n + k + 1, 1);
        tot = 0;
        for(int j = 1; j <= n + ppc - 2 + n; j++)
          if(link(es[j].u, es[j].v))
            e[msk][++tot] = es[j], dp[msk] += es[j].w;
        res = min(res, dp[msk]);
      }
    }
    cout << res << '\n';
    return 0;
  }
};
#ifndef LOCAL
int main() {
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  IHAVENOEGG::main();
}
#else
int main(int argc, char*argv[]) {
  if(argc >= 3) {
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
  }
  IHAVENOEGG::main();
}
#endif
/*
g++ -o o road.cpp -std=c++14 -Wall -DLOCAL -O2
*/