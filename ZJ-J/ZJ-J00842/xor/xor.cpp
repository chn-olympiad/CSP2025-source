#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
using f64 = double;
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  // RICKROLL! /hanx/hanx/hanx
  // freopen("xor.in", "r", stdin);
  // freeopen("xor.out", "w", stdout);
  // Don't forget:
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  i32 n, k, ans = 0;
  std::cin >> n >> k;
  std::vector<i32> a(n + 2, 0), p(n + 2, 0);
  for (i32 i = 1; i <= n; i++) std::cin >> a[i];
  for (i32 i = 1; i <= n; i++) p[i] = a[i] ^ p[i - 1];
  std::set<i32> st;
  for (i32 i = 0; i <= n; i++) {
    if (st.count(p[i] ^ k)) ans++, st.clear();
    st.insert(p[i]);
  }
  std::cout << ans << endl;
  return 0; 
}
// *1300.
