#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> w(n + 1, 0), partialxor(n + 1, 0);
  for (int i = 1; i <= n; i ++) cin >> w[i];
  for (int i = 1; i <= n; i ++) {
    partialxor[i] = partialxor[i - 1] ^ w[i];
  }
  int pos = 1, ans = 0;
  for (int i = 1; i <= n; i ++) {
    for (int j = pos; j <= i; j ++) {
      if ((partialxor[i] ^ partialxor[j - 1]) == k) {
        pos = i + 1;
        ans ++;
        break;
      }
    }
  }
  cout << ans << endl;
}