#include <bits/stdc++.h>
// #define endl '\n'
using std::endl;
using i32 = int;
using i64 = long long;
void solve(i32 _);
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  i32 T = 1;
  // std::cin >> T;
  for (i32 i = 1; i <= T; i++) solve(i);
}
const i32 N = 505;
const i64 p = 998244353;
inline i64 mod(i64 x) { return (x % p + p) % p; }
i32 n, m;
std::string s;
i32 cnt[2], c[N], a[N];
bool check() {
  i32 pre = 0, cnt = 0;
  for (i32 i = 1; i <= n; i++) {
    if (c[a[i]] > pre && (s[i] - '0')) {
      cnt++;
    } else pre++;
  }
  return cnt >= m;
}
void solve(i32 _) {
  std::cin >> n >> m;
  std::cin >> s; s = ' ' + s;
  for (i32 i = 1; i <= n; i++) cnt[s[i] - '0']++;
  for (i32 i = 1; i <= n; i++) std::cin >> c[i];
  for (i32 i = 1; i <= n; i++) a[i] = i;
  i64 ans = check();
  while (std::next_permutation(a + 1, a + n + 1)) {
    ans = mod(ans + check());
  }
  std::cout << ans << endl;
}
// g++ employ.cpp -o employ -O2 -std=c++14 -static