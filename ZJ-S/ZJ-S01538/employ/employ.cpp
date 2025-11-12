#include <bits/stdc++.h>

using u32 = unsigned;

constexpr u32 N{510};

namespace struct_mint
{
  using u128 = unsigned __int128; constexpr u32 p{998244353}; constexpr u128 e{1}, L{(e << 92) / p};
  inline u32 mod(u128 x) { return x - (x * L >> 92) * p; }
  struct mint { u32 x; inline mint(void) : x{0} { } inline mint(u32 x) : x{x} { } };
  inline void operator += (mint &a, mint b) { a.x += b.x; if (a.x >= p) { a.x -= p; } }
  inline void operator -= (mint &a, const mint &b) { if (a.x < b.x) { a.x += p; } a.x -= b.x; }
  inline mint operator * (const mint &a, const mint &b) { return mint{mod(e * a.x * b.x)}; }
  inline void operator *= (mint &a, mint b) { a.x = mod(e * a.x * b.x); }
} // namespace struct_mint

using struct_mint::mint;

u32 n, m, s[N]; std::vector<u32> p; mint fact[N], f[1 << 25], ans;

signed main(void)
{
  freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout); std::cin.tie(nullptr) -> sync_with_stdio(false);
  std::cin >> n >> m; for (u32 i{1}; i <= n; i++) { char x; std::cin >> x; if (x == '1') { p.emplace_back(i); } }
  assert(p.size() <= 25); fact[0] = 1; for (u32 i{1}; i <= n; i++) { fact[i] = fact[i - 1] * i; } std::reverse(p.begin(), p.end());
  for (u32 i{1}, x; i <= n; i++) { std::cin >> x; if (x) { s[x - 1]++;} } for (u32 i{n}; i; i--) { s[i - 1] += s[i]; }
  for (u32 s{(1u << p.size()) - 1}; s; s--) if (__builtin_popcount(s) >= m)
  {
    mint x{1};
    for (u32 i{0}, c{0}, t{__builtin_popcount(s)}; i < p.size(); i++)
    { if (s & (1 << i)) { if (::s[p[i] - t] <= c) { x = 0; break; } x *= ::s[p[i] - t] - c; c++; t--; } }
    f[s] = x * fact[n - __builtin_popcount(s)]; for (u32 u{((1u << p.size()) - 1) ^ s}, t{u}; t; t = (t - 1) & u) { f[s] -= f[s | t]; } ans += f[s];
  }
  std::cout << ans.x; return 0;
}
