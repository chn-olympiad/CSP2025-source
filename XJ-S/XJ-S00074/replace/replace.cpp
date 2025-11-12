#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using ll = long long;
constexpr int N = 2e5 + 3;
struct Rep {
  std::string s1, s2;
} re[N];
int ln[N], pre[N], sub[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
#ifdef _tqx
  std::cin.rdbuf((new std::ifstream{".in"})->rdbuf());
  std::cout.rdbuf((new std::ofstream{".out"})->rdbuf());
#else
  std::cin.rdbuf((new std::ifstream{"replace.in"})->rdbuf());
  std::cout.rdbuf((new std::ofstream{"replace.out"})->rdbuf());
#endif
  int n, q; std::cin >> n >> q;
  bool fla = true;
  for (int i = 1; i <= n; ++i) {
    std::cin >> re[i].s1 >> re[i].s2;
    if (!fla) continue;
    int cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < re[i].s1.size(); ++j) {
      if (re[i].s1[j] != 'a' && re[i].s1[j] != 'b' || re[i].s2[j] != 'a' && re[i].s2[j] != 'b') {
        fla = false;
        break;
      }
      if (re[i].s1[j] == 'b') ++cnt1;
      if (re[i].s2[j] == 'b') ++cnt2;
      if (cnt1 > 1 || cnt2 > 1) {
        fla = false;
        break;
      }
    }
  }
  std::sort(re + 1, re + n + 1, [](const Rep& a, const Rep& b) {
    return a.s1.size() < b.s1.size();
  });
  if (fla) {
    for (int i = 1; i <= n; ++i) {
      int p1 = re[i].s1.find_first_of('b');
      int p2 = re[i].s2.find_first_of('b');
      ln[i] = p2 - p1;
      pre[i] = std::min(p1, p2), sub[i] = re[i].s1.size() - std::max(p1, p2);
    }
  }
  while (q--) {
    std::string t1, t2; std::cin >> t1 >> t2;
    if (t1.size() != t2.size()) {
      std::cout << 0 << '\n';
      continue;
    }
    if (fla) {
      int p1 = -1, p2 = -1;
      for (int i = 0; i < t1.size(); ++i) {
        if (t1[i] == 'b') p1 = i;
        if (t2[i] == 'b') p2 = i;
      }
      int ans = 0;
      for (int i = 1; i <= n; ++i) {
        if (p2 - p1 == ln[i] && pre[i] <= std::min(p1, p2) && sub[i] <= t1.size() - std::max(p1, p2))
          ++ans;
      }
      std::cout << ans << '\n';
    } else {
      int l = t1.size(), r = 0;
      for (int i = 0; i < t1.size(); ++i) {
        if (t1[i] != t2[i]) {
          l = std::min(l, i);
          r = i;
        }
      }
      std::string p1 = "", p2 = "";
      for (int i = l; i <= r; ++i) p1 += t1[i], p2 += t2[i];
      int j = std::upper_bound(re + 1, re + n + 1, Rep{p1, p2}, [](const Rep& a, const Rep& b) {
        return a.s1.size() <= b.s1.size();
      }) - re;
      int ans = 0;
      for (int i = j; i <= n; ++i) {
        if (re[i].s1.size() > t1.size()) break;
        int x = re[i].s1.find(p1);
        if (!~x) continue;
        if (l - x < 0 || l - x + re[i].s1.size() > t1.size()) continue;
        if (t1.substr(l - x, re[i].s1.size()) == re[i].s1) {
          if (t2.substr(l - x, re[i].s1.size()) == re[i].s2)
            ++ans;
        }
      }
      std::cout << ans << '\n';
    }
  }
  return 0;
}