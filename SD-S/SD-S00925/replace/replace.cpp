#include <bits/stdc++.h>

namespace ToyamaKasumi {
using i64 = int64_t;
using u64 = uint64_t;

template<typename T, typename U>
T max(T x, U y) { return x < y ? x : y; }
template<typename T, typename U>
bool chmax(T &x, U y) { return x < y ? (x = y, true) : false; }


#ifdef LOCAL
bool _SYNC = std::cin.tie(nullptr)->sync_with_stdio(false);
#define inf std::cin
#define ouf std::cout
#else
std::ifstream inf("replace.in");
std::ofstream ouf("replace.out");
#endif

static constexpr int N = 2e5 + 5, L = 5e6 + 5;
static constexpr i64 Base = 131, Mod = 220154147;

int n, q, maxL;
std::string s[N], t[N];

//std::vector<int> kmp(const std::string &x, std::vector<int> &pi, int ori) {
//  pi[0] = 0;
//  int l = x.size();
//  
//  std::vector<int> ans;
//  
//  for (int i = 1; i < l; ++i) {
//    j = pi[i - 1];
//    while (j > 0 and x[i] != x[j]) j = pi[j - 1];
//    if (x[i] == x[j]) ++j;
//    pi[i] = j;
//    if (pi[i] == ori) ans.push_back(i);
//  }
//  return ans;
//}

void main() {
  inf >> n >> q;
  for (int i = 1; i <= n; ++i) {
    inf >> s[i] >> t[i];
    chmax(maxL, s[i].size());
    chmax(maxL, t[i].size());
  }
  std::string a, b;
  for (int i = 1; i <= q; ++i) {
    int res = 0;
    inf >> a >> b;
    int l = a.size();
//    std::vector<int> pi(maxL + l + 2);
    for (int j = 1; j <= n; ++j) {
//      std::string x = s[i] + '#' + a;
//      std::vector<int> vi = kmp(x, pi, s[i].size());
//      // sub s[i].size() + 1
//      
      int g = s[j].size();
      for (int k = 0; k < l; ++k) {
        if (a.substr(k, g) == s[j]) {
          std::string X = a.substr(0, k) + t[j] + a.substr(k + g);
          if (X == b) {
            ++res;
            break;
          }
        }
      }
    }
    ouf << res << '\n';
    
  }
}

}

int main() {
  ToyamaKasumi::main();
  return 0;
}

