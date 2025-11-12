#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr int N = 1e5 + 5;

int T, n, cnt[3], sta[N], cntt;

array<pair<int, int>, 3> a[N];

ll ans = 0;

int main() {
  assert(freopen("club.in", "r", stdin));
  assert(freopen("club.out", "w", stdout));
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> n;
    ans = 0;
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 3; ++j) {
        cin >> a[i][j].first;
        a[i][j].second = j;
      }
      sort(a[i].begin(), a[i].end(), greater<pair<int, int>>());
      ans += a[i][0].first;
      ++cnt[a[i][0].second];
    }
    int id = -1;
    for (int i = 0; i < 3; ++i) {
      if (cnt[i] > n / 2) id = i;
    }
    if (id == -1) {
      cout << ans << '\n';
      continue;
    }
    cntt = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i][0].second == id) {
        sta[++cntt] = a[i][0].first - a[i][1].first;
      }
    }
    sort(sta + 1, sta + cntt + 1);
    for (int i = 1; i <= cnt[id] - n / 2; ++i) {
      ans -= sta[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
