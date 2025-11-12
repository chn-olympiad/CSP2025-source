#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb emplace_back

using namespace std;
using ll = long long;

const int N = 2e5 + 10, L = 5e6 + 10, P1 = 998244353, P2 = 1e9 + 7;
const ll bs1 = 29, bs2 = 131;

char s1[L], s2[L];
int n, m, tot, id_tot, ch[L][26], ans[N];

map<ll, int> rt, id; bool vi[L];
vector<int> qv[N << 1]; vector<pii> vec[N << 1];

struct bit {
  int c[N << 1], lim; 
  void cl(int n) { lim = n; for (int i = 1; i <= n; i ++) c[i] = 0; }
  void ad(int x, int v) { while (x <= lim) c[x] += v, x += x & -x; }
  int qu(int x, int r = 0) { while (x) r += c[x], x -= x & -x; return r; }
  void md(int l, int r, int v) { ad(l, v), ad(r + 1, -v); }
} tr;

int ins(ll r, char *s, int len) {
  if (rt.find(r) == rt.end()) 
    rt[r] = ++ tot, vi[tot] = 1;

  int p = rt[r];
  for (int i = 1; i <= len; i ++) {
    int &to = ch[p][s[i] - 'a'];
    if (!to) to = ++ tot; p = to;
  }

  vi[p] = 1;
  return p;
}

int dfn_tot, dfn[L], R[L]; pii stk[L], q[N];
void dfs(int st) {
  int tp = 0;
  stk[tp = 1] = {st, 0};
  dfn[st] = dfn_tot = 1;

  while (tp) {
    int u = stk[tp].fi, &c = stk[tp].se;
    if (c == 26) {
      R[u] = dfn_tot, tp --; 
      continue;
    }

    if (ch[u][c]) {
      int v = ch[u][c];
      stk[++ tp] = {v, 0};
      if (vi[v]) dfn[v] = ++ dfn_tot;
    }

    c ++;
  }
}

struct Node { int l, r, v; };
vector<Node> mv[N << 1];

void ins_p(int l, int r, int l0, int r0) {
  mv[l].pb(Node {l0, r0, 1});
  if (r < dfn_tot) mv[r + 1].pb(Node {l0, r0, -1});
}

void calc(int x, int st) {
  dfs(st); 
  for (pii t : vec[x]) 
    ins_p(dfn[t.fi], R[t.fi], dfn[t.se], R[t.se]);
    
  sort(qv[x].begin(), qv[x].end(), [&](int x, int y) {
    return dfn[q[x].fi] < dfn[q[y].fi];
  });
  
  tr.cl(dfn_tot);
  for (int i = 1, p = 0; i <= dfn_tot; i ++) {
    for (Node t : mv[i]) tr.md(t.l, t.r, t.v);
    while (p < qv[x].size() && dfn[q[qv[x][p]].fi] == i)
      ans[qv[x][p]] = tr.qu(dfn[q[qv[x][p]].se]), p ++;
    mv[i].clear();
  }
}

signed main() {

  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);

  scanf("%d%d", &n, &m);
  for (int T = 1; T <= n + m; T ++) {
    scanf("%s%s", s1 + 1, s2 + 1);

    int len = strlen(s1 + 1);
    if (T > n && len != strlen(s2 + 1))
      continue;

    int l = 1, r = len;
    while (l <= len && s1[l] == s2[l]) l ++;
    while (r >= 1 && s1[r] == s2[r]) r --;

    if (T <= n && l > r) continue;

    ll r1 = 0, r2 = 0, res = 0;
    for (int i = l; i <= r; i ++) 
      (r1 = r1 * bs1 + s1[i] - 'a' + 1) %= P1,
      (r2 = r2 * bs2 + s1[i] - 'a' + 1) %= P2;
    for (int i = l; i <= r; i ++)
      (r1 = r1 * bs1 + s2[i] - 'a' + 1) %= P1,
      (r2 = r2 * bs2 + s2[i] - 'a' + 1) %= P2;

    res = r1 * 1000000000ll + r2;
    if (id.find(res) == id.end())
      id[res] = ++ id_tot;
    
    reverse(s1 + 1, s1 + l);
    if (T <= n) {
      vec[id[res]].pb(ins(res, s1, l - 1), ins(res, s1 + r, len - r));
    } else {
      qv[id[res]].pb(T - n);
      q[T - n] = {ins(res, s1, l - 1), ins(res, s1 + r, len - r)};
    }
  }

  for (pair<ll, int> val : rt) calc(id[val.fi], val.se);
  for (int i = 1; i <= m; i ++)
    printf("%d\n", ans[i]);
}