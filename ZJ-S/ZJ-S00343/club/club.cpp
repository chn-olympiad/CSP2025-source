#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int n, a[N][4], id[N], ans;
void reb(int x, int t) {
  vector<int> v;
  for (int i = 1; i <= n; i ++)
    if (id[i] == x) {
      int mx = 0;
      for (int j = 0; j < 3; j ++)
        if (j != x) mx = max(mx, a[i][j]);
      v.emplace_back(a[i][x] - mx);
    }

  sort(v.begin(), v.end());
  for (int i = 0; i < t; i ++) ans -= v[i];
}

void work() {
  int cnt[3] = {0, 0, 0};

  scanf("%lld", &n), ans = 0;
  for (int i = 1; i <= n; i ++) {
    for (int j = 0; j < 3; j ++)
      scanf("%lld", &a[i][j]);
    
    if (a[i][0] >= max(a[i][1], a[i][2])) id[i] = 0;
    else if (a[i][1] >= max(a[i][0], a[i][2])) id[i] = 1;
    else id[i] = 2;

    cnt[id[i]] ++, ans += a[i][id[i]];
  }
  
  for (int i = 0; i < 3; i ++)
    if (cnt[i] > n / 2) { reb(i, cnt[i] - n / 2); break; }
  printf("%lld\n", ans);
}

signed main() {

  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);

  int T; scanf("%lld", &T);
  while (T --) work();
}