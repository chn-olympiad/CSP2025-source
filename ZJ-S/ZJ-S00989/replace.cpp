#include <bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
#define ForDown(i, j, k) for(int i = (j); i >= (k); i--)
#define LJY main
#define within :
using namespace std;
typedef long long ll;
const int N = 4e5 + 5, M = 5e6 + 5;
const int B1 = 37, M1 = 998244353, B2 = 41, M2 = 1e9 + 325609;
int n, q, tr[M][26], tot, cnt[M];
string s[N][2]; int len[N], pre[N], suf[N], ans[N];
struct Hash {ll v1, v2; int len;};
vector<int> Mdf[M];
bool operator<(Hash a, Hash b) {return a.v1 != b.v1 ? (a.v1 < b.v1) : (a.v2 != b.v2 ? a.v2 < b.v2 : a.len < b.len);}
Hash operator+(Hash a, char c) {a.v1 = (a.v1 * B1 + c - 'a' + 1) % M1, a.v2 = (a.v2 * B2 + c - 'a' + 1) % M2; a.len++; return a;} 
pair<Hash, Hash> val[N]; int id[N];
map<pair<Hash, Hash>, int> mp; int cid; vector<int> vec[N];
int h[M], ce; struct Edge {int v, nxt;} e[M];
void addedge(int u, int v) {e[++ce] = {v, h[u]}; h[u] = ce;}
void dfs(int u) {
  for(int i within Mdf[u]) {
    int u = 0;
    if(i <= n) {
      For(j, suf[i] + 1, len[i] - 1) {
        int c = s[i][0][j] - 'a';
        if(!tr[u][c]) tr[u][c] = ++tot; u = tr[u][c];
      } cnt[u]++;
    } else {
      ans[i] += cnt[u];
      For(j, suf[i] + 1, len[i] - 1) {
        int c = s[i][0][j] - 'a';
        if(tr[u][c]) u = tr[u][c]; else break; ans[i] += cnt[u];}
    }
  } for(int i = h[u]; i; i = e[i].nxt) dfs(e[i].v);
  for(int i within Mdf[u]) if(i <= n) {
    int u = 0;
    For(j, suf[i] + 1, len[i] - 1) u = tr[u][s[i][0][j] - 'a']; cnt[u]--;
  }
}
void solve(int x) {
  bool flg1 = 0, flg2 = 0;
  for(int i within vec[x]) if(i <= n) flg1 = 1; else flg2 = 1;
  if(!flg1 || !flg2) return;
  for(int i within vec[x]) {
    int u = 0;
    ForDown(j, pre[i] - 1, 0) {
      if(!tr[u][s[i][0][j] - 'a']){ if(i <= n) tr[u][s[i][0][j] - 'a'] = ++tot, u = tot; else break;}
      else u = tr[u][s[i][0][j] - 'a'];
    } Mdf[u].emplace_back(i);
  } For(i, 0, tot) For(j, 0, 25) if(tr[i][j]) addedge(i, tr[i][j]); int lsttot = tot;
  For(i, 0, tot) memset(tr[i], 0, sizeof(tr[i])); tot = 0; dfs(0);
  For(i, 0, tot) memset(tr[i], 0, sizeof(tr[i])), cnt[i] = 0; tot = 0;
  For(i, 0, lsttot) Mdf[i].clear(), h[i] = 0; ce = 0;
}
signed LJY() {
  freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  For(i, 1, n + q) {
    cin >> s[i][0] >> s[i][1]; len[i] = s[i][0].size();
    if(s[i][1].size() != len[i]) continue;
    pre[i] = -1; For(j, 0, len[i] - 1) if(s[i][0][j] != s[i][1][j]) {pre[i] = j; break;}
    if(pre[i] == -1) {i--; n--; continue;}
    suf[i] = -1; ForDown(j, len[i] - 1, 0) if(s[i][0][j] != s[i][1][j]) {suf[i] = j; break;}
    For(j, pre[i], suf[i]) val[i].first = val[i].first + s[i][0][j], val[i].second = val[i].second + s[i][1][j];
    if(!mp.count(val[i])) mp[val[i]] = ++cid, id[i] = cid; else id[i] = mp[val[i]];
    vec[id[i]].emplace_back(i);
  } For(i, 1, cid) solve(i);
  For(i, n + 1, n + q) printf("%d\n", ans[i]);
}