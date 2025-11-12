#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> pre_xor(n + 1);
  vector<int> pre_cnt(n + 1);
  map<int, int> last_xor_pos;
  last_xor_pos[0] = 0;
  for (int i = 0; i < n; i++) {
    pre_xor[i + 1] = pre_xor[i] ^ a[i];
    pre_cnt[i + 1] = pre_cnt[i];
    if (last_xor_pos.count(pre_xor[i + 1] ^ k)) {
      pre_cnt[i + 1] =
          max(pre_cnt[i + 1], pre_cnt[last_xor_pos[pre_xor[i + 1] ^ k]] + 1);
    }
    last_xor_pos[pre_xor[i + 1]] = i + 1;
  }
  cout << pre_cnt[n] << "\n";
  return 0;
}
