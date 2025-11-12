#include <iostream>
#include <string>
using namespace std;

namespace My {
constexpr int N = 2e5 + 5;
int n, q;
string s1[N], s2[N], t1[N], t2[N];

int find(const string& s) {
  int ret = -1;
  for (auto g = s.begin(); g != s.end(); ++g) {
    ++ret;
    if (*g == 'b') break;
  }
  return ret;
}

void solveB() {
  static int l1[N], r1[N], l2[N], r2[N];
  for (int i = 1; i <= n; ++i) {
    l1[i] = find(s1[i]);
    r1[i] = s1[i].length() - l1[i] - 1;
    l2[i] = find(s2[i]);
    r2[i] = s2[i].length() - l2[i] - 1;
  }
  for (int i = 1; i <= q; ++i) {
    int ans = 0;
    int left1 = find(t1[i]), left2 = find(t2[i]);
    int right1 = t1[i].length() - left1 - 1, right2 = t2[i].length() - left2 - 1;
    for (int j = 1; j <= n; ++j) {
      if (l1[j] - l2[j] == left1 - left2 && l1[j] >= left1 && r1[j] >= right1 && l2[j] >= left2 && r2[j] >= right2) ++ans;
    }
    cout << ans << '\n';
  }
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> s1[i] >> s2[i];
  for (int i = 1; i <= q; ++i) cin >> t1[i] >> t2[i];
  solveB();
}

}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  My::solve();
  return 0;
}

