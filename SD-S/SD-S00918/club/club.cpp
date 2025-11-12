#include <bits/stdc++.h>

using ll = long long;
using vl = std::vector<ll>;

void Advotya() {
  int n; std::cin >> n;
  vl a(n);
  vl b(n);
  vl c(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i] >> c[i];
  vl cnt(3); 
  ll tar = 0; 
  vl choose(n);
  for (int i = 0; i < n; ++i) {
    int mx = std::max(a[i], std::max(b[i], c[i]));
    tar += mx;
    if (a[i] == mx) choose[i] = 0;
    else if (b[i] == mx) choose[i] = 1;
    else if (c[i] == mx) choose[i] = 2; 
    ++cnt[choose[i]]; 
  }
  for (int i = 0; i < 3; ++i) {
    if (cnt[i] <= n / 2) continue;
    std::multiset<int> o;
    for (int j = 0; j < n; ++j) {
      if (choose[j] != i) continue;
      int mx = std::max(a[j], std::max(b[j], c[j]));
      int mn = std::min(a[j], std::min(b[j], c[j]));
      int md = a[j] + b[j] + c[j] - mx - mn; 
      o.insert(mx - md);
    }
    while (cnt[i] > n / 2) {
      --cnt[i];
      tar -= *o.begin();
      o.erase(o.begin());
    }
  } 
  std::cout << tar << "\n";
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) Advotya();
  return 0;
}
 
