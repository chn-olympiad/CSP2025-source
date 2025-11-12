#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  vector<char> t;
  for (char c : s)
    if (isdigit(c)) t.push_back(c);
  sort(t.rbegin(), t.rend());
  for (char c : t) cout << c;
  cout << "\n";
  return 0;
}
