#include <bits/stdc++.h>

namespace ToyamaKasumi {
using i64 = int64_t;
using u64 = uint64_t;

#ifdef LOCAL
bool _SYNC = std::cin.tie(nullptr)->sync_with_stdio(false);
#define inf std::cin
#define ouf std::cout
#else
std::ifstream inf("employ.in");
std::ofstream ouf("employ.out");
#endif

static constexpr i64 Mod = 998244353;
static constexpr int N = 508;

//namespace BIT {
//#define lowbit(x) ((x)&(-(x)))
//int tr[N];
//void add(int x) {
//  for (; x < N; x += lowbit(x))
//    ++tr[x];
//}
//int sum(int x) {
//  int res = 0;
//  for (; x > 0; x -= lowbit(x))
//    res += tr[x];
//  return res;
//}
//}

int n, m, c[N];
//i64 fac[N];
i64 res;
int idx[N];
std::string str;

void main() {
  inf >> n >> m >> str;
  for (int i = 1; i <= n; ++i) {
    inf >> c[i];
    idx[i] = i;
  }
  
//  bool flg = true;
//  for (int i = 0; i < n; ++i) {
//    if (str[i] == '0') {
//      flg = false;
//      break;
//    }
//  }
//  
//  if (flg) {
//    int cnt = 0;
//    fac[0] = 1;
//    for (int i = 1; i <= n; ++i) {
//      if (c[i] == 0) ++cnt;
//      fac[i] = (fac[i - 1] * (i64) i) % Mod;
//    }
//    res = fac[cnt];
//    for (int i = 1; i <= n; ++i) {
//      if (c[i] == 0) continue;
//      
//    }
//    
//    return;
//  }
  
  if (n > 30) {
    res = 1;
    for (int i = 2; i <= n; ++i) {
      (res *= (i64) i) %= Mod; 
    }
    ouf << res << '\n';
    return;
  }
  
  do {
    int ok = 0, cnt = 0;
    for (int j = 1; j <= n; ++j) {
      int i = idx[j];
      if (cnt >= c[i]) {
        ++cnt;
        continue;
      }
      
      if (str[j - 1] == '1') {
        ++ok;
      } else {
        ++cnt;
      }
    }
    if (ok >= m) ++res;
    if (res == Mod) res = 0;
  } while(std::next_permutation(idx + 1, idx + 1 + n));
  
  ouf << res << '\n';
  
}

}

int main() {
  ToyamaKasumi::main();
  return 0;
}

