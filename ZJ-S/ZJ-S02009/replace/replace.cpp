#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;

constexpr int P = 1E9 + 7, B = 131;

struct Info {
  std::string s, t;
  int id;
};

constexpr int N = 4E5 + 5;

int a[N];

void add(int x, int v) {
  for (int i = x + 1; i < N; i += i & -i) {
    a[i - 1] += v;
  }
}

int sum(int x) {
  int ans = 0;
  for (int i = x; i; i -= i & -i) {
    ans += a[i - 1];
  }
  return ans;
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;

  std::map<std::array<int, 2>, std::vector<Info>> f, g;
  for (int i = 0; i < n; i++) {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1 == s2) {
      continue;
    }
    int m = s1.size();
    int l, r;
    for (int j = 0; j < m; j++) {
      if (s1[j] != s2[j]) {
        l = j;
        break;
      }
    }
    for (int j = m - 1; j >= 0; j--) {
      if (s1[j] != s2[j]) {
        r = j;
        break;
      }
    }
    int h0 = 0, h1 = 0;
    for (int j = l; j <= r; j++) {
      h0 = (1LL * h0 * B + s1[j] - 'a') % P;
      h1 = (1LL * h1 * B + s2[j] - 'a') % P;
    }
    f[{h0, h1}].push_back({s1.substr(0, l), s2.substr(r + 1), i});
  }

  std::vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    std::string t1, t2;
    std::cin >> t1 >> t2;

    if (t1.size() == t2.size()) {
      int m = t1.size();
      int l, r;
      for (int j = 0; j < m; j++) {
        if (t1[j] != t2[j]) {
          l = j;
          break;
        }
      }
      for (int j = m - 1; j >= 0; j--) {
        if (t1[j] != t2[j]) {
          r = j;
          break;
        }
      }
      int h0 = 0, h1 = 0;
      for (int j = l; j <= r; j++) {
        h0 = (i64(h0) * B + t1[j] - 'a') % P;
        h1 = (i64(h1) * B + t2[j] - 'a') % P;
      }
      g[{h0, h1}].push_back({t1.substr(0, l), t2.substr(r + 1), i});
    }
  }

  auto work = [&](std::string s) {
    int n = s.size();
    std::vector<int> hsh(n + 1);
    for (int i = 0; i < n; i++) {
      hsh[i + 1] = (i64(hsh[i]) * B + s[i] - 'a') % P;
    }
    hsh.erase(hsh.begin());
    return hsh;
  };

  for (auto [k, p] : f) {
    auto q = g[k];
    int n = p.size(), m = q.size();

    std::vector<int> l(m), r(m);
    std::vector<int> l1(n), r1(n), l2(n), r2(n);
    std::vector<std::string> s((n + m) * 2);
    std::vector<std::vector<int>> hsh((n + m) * 2);

    for (int i = 0; i < n; i++) {
      std::reverse(p[i].s.begin(), p[i].s.end());
      s[i] = p[i].s;
      s[i + n + m] = p[i].t;
    }
    for (int i = 0; i < m; i++) {
      std::reverse(q[i].s.begin(), q[i].s.end());
      s[i + n] = q[i].s;
      s[i + n + n + m] = q[i].t;
    }
    for (int i = 0; i < (n + m) * 2; i++) {
      hsh[i] = work(s[i]);
    }
    auto lcp = [&](int x, int y) {
      int n = hsh[x].size(), m = hsh[y].size();
      int lo = 0, hi = std::min(n, m);
      while (lo < hi) {
        int t = (lo + hi) / 2;
        if (hsh[x][t] == hsh[y][t]) {
          lo = t + 1;
        } else {
          hi = t;
        }
      }
      return hi;
    };
    {
      std::vector<int> ord(n + m);
      std::iota(ord.begin(), ord.end(), 0);
      std::sort(ord.begin(), ord.end(),
        [&](int x, int y) {
          int k = lcp(x, y);
          if (k == std::min(s[x].size(), s[y].size())) {
            return s[x].size() == s[y].size() ? x < y : s[x].size() < s[y].size();
          } else {
            return s[x][k] < s[y][k];
          }
        });
      for (int i = 0; i < n + m; i++) {
        int j = ord[i];
        if (j < n) {
          l1[j] = i;
          int lo = i, hi = n + m - 1;
          while (lo < hi) {
            int m = (lo + hi + 1) / 2;
            if (lcp(j, ord[m]) == s[j].size()) {
              lo = m;
            } else {
              hi = m - 1;
            }
          }
          r1[j] = hi;
        } else {
          l[j - n] = i;
        }
      }
    }
    {
      std::vector<int> ord(n + m);
      std::iota(ord.begin(), ord.end(), n + m);
      std::sort(ord.begin(), ord.end(),
        [&](int x, int y) {
          int k = lcp(x, y);
          if (k == std::min(s[x].size(), s[y].size())) {
            return s[x].size() == s[y].size() ? x < y : s[x].size() < s[y].size();
          } else {
            return s[x][k] < s[y][k];
          }
        });
      for (int i = 0; i < n + m; i++) {
        int j = ord[i];
        if (j < n + n + m) {
          l2[j - n - m] = i;
          int lo = i, hi = n + m - 1;
          while (lo < hi) {
            int m = (lo + hi + 1) / 2;
            if (lcp(j, ord[m]) == s[j].size()) {
              lo = m;
            } else {
              hi = m - 1;
            }
          }
          r2[j - n - m] = hi;
        } else {
          r[j - n - m - n] = i;
        }
      }
    }
    std::vector<std::vector<std::array<int, 3>>> mdf(n + m + 1);
    for (int i = 0; i < n; i++) {
      mdf[l1[i]].push_back({l2[i], r2[i], 1});
      mdf[r1[i] + 1].push_back({l2[i], r2[i], -1});
    }
    std::vector<std::array<int, 2>> qry(n + m + 1, {-1, -1});
    for (int i = 0; i < m; i++) {
      qry[l[i]] = {r[i], q[i].id};
    }
    for (int i = 0; i <= n + m; i++) {
      for (auto [l, r, v] : mdf[i]) {
        add(l, v);
        add(r + 1, -v);
      }
      if (qry[i][0] != -1) {
        ans[qry[i][1]] = sum(qry[i][0] + 1);
      }
    }
  }

  for (int i = 0; i < q; i++) {
    std::cout << ans[i] << "\n";
  }

  return 0;
}