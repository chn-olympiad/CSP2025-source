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
constexpr int MAXN = 2e5 + 5, MAXL = 5e6 + 5;
constexpr ll bs1 = 37, mod1 = 998244353, bs2 = 31, mod2 = 1e9 + 7;
int n, Q, Ans[MAXN], ch[MAXL][26], msk[MAXL], sz[MAXL], dfnR[MAXN * 2], szR[MAXN * 2], cnt = 0, tot = 0;
basic_string<int> vis[MAXL];
map<pll, vector<tuple<int, string, string>>> All;
int bit[MAXN * 2];
void append(pll &x, int v) {
  x.fi = (x.fi * bs1 + v) % mod1;
  x.se = (x.se * bs2 + v) % mod2;
}
void ins(int id, const string &x) {
  int p = 1;
  for (char c : x) {
    if (!ch[p][c - 'a']) {
      if (id <= n)
        ch[p][c - 'a'] = ++cnt, msk[p] |= 1 << (c - 'a');
      else
        break;
    }
    p = ch[p][c - 'a'];
  }
  // cerr << "! " << p << ' ' << id << '\n';
  vis[p].push_back(id);
}
void dfs1(int p) {
  if (!vis[p].empty()) {
    int dfn = ++tot;
    sz[p] = 1;
    for (int id : vis[p])
      dfnR[id] = dfn;
  }
  for (int S = msk[p], i; S; S ^= 1 << i) {
    i = __builtin_ctz(S);
    dfs1(ch[p][i]), sz[p] += sz[ch[p][i]];
  }
  for (int id : vis[p])
    szR[id] = sz[p];
}

void bit_add(int p, int v) {
  for (; p <= tot; p += p & -p)
    bit[p] += v;
}
int bit_qry(int p) {
  int ans = 0;
  for (; p; p -= p & -p)
    ans += bit[p];
  return ans;
}

void dfs2(int p) {
  // cerr << p << '\n';
  for (int id : vis[p]) {
    if (id <= n)
      /* cerr << p << ' ' << id << ' ' << dfnR[id] << ' ' << szR[id] << '\n', */ bit_add(dfnR[id], 1), bit_add(dfnR[id] + szR[id], -1);
    else
      /* cerr << p << ' ' << id << ' ' << dfnR[id] << '\n', */ Ans[id - n] = bit_qry(dfnR[id]);
  }
  for (int S = msk[p], i; S; S ^= 1 << i) {
    i = __builtin_ctz(S);
    dfs2(ch[p][i]);
  }
  for (int id : vis[p])
    if (id <= n)
      bit_add(dfnR[id], -1), bit_add(dfnR[id] + szR[id], 1);
}

void Main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> Q;
  For(i, 1, n) {
    static string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
      continue;
    pll v1{}, v2{};
    int p = 0, q = ssz(s1) - 1;
    while (s1[p] == s2[p])
      p++;
    while (s1[q] == s2[q])
      q--;
    assert(p <= q);
    For(j, p, q)
      append(v1, s1[j] - 'a' + 1), append(v2, s2[j] - 'a' + 1);
    All[{v1.fi << 32 | v1.se, v2.fi << 32 | v2.se}].eb(i, s1.substr(0, p), (q == ssz(s1) - 1) ? ""s : s1.substr(q + 1));
  }
  For(i, 1, Q) {
    static string t1, t2;
    cin >> t1 >> t2;
    if (ssz(t1) != ssz(t2))
      continue;
    int p = 0, q = ssz(t1) - 1;
    while (t1[p] == t2[p])
      p++;
    while (t1[q] == t2[q])
      q--;
    pll v1{}, v2{};
    assert(p <= q);
    For(j, p, q)
      append(v1, t1[j] - 'a' + 1), append(v2, t2[j] - 'a' + 1);
    pll key{v1.fi << 32 | v1.se, v2.fi << 32 | v2.se};
    auto it = All.find(key);
    if (it == All.end())
      continue;
    All[key].eb(i + n, t1.substr(0, p), t1.substr(q + 1));
  }
  for (auto &[_, vec] : All) {
    // cerr << "-----\n";
    memset(bit, 0, (tot + 1) * sizeof(int));

    memset(ch, 0, (cnt + 1) * 26 * sizeof(int));
    memset(sz, 0, (cnt + 1) * sizeof(int));
    memset(msk, 0, (cnt + 1) * sizeof(int));
    For(i, 0, cnt) vis[i].clear();
    cnt = 1, tot = 0;
    for (const auto &[id, L, R] : vec)
      ins(id, R);
    dfs1(1);

    memset(ch, 0, (cnt + 1) * 26 * sizeof(int));
    memset(sz, 0, (cnt + 1) * sizeof(int));
    memset(msk, 0, (cnt + 1) * sizeof(int));
    For(i, 0, cnt) vis[i].clear();
    cnt = 1;
    for (auto &[id, L, R] : vec)
      reverse(beg2ed(L)), ins(id, L);
    dfs2(1);
  }

  For(i, 1, Q) cout << Ans[i] << '\n';
}
}

int main() { return Main(), 0; }