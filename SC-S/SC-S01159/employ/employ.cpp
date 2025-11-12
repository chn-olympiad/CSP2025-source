#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500;
const int P = 998244353;
int n, m, a[N + 1];
char s[N + 1];

void add(int &x, int y) {
  x += y - P;
  x += x >> 31 & P;
  return;
}

namespace sub1 {

void sol() {
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0' || !a[i]) {
      cout << "0";
      return;
    }
  }
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = (ll)res * i % P;
  }
  cout << res;
  return;
}

}

namespace sub2 {

const int N = 18;
const int S = (1 << N) - 1;
int f[S + 1][N + 1], ans;

void sol() {
  int s = (1 << n) - 1;
  f[0][0] = 1;
  for (int i = 0; i < s; i++) {
    int cnt = __builtin_popcount(i);
    for (int j = 0; j <= cnt; j++) {
      int tf = f[i][j];
      if (!tf) {
        continue;
      }
      for (int k = 1; k <= n; k++) {
        if (i >> k - 1 & 1) {
          continue;
        }
        if (::s[cnt + 1] == '1' && cnt - j < a[k]) {
          add(f[i | 1 << k - 1][j + 1], tf);
        }
        else {
          add(f[i | 1 << k - 1][j], tf);
        }
      }
    }
  }
  for (int i = m; i <= n; i++) {
    add(ans, f[s][i]);
  }
  cout << ans;
  return;
}

}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (m == n) {
    sub1::sol();
  }
  else if (n <= 18) {
    sub2::sol();
  }
  return 0;
}