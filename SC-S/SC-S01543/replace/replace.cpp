#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i=(a);i<(b);++i)
#define forv(v,adj,fs) for(int v:adj)if(v!=fs)
#define forvw(v,w,adj,fs) for(auto[v,w]:adj)if(v!=fs)
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;
const int _inf32 = 0x3f3f3f3f;
const i64 _inf64 = 0x3f3f3f3f3f3f3f3f;
#define ckmax(a,b) (a=max(a,b))
#define ckmin(a,b) (a=min(a,b))
#define pb emplace_back
#define FI first
#define SE second

const int MaxN = int(2e5+7);
const int L = int(2.5e6+7);
const u64 P = 13131;

int n, q;
i64 ans[MaxN];
u64 h1[MaxN];

namespace acam {
  int trie[L][26], fail[L];
  vector<int> ed[L];
  vector<int> son[L];
  int tot;
  void init() {
    tot = 1;
  }
  void insert(const string &s, int id) {
    int p = 1;
    for (char c : s) {
      int x = c-'a';
      if (!trie[p][x]) {
        trie[p][x] = ++tot;
        // son[p].pb(tot);
      }
      p = trie[p][x];
    }
    ed[p].pb(id);
  }
  void build() {
    queue<int> que;
    que.push(1);
    fail[1] = 1;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      For (x, 0, 26) {
        if (trie[u][x]) {
          int v = trie[u][x];
          fail[v] = trie[fail[u]][x];
          if (fail[v] == v) fail[v] = 1;
          que.push(v);
        }
        else {
          trie[u][x] = trie[fail[u]][x];
          if (!trie[u][x]) trie[u][x] = 1;
        }
      }
    }
  }
  vector<pair<int,u64>> qry[L];
  map<u64,int> cnt;
  void DFS(int u) {
    for (int x : ed[u]) ++cnt[h1[x]];
    for (auto [x, val] : qry[u])
      if (cnt.count(val))
        ans[x] += cnt[val];
    for (int v : son[u])
      DFS(v);
    for (int x : ed[u]) --cnt[h1[x]];
  }
  void solve() {
    For (i, 2, tot+1) son[fail[i]].pb(i);
    DFS(1);
  }
}

namespace hsh {
  u64 pwr[L];
  void init() {
    pwr[0] = 1;
    For (i, 1, L) pwr[i] = pwr[i-1]*P;
  }
  u64 calc(const string &s) {
    u64 ret = 0;
    int n = s.size();
    For (i, 0, n) ret += s[i]*pwr[i];
    return ret;
  }
}
using hsh::pwr;

namespace work {
  void main() {
    acam::init();
    hsh::init();
    cin >> n >> q;
    // i64 debug_tot = 0;
    For (i, 0, n) {
      string s1, s2;
      cin >> s1 >> s2;
      int len = s1.size();
      // debug_tot += len;
      h1[i] = (hsh::calc(s2)-hsh::calc(s1))*pwr[L-len];
      // cerr << h1[i] << endl;
      acam::insert(s1, i);
    }
    // cerr << debug_tot << endl;
    acam::build();
    // cerr << "-----\n";
    For (i, 0, q) {
      string t1, t2;
      cin >> t1 >> t2;
      // assert(t1.size() == t2.size());
      if (t1.size() != t2.size()) continue;
      u64 tar = hsh::calc(t2)-hsh::calc(t1);
      int pos = 0;
      int len = t1.size();
      For (j, 0, len) if (t1[j] != t2[j]) pos = j;
      int p = 1;
      For (j, 0, pos) p = acam::trie[p][t1[j]-'a'];
      For (j, pos, len) {
        p = acam::trie[p][t1[j]-'a'];
        u64 re = tar*pwr[L-j-1];
        // cerr << re << endl;
        acam::qry[p].pb(i,re);
      }
      // cerr << "----\n";
    }
    acam::solve();
    For (i, 0, q) cout << ans[i] << '\n';
    // cerr << acam::tot << endl;
  }
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(nullptr);
  work::main();
  cout.flush();
  fclose(stdin);
  fclose(stdout);
  return 0;
}