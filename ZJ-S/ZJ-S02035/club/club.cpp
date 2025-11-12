#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    vector<int> choice(n);
    vector<int> cnt(3);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int mx = 0;
      for (int j = 0; j < 3; j++) {
        cin >> a[i][j];
        if (a[i][j] > a[i][mx]) mx = j;
      }
      choice[i] = mx;
      cnt[mx]++;
      sum += a[i][mx];
    }
    int ex = -1;
    for (int i = 0; i < 3; i++)
      if (cnt[i] > n / 2) ex = i;
    if (ex == -1) {
      cout << sum << "\n";
      continue;
    }

    priority_queue<int> cuts;
    for (int i = 0; i < n; i++) {
      int mx = choice[i];
      if (mx == ex) {
        int offset =
            max(a[i][(mx + 1) % 3] - a[i][mx], a[i][(mx + 2) % 3] - a[i][mx]);
        cuts.push(offset);
      }
    }
    int _ = cnt[ex] - n / 2;
    while (_--) {
      sum += cuts.top();
      cuts.pop();
    }
    cout << sum << "\n";
  }
  return 0;
}
