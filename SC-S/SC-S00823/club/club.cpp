#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#define int long long
const int N = 200 + 10;

struct el {
  int fi, se, th;
}s[N];
int n, a[4][N], f[N][N][N], g[N][3];
void solve() {
  std::cin >> n;
  memset(f, 0, sizeof (f));
  bool f1 = true;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[1][i] >> a[2][i] >> a[3][i];
    if (a[2][i] != 0 || a[3][i] != 0) {
      f1 = false;
    }
  }
  
  if (f1) {
    std::sort(a[1] + 1, a[1] + n + 1);
    int ans = 0;
    for (int i = n; i >= n / 2 + 1; --i) {
      ans += a[1][i]; 
    }
    std::cout << ans << '\n';
    return ;
  }
  f[1][1][0] = a[1][1], f[1][0][1] = a[2][1], f[1][0][0] = a[3][1];
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= std::min(n / 2, i); ++j) {
      for (int k = 0; k <= std::min(n / 2, i); ++k) {      	
        int r = i - j - k;
        if (r > n / 2) continue;
        if (j) {
        	f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - 1][k] + a[1][i]);
		    }
		    if (k) {
		      f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k - 1] + a[2][i]); 
        }
        if (r) {
          f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k] + a[3][i]);
        }
      }
    }
  }
  
  int ans = -1;
  for (int i = 1; i <= n / 2; ++i) {
    for (int j = 1; j <= n / 2; ++j) {
      int r = n - i - j;
      if (r > n / 2) continue;
      ans = std::max(ans, f[n][i][j]); 
    }
  }
  
  std::cout << ans << '\n';
}

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int t;
  std::cin >> t;
  while(t--) solve();
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}