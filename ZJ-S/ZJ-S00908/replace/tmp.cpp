#include <bits/stdc++.h>
#define endl '\n'
#define fir first
#define sec second
// using std::endl;
using i32 = int;
using i64 = long long;
using p32 = std::pair<i32, i32>;
using p64 = std::pair<i64, i64>;
const i64 inf64 = 2e18;
void solve(i32 _);
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  i32 T = 1;
  // std::cin >> T;
  for (i32 i = 1; i <= T; i++) solve(i);
}
std::mt19937 rnd(std::random_device{}());
bool isprime(i64 x) {
  for (i64 i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
i64 getrndp() {
  i64 p = rnd() % 50000000 + 50000000;
  while (!isprime(p)) p += (p & 1 ? 2 : 1);
  return p;
}
const i64 p = getrndp(), base = getrndp();
inline i64 mod(i64 x) {
  return (x % p + p) % p;
}
i64 B[5000005], cnt = 0;
i64 sa[5000005], sb[5000005];
void solve(i32 _) {
  i32 n, q;
  std::cin >> n >> q;
  B[0] = 1;
  std::vector<p64> s(n + 2, {0, 0});
  std::vector<i32> siz(n + 2, 0);
  for (i32 i = 1; i <= n; i++) {
    std::string a, b;
    siz[i] = a.size();
    for (i32 c : a) s[i].fir = mod(s[i].fir * base + c);
    for (i32 c : b) s[i].sec = mod(s[i].sec * base + c);
  }
  for (i32 i = 1; i <= q; i++) {
    i64 ans = 0;
    std::string a, b;
    std::cin >> a >> b;
    while (cnt < std::max(a.size(), b.size())) B[cnt + 1] = mod(B[cnt] * base), cnt++;
    sa[0] = sb[0] = 0;
    for (i32 i = 1; i <= a.size(); i++) {
      sa[i] = mod(sa[i - 1] * base + a[i - 1]);
    }
    for (i32 i = 1; i <= a.size(); i++) {
      sb[i] = mod(sb[i - 1] * base + b[i - 1]);
    }
    auto getHash = [&](i32 l, i32 r) -> i64 {
      if (r < l) return 0;
      return mod(sa[r] - mod(sa[l - 1] * B[r - l + 1]));
    };
    for (i32 i = 1; i <= n; i++)
    for (i32 j = 1; j <= (i32)a.size() - siz[i] + 1; j++) {
      if (getHash(j, j + siz[i] - 1) == s[i].fir) 
        if (mod(mod(getHash(1, j - 1) * B[(i32)a.size() - j]) + mod(s[i].sec * B[(i32)a.size() - siz[i] - j]) + mod(getHash(j + siz[i] + 1, (i32)a.size()))) == sb[(i32)a.size()])
          ans++;
    }
    std::cout << ans << endl;
  }
}
// g++ replace.cpp -o replace -O2 -static -std=c++14
