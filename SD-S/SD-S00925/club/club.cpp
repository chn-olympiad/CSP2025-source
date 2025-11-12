#include <bits/stdc++.h>

namespace ToyamaKasumi {
using i64 = int64_t;
using u64 = uint64_t;

#ifdef LOCAL
bool _SYNC = std::cin.tie(nullptr)->sync_with_stdio(false);
#define inf std::cin
#define ouf std::cout
#else
std::ifstream inf("club.in");
std::ofstream ouf("club.out");
#endif

template<typename T, typename U>
T min(T x, U y) { return x < y ? x : y; }
template<typename T, typename U>
T max(T x, U y) { return y < x ? x : y; }
template<typename T, typename U>
bool chmax(T &x, U y) { return x < y ? (x = y, true) : false; }

static constexpr int N = 1e5 + 5, N2 = 216;
int t, n, id;
int a[N][3], cnt[3];
bool vis[N];
i64 f[2][N2 / 2][N2 / 2];
i64 res;

struct Node {
  int maxv, cst;
  int pos, id;
  bool operator<(const Node &rhs) const {
    if (maxv == rhs.maxv) {
      return cst < rhs.cst;
    }
    return maxv > rhs.maxv;
  }
};

int ok[3][2] = {
  {1, 2},
  {0, 2},
  {0, 1}
};

void solve() {
  inf >> n;
  res = 0;
  
  bool flg1 = true; //, flg2 = true;
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      inf >> a[i][j];
//      res += a[i][j];
      if (a[i][1] != 0 or a[i][2] != 0) {
        flg1 = false; 
      }
//      if (a[i][2] != 0) {
//        flg2 = false;
//      }
    }
  }
  
  if (n > 8000) {
    if (flg1) {
      std::vector<int> b(n + 1);
      for (int i = 1; i <= n; ++i) b[i] = a[i][0];
      std::sort(b.begin() + 1, b.end(), std::greater<int> {});
      for (int i = 1; i <= n / 2; ++i) {
        res += b[i];
      }
      ouf << res << '\n';
      return;
    }
    
    for (int i = 0; i < 3; ++i) cnt[i] = 0;
    for (int i = 1; i <= n; ++i) vis[i] = false;
    
    std::vector<Node> seq;
    seq.reserve(n);
    for (int i = 1; i <= n; ++i) {
      int pos = std::max_element(a[i], a[i] + 3) - a[i];
      Node node;
      node.id = i;
      node.pos = pos;
      node.maxv = a[i][pos];
      for (int j = 0; j < 3; ++j) if (j != pos) node.cst += a[i][j];
      seq.push_back(node);
    }
    std::sort(seq.begin(), seq.end());
    
    int id = -1;
    
    for (int i = 0; i < n; ++i) {
      const Node &cur = seq[i];
      if (cnt[cur.pos] == n / 2) {
        id = cur.pos;
        break;
      }
      res += cur.maxv;
      ++cnt[cur.pos];
      vis[cur.id] = true;
    }
    
    if (cnt[0] + cnt[1] + cnt[2] != n) {
      std::vector<Node> seq2;
      seq2.reserve(n);
      for (int i = 1; i <= n; ++i) {
        int ok1 = ok[id][0], ok2 = ok[id][1];
        Node node;
        if (a[i][ok1] > a[i][ok2]) {
          node.pos = ok1;
          node.maxv = a[i][ok1];
          node.cst = a[i][ok2];
        } else {
          node.pos = ok2;
          node.maxv = a[i][ok2];
          node.cst = a[i][ok1];
        }
        seq2.push_back(node);
      }
      std::sort(seq2.begin(), seq2.end());
      
      for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        const Node &cur = seq2[i];
        res += cur.maxv;
      }
    }
    
    ouf << res << '\n';
    
    return;
  }
  
  for (int siz0 = 0; siz0 <= n / 2; ++siz0) {
    for (int siz1 = 0; siz1 <= n / 2; ++siz1) {
      f[0][siz0][siz1] = 0;
    }
  }
  int cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur ^= 1;
    for (int siz0 = 0; siz0 <= n / 2; ++siz0) {
      for (int siz1 = 0; siz1 <= n / 2; ++siz1) {
        f[cur][siz0][siz1] = 0;
      }
    }
    for (int siz0 = 0; siz0 <= min(n / 2, i - 1); ++siz0) {
      for (int siz1 = max(0, i - 1 - siz0 - n / 2); siz1 <= min(n / 2, i - 1 - siz0); ++siz1) {
        if (i - siz0 - siz1 <= n / 2) {
          chmax(f[cur][siz0][siz1], f[cur ^ 1][siz0][siz1] + a[i][2]);
          if (i == n) chmax(res, f[cur][siz0][siz1]);
        }
        if (siz0 + 1 <= n / 2) {
          chmax(f[cur][siz0 + 1][siz1], f[cur ^ 1][siz0][siz1] + a[i][0]);
          if (i == n) chmax(res, f[cur][siz0 + 1][siz1]);
        }
        if (siz1 + 1 <= n / 2) {
          chmax(f[cur][siz0][siz1 + 1], f[cur ^ 1][siz0][siz1] + a[i][1]);
          if (i == n) chmax(res, f[cur][siz0][siz1 + 1]);
        }
      }
    }
  }
  
  ouf << res << '\n';

}
void main() {
  inf >> t;
  while (t--) {
    solve();
  }
}

}

int main() {
  ToyamaKasumi::main();
  return 0;
}

