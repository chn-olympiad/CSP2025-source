#include <bits/stdc++.h>
#define endl '\n'
#define fir first
#define sec second
// using std::endl;
using i32 = int;
using i64 = long long;
using p32 = std::pair<i32, i32>;
using p64 = std::pair<i64, i64>;
const i64 inf64 = 2e18;
void solve(i32 _);
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  i32 T = 1;
  // std::cin >> T;
  for (i32 i = 1; i <= T; i++) solve(i);
}
const i32 N = 2e5 + 5;
std::string s[3][N];
p32 ss[3][N];
void solve(i32 _) {
  i32 n, q;
  i32 tmp = 0;
  std::cin >> n >> q;
  for (i32 i = 1; i <= n; i++) std::cin >> s[1][i] >> s[2][i], tmp += s[1][i].size() + s[2][i].size();
  if (n <= 2000 && q <= 2000 && tmp <= 5000) {
    for (i32 i = 1; i <= q; i++) {
      i64 ans = 0;
      std::string a, b;
      std::cin >> a >> b;
      for (i32 j = 1; j <= n; j++) {
        i32 pos = a.find(s[1][j]);
        if (~pos) {
          std::string tmp = a.substr(0, pos) + s[2][j];
          if (tmp + a.substr(pos + s[2][j].size(), (i32)a.size() - (pos + s[2][j].size())) == b) ans++;
        }
      }
      std::cout << ans << endl;
    }
  } else {
    for (i32 i = 1; i <= n; i++) {
      ss[1][i] = {s[1][i].find("b"), s[1][i].size()};
      ss[2][i] = {s[2][i].find("b"), s[2][i].size()};
    }
    for (i32 i = 1; i <= q; i++) {
      i64 ans = 0;
      std::string a, b;
      std::cin >> a >> b;
      i32 x = a.find("b"), y = b.find("b");
      i32 delta = x - y;
      for (i32 i = 1; i <= n; i++) {
        if ((i32)ss[1][i].fir - ss[2][i].fir == delta && ss[1][i].sec <= a.size() - x) ans++;
      }
      std::cout << ans << endl;
    }
  }
}
// g++ replace.cpp -o replace -O2 -static -std=c++14
