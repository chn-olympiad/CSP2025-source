#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 1e5 + 10;
int n;
int a[N][5];
int b[N][5], tot[5];
int id[5];
int ans;
signed Luogu_UID_947527() {
  cin >> n;
  ans = 0;
  for (int i = 1; i <= 3; ++ i) {
    tot[i] = 0;
  }
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= 3; ++ j) {
      cin >> a[i][j];
      id[j] = j;
    }
    sort(id + 1, id + 3 + 1, [&](int x, int y) {
      return a[i][x] > a[i][y]; 
    });
    b[id[1]][++ tot[id[1]]] = a[i][id[1]] - a[i][id[2]];
    ans += a[i][id[1]]; 
  }
  for (int i = 1; i <= 3; ++ i) {
    id[i] = i;
  }
  sort(id + 1, id + 3 + 1, [&](int x, int y) {
    return tot[x] > tot[y];
  });
  sort(b[id[1]] + 1, b[id[1]] + tot[id[1]] + 1, greater<int>());
  for (; tot[id[1]] > n / 2;) {
    ans -= b[id[1]][tot[id[1]] --];
  }
  cout << ans << endl;
  return 0;
}
signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T --) {
    Luogu_UID_947527();
  }
  return 0;
}
