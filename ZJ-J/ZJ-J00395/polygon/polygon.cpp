#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int main() {
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  int n;
  long long ans = 0;
  cin >> n;
  vector<long long> w(n);
  for (long long &x : w) cin >> x;
  sort(w.begin(), w.end());
  vector<long long> sum(accumulate(w.begin(), w.end(), 5ll), 0);
  long long sumw = 0;
  for (int i = 0; i < n; i ++) {
    long long x = w[i];
    if (i > 1) ans += accumulate(sum.begin() + x + 1, sum.begin() + sumw + 1, 0ll);
    ans %= mod;
    sumw += x;
    for (int i = sumw; i >= x; i --) {
      sum[i] += sum[i - x];
      sum[i] %= mod;
    }
    sum[x] ++;
    sum[x] %= mod;
  }
  cout << ans << endl;
}