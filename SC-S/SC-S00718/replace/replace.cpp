#include<bits/stdc++.h>
#define int long long
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)
using namespace std;
constexpr int p = 131, mod = 998244353;
int n, q, fac[5000000 + 5];
struct Node {
    int len, hashnum1, hashnum2;
    Node(int len = 0) : len(len), hashnum1(), hashnum2() {}
    void prep(string s, string t) {
        len = s.size(); hashnum1 = hashnum2 = 0;
        for (int i = 0; i < len; ++i)
            hashnum1 = (hashnum1 + s[i] * fac[i] % mod) % mod,
            hashnum2 = (hashnum2 + t[i] * fac[i] % mod) % mod;
    }
    friend bool operator<(const Node&a, const Node&b) {
        return a.len < b.len;
    }
}s[200000 + 10];
int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
int32_t main() {
    file(replace);
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q; fac[0] = 1; int inv = qpow(p, mod);
    for (int i = 1; i <= 5e6; ++i) fac[i] = fac[i - 1] * p % mod;
    for (int i = 1; i <= n; ++i) {
        string t1, t2;
        cin >> t1 >> t2;
        s[i].prep(t1, t2);
    }
    sort(s + 1, s + n + 1);
    while (q--) {
        string t[2];
        cin >> t[0] >> t[1];
        int cnt = 0, m = t[0].size(), lst = -1, rst = m;
        for (int i = 0; i < m; ++i) {
            if (t[0][i] != t[1][i]) {
                if (lst == -1) lst = i;
                rst = i;
            }
        }
        int ans = 0;
        int l = max<int>(lower_bound(s + 1, s + n + 1, rst - lst + 1) - s - 2, 1);
        int r = min<int>(upper_bound(s + 1, s + n + 1, m) - s + 2, n);
        // int l = 1, r = n;
        for (int i = l; i <= r; ++i) {
            if (rst - lst + 1 <= s[i].len && s[i].len <= m) {
                int beg = max(0ll, rst - s[i].len + 1);
                int hshnum1 = 0, hshnum2 = 0;
                for (int j = beg; j < beg + s[i].len; ++j)
                    hshnum1 = (hshnum1 + t[0][j] * fac[j] % mod) % mod,
                    hshnum2 = (hshnum2 + t[1][j] * fac[j] % mod) % mod;
                for (int j = beg; j <= lst; ++j) {
                    if (hshnum1 == s[i].hashnum1 * fac[j] % mod && hshnum2 == s[i].hashnum2 * fac[j] % mod) 
                        ans++; //, cerr << "string " << t[0] << " replace " << j << " (s" << i << ") could be true" << endl;
                    hshnum1 = (hshnum1 - t[0][j] * fac[j] % mod + mod) % mod;
                    if (j + s[i].len < m)
                        hshnum1 = (hshnum1 + t[0][j + s[i].len] * fac[j + s[i].len] % mod) % mod;
                    else break;
                    hshnum2 = (hshnum2 - t[1][j] * fac[j] + mod) % mod;
                    hshnum2 = (hshnum2 + t[1][j + s[i].len] * fac[j + s[i].len] % mod) % mod;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}