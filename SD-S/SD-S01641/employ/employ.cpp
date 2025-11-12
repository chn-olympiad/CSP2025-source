#include <bits/stdc++.h>
using namespace std;

static constexpr uint64_t mod = 998244353;

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.badbit | cin.failbit);
  size_t n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vector<size_t> cc(n);
  for (size_t i = 0; i < n; ++i)
    cin >> cc[i];

  vector<size_t> p(n);
  iota(p.begin(), p.end(), 0);
  
  uint64_t count = 0;
  do {
    size_t cnt = 0, ac = 0;
    for (size_t j = 0; j < n; ++j) {
      size_t i = p[j];
      if (s[j] == '0')
        ++cnt;
      else {
        if (cnt >= cc[i])
          ++cnt;
        else
          ++ac;
      }
    }
    if (ac >= m) {
      ++count;
    }
  } while(next_permutation(p.begin(), p.end()));
  
  cout << count << '\n';
  return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

3 2
101
1 1 2

*/
