#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
using f64 = double;
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  std::string s;
  std::cin >> s;
  std::vector<i32> cnt(12, 0);
  for (char c : s) 
  	if (isdigit(c)) cnt[c - '0']++;
  for (i32 i = 9; ~i; i--)
  	for (i32 j = 1; j <= cnt[i]; j++) std::cout << i;
  std::cout << endl;
}
// *800.
