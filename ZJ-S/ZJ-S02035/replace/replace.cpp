#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int MaxLen = 5000'000;
const int HashK = 97;
const int HashP = 998244353;
const int HashU = 1000000000;
const int Mod2 = 1LL << 16;
const int Mask = Mod2 - 1;

// 2^20 * 2^12/2^3 B
// <= 2^11 * 2^20 B

ull str_hash(string &s) {
  ull res = 0;
  for (auto a : s) res = (res * HashK + (a - 'a')) % HashP;
  return res;
}

vector<ull> str_hashs(string &s) {
  int n = s.length();
  vector<ull> res(n + 1);
  for (int i = 0; i < n; i++)
    res[i + 1] = (res[i] * HashK + (s[i] - 'a')) % HashP;
  return res;
}

ull hash_ks[MaxLen + 1];
inline ull calc_hash(vector<ull> &pre, int l, int r) {
  return (pre[r] + (HashP - pre[l]) * hash_ks[r - l]) % HashP;
}

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int replaces, q;
  cin >> replaces >> q;

  vector<unordered_map<ull, int>> records(MaxLen + 1);

  // 4000M bit
  set<int> lens;
  for (int i = 0; i < replaces; i++) {
    string s, t;
    cin >> s >> t;
    lens.insert(s.length());
    ull s_hash = str_hash(s);
    ull t_hash = str_hash(t);
    records[s.length()][s_hash * HashU + t_hash]++;
  }
  vector<bitset<Mod2>> sheets(lens.size());
  int idx = 0;
  for (auto len : lens) {
    for (auto [record, c] : records[len]) sheets[idx].set(record & Mask);
    idx++;
  }
  // cerr << lens.size() << "\n";

  hash_ks[0] = 1;
  for (int i = 1; i <= MaxLen; i++) hash_ks[i] = hash_ks[i - 1] * HashK % HashP;

  // int debug_count = 0;
  // int debug_nosol = 0;
  while (q--) {
    string s, t;
    cin >> s >> t;
    // cerr << q << " " << s << " " << t << "\n";
    int n = s.length();
    int safe_r = n;
    while (safe_r) {
      if (s[safe_r - 1] != t[safe_r - 1]) break;
      safe_r--;
    }
    // cerr << n << " " << safe_r << "\n";
    auto pre_s = str_hashs(s);
    auto pre_t = str_hashs(t);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (pre_s[i] != pre_t[i]) break;
      idx = -1;
      for (int len : lens) {
        idx++;
        if (i + len > n) break;
        if (i + len < safe_r) continue;
        int l = i;
        int r = i + len;
        // ull s_part = calc_hash(pre_s, l, r);
        // ull t_part = calc_hash(pre_t, l, r);
        ull key = calc_hash(pre_s, l, r) * HashU + calc_hash(pre_t, l, r);
        if (!sheets[idx][key & Mask]) continue;
        // ++debug_count; // debug
        if (records[len].count(key)) {
          ans += records[len][key];
        }
      }
    }
    cout << ans << "\n";
    // if (!ans) debug_nosol++;
  }
  // cerr << "call times: " << debug_count << "\n";
  // cerr << "null times: " << debug_nosol << "\n";
  return 0;
}
