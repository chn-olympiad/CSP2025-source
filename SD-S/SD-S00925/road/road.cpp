#include <bits/stdc++.h>

namespace ToyamaKasumi {
using i64 = int64_t;
using u64 = uint64_t;

namespace FastRead {

static constexpr int BufSize = 1 << 20;
char buf[BufSize], *st, *ed;

void flushInputStream() {
  std::cin.read(buf, BufSize);
  int cnt = std::cin.gcount();
  st = buf;
  ed = buf + cnt;
}
int getc() {
  if (st == ed) {
    flushInputStream();
    if (st == ed) return EOF;
  }
  return *st++;
}

template <typename T>
void read(T &x) {
  x = 0;
  int ch = getc();
  while (ch < '0' or ch > '9') {
    ch = getc();
  }
  while (ch >= '0' and ch <= '9') {
    x = (x * 10) + (ch - '0');
    ch = getc();
  }
}

}

using FastRead::read;

#ifdef LOCAL
#define ouf std::cout
#else
std::ofstream ouf("road.out");
#endif

static constexpr int N = 1e4 + 15, M = 1.1e6 + 25, K = 11;
int actualN;

namespace DSU {
int fa[N], siz[N];

void init() {
  for (int i = 1; i <= actualN; ++i) {
    fa[i] = i;
    siz[i] = 1;
  }
}
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
//  x = find(x), y = find(y);
#ifdef LOCAL
  assert(fa[x] == x and fa[y] == y);
#endif
  if (x == y) return;
  if (siz[x] < siz[y]) std::swap(x, y);
  fa[y] = x;
  siz[y] += siz[x];
}
}

int n, m, k;
struct Edge {
  int u, v, w;
  bool operator<(const Edge &rhs) const {
    return w == rhs.w ? u < rhs.u : w < rhs.w;
  }
};
//std::set<Edge> orig, curr;
//std::set<Edge> curr;
std::vector<Edge> curr;
//int sel[N];

int kc[K][N];
i64 ans, res;

void main() {
//  inf >> n >> m >> k;
  read(n), read(m), read(k);
  actualN = n + k;
  Edge tmp;
  for (int i = 1; i <= m; ++i) {
//    inf >> tmp.u >> tmp.v >> tmp.w;
    read(tmp.u), read(tmp.v), read(tmp.w);
    curr.push_back(tmp);
  }
  
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
//      inf >> kc[i][j];
      read(kc[i][j]);
      if (j != 0) {
//        curr.insert({n + i, j, kc[i][j]});
        tmp.u = n + i, tmp.v = j, tmp.w = kc[i][j];
        curr.push_back(tmp);
      }
    }
  }
  
  std::sort(curr.begin(), curr.end());
  
  ans = 5e18;
  int mskSiz = (1 << k) - 1;
  for (int msk = 0; msk <= mskSiz; ++msk) {
    res = 0;
//    curr = orig;
    int numK = 0; // popcnt
    for (int i = 1; i <= k; ++i) {
      if (msk & (1 << (i - 1))) {
        ++numK;
        res += (i64) kc[i][0];
//        sel[i] = -1;
//        for (int j = 1; j <= n; ++j) {
//          curr.insert({n + i, j, kc[i][j]}); 
//        }
      }
    }
    
    DSU::init();
    
    int cnt = 0;
    for (auto it = curr.begin(); it != curr.end() and cnt != n + numK - 1; ++it) {
      int u = it->u, v = it->v, w = it->w;
      if (u > n and (! (msk & (1 << ((u - n) - 1))) ) ) continue;
      int fu = DSU::find(u), fv = DSU::find(v);
      if (fu == fv) continue;
      DSU::merge(fu, fv);
      res += (i64) w;
      ++cnt;
//      if (u > n) {
//        if (sel[u - n] == -1) {
//          sel[u - n] = w;
//        } else sel[u - n] = -2;
//      }
    }
    
//    for (int i = 1; i <= k; ++i) {
//      if (msk & (1 << (i - 1))) {
//        if (sel[i] == -2) {
//          res += kc[i][0];
//          continue;
//        }
//        res -= sel[i];
//      }
//    }
    
    if (res < ans) {
      ans = res;
    }
  }
  
  ouf << ans << '\n';
}

}

int main() {
#ifndef LOCAL
  std::freopen("road.in", "r", stdin);
#endif
  std::cin.tie(nullptr)->sync_with_stdio(false);
  ToyamaKasumi::main();
  return 0;
}

