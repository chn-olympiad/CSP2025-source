#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define il inline
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define ssz(x) ((signed)((x).size()))
#define beg2ed(x) x.begin(), x.end()
#define For(i, j, k) for (int i = (j); i <= (k); i++)
#define ForDown(i, j, k) for (int i = (j); i >= (k); i--)

template <typename T> il void cmin(T &x, const T &y) { x = min(x, y); }
template <typename T> il void cmax(T &x, const T &y) { x = max(x, y); }

namespace {
constexpr int MAXN = 1e4 + 15, MAXM = 1e6 + 5;
int n, m, K, a[11][MAXN], f[MAXN], nxt[MAXN * 11][2][1 << 5];
tuple<int, int, int> E[MAXM], E2[MAXN * 11];
int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}
void Main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> K;
  For(i, 1, m) {
    auto &[u, v, w] = E[i];
    cin >> u >> v >> w;
  }
  For(i, 0, K - 1) For(j, 0, n) cin >> a[i][j];
  iota(f + 1, f + 1 + n, 1);
  sort(E + 1, E + 1 + m, [&](const auto &x, const auto &y) { return get<2>(x) < get<2>(y); });
  int cnt = 0;
  ll Ans = 0;
  For(i, 1, m) {
    auto [u, v, w] = E[i];
    if (find(u) == find(v))
      continue;
    E2[++cnt] = {u, v, w}, f[find(u)] = find(v), Ans += w;
  }
  For(i, 0, K - 1) For(j, 1, n) E2[++cnt] = {j, n + i + 1, a[i][j]};
  sort(E2 + 1, E2 + 1 + cnt, [&](const auto &x, const auto &y) { return get<2>(x) < get<2>(y); });
  memset(nxt[cnt + 1], 0x3f, sizeof nxt[cnt + 1]);
  ForDown(i, cnt, 1) {
    memcpy(nxt[i], nxt[i + 1], sizeof nxt[i + 1]);
    int p = get<1>(E2[i]);
    if (p <= n)
      For(j, 0, 1) For(k, 0, (1 << 5) - 1) nxt[i][j][k] = i;
    else if (p - n - 1 < 5) {
      For(k, 0, (1 << 5) - 1) if (k >> (p - n - 1) & 1)
        nxt[i][0][k] = i;
    }
    else {
      For(k, 0, (1 << 5) - 1) if (k >> (p - n - 6) & 1)
        nxt[i][1][k] = i;
    }
  }
  For(S, 1, (1 << K) - 1) {
    iota(f + 1, f + 1 + n + K, 1);
    ll sum = 0;
    For(i, 0, K - 1) if (S >> i & 1) sum += a[i][0];
    for (int j = 1; j <= cnt; j = min(nxt[j + 1][0][S & 31], nxt[j + 1][1][S >> 5])) {
      auto [u, v, w] = E2[j];
      if (find(u) == find(v))
        continue;
      f[find(u)] = find(v), sum += w;
      if (sum > Ans)
        break;
    }
    cmin(Ans, sum);
  }
  cout << Ans << '\n';
}
}

int main() { return Main(), 0; }