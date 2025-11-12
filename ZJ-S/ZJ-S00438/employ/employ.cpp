#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long Cr(int b) {
  long long t = 1;
  for (int i = 2; i <= b; i ++) {
    t *= i;
    t %= mod;
  }
  return t;
}
int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  string diff;
  cin >> diff;
  vector<int> s(n);
  for (int &x : s) cin >> x;
  bool a = 1;
  for (int &x : s) {
    if (x != 1) {
      a = false;
      break;
    }
  }
  if (a) {
    int lth = 0;
    for (int i = 0; i < n; i ++) {
      if (diff[i] == '1') {
        lth ++;
      } else {
        break;
      }
    }
    if (lth >= m) {
      cout << Cr(lth) << endl;
    } else {
      cout << 0 << endl;
    }
  }
}