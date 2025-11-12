#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<int> a(n * m);
  for (int i = 0; i < n * m; i++) cin >> a[i];
  int key = a[0];
  sort(a.rbegin(), a.rend());
  int pos = find(a.begin(), a.end(), key) - a.begin();
  int groups = pos / (2 * n);
  int remain = pos % (2 * n);
  if (remain < n) {
    cout << 2 * groups + 1 << " " << remain + 1 << "\n";
  } else {
    cout << 2 * groups + 2 << " " << 2 * n - remain << "\n";
  }
  return 0;
}
/*
Example 1:
100 97
99  98
*/
