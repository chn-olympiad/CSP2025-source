#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2.5e6 + 5;
struct ACAM {
  int t[N][26], tot;
  int insert(string& s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
      int& to = t[u][s[i] - 'a'];
      if (!to) to = ++tot;
      u = to;
    }
    return u;
  }
  int fail[N];
  struct Graph {
    int head[N], to[N], nxt[N], m;
    void addedge(int u, int v) {
      to[++m] = v, nxt[m] = head[u], head[u] = m;
    }
  } G;
  int dfn[N], siz[N], dfc;
  void dfs(int u) {
    dfn[u] = ++dfc, siz[u] = 1;
    for (int i = G.head[u]; i; i = G.nxt[i]) {
      int v = G.to[i];
      dfs(v);
      siz[u] += siz[v];
    }
  }
  void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
      if (t[0][i]) {
        q.push(t[0][i]);
      }
    }
    while (q.size()) {
      int u = q.front(); q.pop();
      for (int i = 0; i < 26; i++) {
        if (t[u][i]) {
          fail[t[u][i]] = t[fail[u]][i];
          q.push(t[u][i]);
        } else {
          t[u][i] = t[fail[u]][i];
        }
      }
    }
    for (int i = 1; i <= tot; i++) {
      G.addedge(fail[i], i);
    }
    dfs(0);
  }
} A1, A2;
int n, Q;

constexpr int M = 3.5e6 + 5;
ll ans[N];
struct Point { int op, x, y, t, coe; } p[M], tmp[M];
int tot;

struct BIT {
  int t[N];
  void add(int x, int w) { for (; x < N; x += x & -x) t[x] += w; }
  int query(int x) { int r = 0; for (; x; x -= x & -x) r += t[x]; return r; }
} bit;
void SOLVE(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  SOLVE(l, mid), SOLVE(mid + 1, r);

  int cnt = 0;
  for (int i = l; i <= mid; i++) {
    if (p[i].op == 0) tmp[++cnt] = p[i];
  }
  for (int i = mid + 1; i <= r; i++) {
    if (p[i].op == 1) tmp[++cnt] = p[i];
  }
  sort(tmp + 1, tmp + cnt + 1, [](Point A, Point B) {
    if (A.x != B.x) return A.x < B.x;
    return A.op < B.op;
  });
  for (int i = 1; i <= cnt; i++) {
    if (tmp[i].op == 0) {
      bit.add(tmp[i].y, tmp[i].coe);
    } else {
      ans[tmp[i].coe] += bit.query(tmp[i].y);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (tmp[i].op == 0) {
      bit.add(tmp[i].y, -tmp[i].coe);
    }
  }
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cin >> n >> Q;
  vector<tuple<int, int, int>> S;
  for (int i = 1; i <= n; i++) {
    string a, b; cin >> a >> b;
    int u = A1.insert(a), v = A2.insert(b);
    S.emplace_back(u, v, a.size());
  }
  A1.build(), A2.build();
  for (auto [u, v, t] : S) {
    p[++tot] = {0, A1.dfn[u], A2.dfn[v], t, 1};
    p[++tot] = {0, A1.dfn[u] + A1.siz[u], A2.dfn[v], t, -1};
    p[++tot] = {0, A1.dfn[u], A2.dfn[v] + A2.siz[v], t, -1};
    p[++tot] = {0, A1.dfn[u] + A1.siz[u], A2.dfn[v] + A2.siz[v], t, 1};
  }
  for (int i = 1; i <= Q; i++) {
    string a, b; cin >> a >> b;
    if (a.size() != b.size()) { continue; }
    int u = 0, v = 0, ans = 0;
    int ld = -1, rd = -1;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] != b[j]) {
        if (ld == -1) ld = j;
        rd = j;
      }
    }
    for (int j = 0; j < a.size(); j++) {
      u = A1.t[u][a[j] - 'a'], v = A2.t[v][b[j] - 'a'];
      if (j < rd) continue;

      int x = A1.dfn[u], y = A2.dfn[v], T = j - ld + 1;
      p[++tot] = {1, x, y, T, i};
      // for (int _ = 1; _ <= tot; _++) {
      //   if (p[_].x <= x && p[_].y <= y && p[_].t >= T) {
      //     ans += p[_].coe;
      //   }
      // }
    }
    // cout << ans << "\n";
  }
  sort(p + 1, p + tot + 1, [](Point A, Point B) {
    if (A.t != B.t) return A.t > B.t;
    if (A.x != B.x) return A.x < B.x;
    if (A.y != B.y) return A.y < B.y;
    return A.op < B.op;
  });
  // cerr << "time = " << clock() * 1e3 / CLOCKS_PER_SEC << " ms\n";
  SOLVE(1, tot);
  for (int i = 1; i <= Q; i++) {
    cout << ans[i] << "\n";
  }
  // cerr << "time = " << clock() * 1e3 / CLOCKS_PER_SEC << " ms\n";
}
// g++ -o replace replace.cpp -O2 -std=c++14 -fsanitize=undefined