#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using i64 = long long;
using pii = pair <int, int>;

constexpr int N = 1e5 + 7;

int T, n, a[N][4], f[201][201][201];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++) 
    for (int j = 1; j <= 3; j ++) cin >> a[i][j];

  memset(f, 0, sizeof(f));
  
  for (int i = 1; i <= n; i ++) {
    for (int j = 0; j <= i; j ++) {
      for (int k = 0; k <= i; k ++) {
        if (j + k > i) continue;
        if (j) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][1]);
        if (k) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][2]);
        if (i - j - k) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][3]);
      }
    }
  }

  int ans = 0;
  for (int j = 0; j <= n; j ++) {
    for (int k = 0; k <= n; k ++) {
      if (j + k > n) continue;
      if (j > n / 2) continue;
      if (k > n / 2) continue;
      if ((n - j - k) > n / 2) continue;
      ans = max(ans, f[n][j][k]);
    }
  }
  
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  for (cin >> T; T --; ) solve();
  return 0;
}