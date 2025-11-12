#include <bits/stdc++.h>

bool mem;

using u32 = unsigned; using u64 = unsigned long long;

constexpr u32 N{10011}, M{1100000}, K{11};

struct edge { u32 u, v; u64 w; inline edge(void) = default; inline edge(u32 &u, u32 v) : u{u}, v{v} { } };
inline bool operator < (const edge &a, const edge &b) { return a.w < b.w; }
u32 n, m, k, t, b[N], p[N], sz[N]; u64 c[K], ans; std::vector<edge> e[K], E[1024];

inline void init(void) { for (u32 i{1}; i <= n + k; i++) { p[i] = i; sz[i] = 1; } }
const u32 &find(const u32 &x) { if (p[x] != p[p[x]]) { p[x] = find(p[x]); } return p[x]; }
inline bool merge(const u32 &x, const u32 &y)
{ u32 a{find(x)}, b{find(y)}; if (a == b) { return false; } if (sz[a] > sz[b]) { std::swap(a, b); } p[a] = b; sz[b] += sz[a]; return true; }

bool ory;

signed main(void)
{
  std::cin.tie(nullptr) -> sync_with_stdio(false);
  std::cin >> n >> m >> k; e[0].resize(m); for (u32 i{0}; i < m; i++) { std::cin >> e[0][i].u >> e[0][i].v >> e[0][i].w; }
  for (u32 j{1}; j <= k; j++) { std::cin >> c[j]; for (u32 i{1}; i <= n; i++) { e[j].emplace_back(i, j + n); std::cin >> e[j].back().w; } std::sort(e[j].begin(), e[j].end()); }
  std::sort(e[0].begin(), e[0].end()); init(); for (const edge &e : ::e[0]) { if (merge(e.u, e.v)) { E[0].emplace_back(e); ans += e.w; } }
  for (u32 s{1}; s < (1u << k); s++)
  {
    u32 x{0}; u64 S{0}; for (u32 i{1}; i <= k; i++) { if (s & (1 << (i - 1))) { if (!x) { x = i - 1; } S += c[i]; } }
    std::vector<edge> ed, &E{::E[s ^ (1 << x)]}, &e{::e[x + 1]}; auto p0{E.begin()}, p1{e.begin()};
    while (p0 != E.end() && p1 != e.end()) { ed.emplace_back((p0 -> w < p1 -> w) ? *p0++ : *p1++); }
    while (p0 != E.end()) { ed.emplace_back(*p0++); } while (p1 != e.end()) { ed.emplace_back(*p1++); }
    init(); for (const edge &e : ed) { if (merge(e.u, e.v)) { ::E[s].emplace_back(e); S += e.w; } } if (S < ans) { ans = S; }
  }
  std::cout << ans; return 0;
}
