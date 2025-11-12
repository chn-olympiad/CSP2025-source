#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int P = 998244353;
constexpr int N = 505;

int n, m, c[N];
int dp[1 << 19][20];
ll fac[N];
string s;
vector<int> vec;

void reduce(int& u) {
  u -= (u >= P) * P;
}

int main() {
  assert(freopen("employ.in", "r", stdin));
  assert(freopen("employ.out", "w", stdout));
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  cin >> s;
  s = ' ' + s;
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i - 1] * i % P;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  if (m == n) {
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '0' || c[i] == 0) {
        cout << 0;
        return 0;
      }
    }
    cout << fac[n];
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 0; i < (1 << n) - 1; ++i) {
    int up = __builtin_popcount(i);
    for (int j = 0; j <= up; ++j) {
      if (!dp[i][j]) continue;
      for (int k = 0; k < n; ++k) {
        if (i >> k & 1) continue;


        if (s[up + 1] == '0' || c[k + 1] <= j) {
          reduce(dp[i | (1 << k)][j + 1] += dp[i][j]);
        } else {
          reduce(dp[i | (1 << k)][j] += dp[i][j]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n - m; ++i) {
    reduce(ans += dp[(1 << n) - 1][i]);
  }
  cout << ans;
  // for (int i = 1; i <= n; ++i) {
  //   if (s[i] == '1') {
  //     vec.push_back(i);
  //   }
  // }
  // int sz = vec.size();
  // ll ans = 0;
  // vector<int> tmp;
  // for (int i = 0; i < (1 << sz); ++i) {
  //   if (__builtin_popcount(i) < m) continue;
  //   tmp.clear();
  //   for (int j = 0, cnt = 0; j < sz; ++j) {
  //     if (i >> j & 1) {
  //       tmp.push_back(vec[j] - cnt - 1);
  //       ++cnt;
  //     }
  //   }
  //   reverse(tmp.begin(), tmp.end());
  //   int cnt = 0;
  //   ll prod = 1;
  //   for (int x : tmp) {
  //     int ccnt = 0;
  //     for (int j = 1; j <= n; ++j) {
  //       if (c[j] > x) ++ccnt;
  //     }
  //     ccnt -= cnt;
  //     ++cnt;
  //     if (ccnt > 0) {
  //       prod = prod * ccnt % P;
  //     } else {
  //       prod = 0;
  //       break;
  //     }
  //   }
  //   prod = prod * fac[n - __builtin_popcount(i)] % P;
  //   if ((__builtin_popcount(i) - m) & 1) {
  //     ans -= prod;
  //   } else {
  //     ans += prod;
  //   }
  //   // cout << prod << ' ';
  //   // cout << '\n';
  // }
  // cout << (ans % P + P) % P;
  return 0;
}