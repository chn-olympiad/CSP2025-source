#include <bits/stdc++.h>

using ll = long long;

void brute(int n, int q, std::vector<std::string> s, std::vector<std::string> t) {
  for (int i = 0; i < q; ++i) {
    int tar = 0;
    int l = 0;
    int r = 0; 
    for (int j = 0; j < t[i].size(); j += 2) {
      if (t[i][j] != t[i][j + 1]) {
        l = j;
        break;
      }
    }
    for (int j = t[i].size() - 1; j >= 1; j -= 2) {
      if (t[i][j] != t[i][j - 1]) {
        r = j;
        break;
      }
    }
    for (int j = 0; j <= l; ++j) {
      for (int u = 0; u < n; ++u) {
        if (j + s[u].size() - 1 >= t[i].size()) continue;
        if (r > j + s[u].size() - 1) continue;
        bool flag = true;
        for (int v = 0; v < s[u].size(); ++v) {
          if (t[i][j + v] != s[u][v]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          ++tar;
        }
      }
    }
    std::cout << tar << "\n";
  }
}

void Advotya() {
  int n; std::cin >> n;
  int q; std::cin >> q;
  std::vector<std::string> s(n);
  std::vector<std::string> t(q);
  int l1 = 0;
  int l2 = 0;
  for (int i = 0; i < n; ++i) {
    std::string s1; std::cin >> s1;
    std::string s2; std::cin >> s2;
    for (int j = 0; j < s1.size(); ++j) {
      s[i].push_back(s1[j]);
      s[i].push_back(s2[j]);
    }
    l1 += s[i].size();
  }
  for (int i = 0; i < q; ++i) {
    std::string s1; std::cin >> s1;
    std::string s2; std::cin >> s2;
    for (int j = 0; j < s1.size(); ++j) {
      t[i].push_back(s1[j]);
      t[i].push_back(s2[j]);
    }
    l2 += t[i].size();
  }
  brute(n, q, s, t);
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  Advotya();
  return 0;
}

