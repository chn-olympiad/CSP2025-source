#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;
typedef __int128 i128;
typedef unsigned long long ull;
typedef pair<ull, ull> pii;

const int N = 2e5 + 5, M = 5e6 + 5, inf = 1e16, mod = 998244353;
const ull B = 1e7 + 7;
bool bg;
int n, q;
ull pw1[M];
int pw2[M];
struct Hash {
    int len; ull h1; int h2;
    Hash(int l = 0, ull x = 0, int y = 0) {
        len = l, h1 = x, h2 = y;
    }
    friend Hash operator + (Hash x, Hash y) {
        Hash z; z.len = x.len + y.len;
        z.h1 = x.h1 * pw1[y.len] + y.h1;
        z.h2 = (x.h2 * pw2[y.len] + y.h2) % mod;
        return z;
    }
    friend Hash operator - (Hash x, Hash y) {
        Hash z; z.len = x.len - y.len;
        z.h1 = x.h1 - pw1[z.len] * y.h1;
        z.h2 = (x.h2 - pw2[z.len] * y.h2 % mod + mod) % mod;
        return z;
    }
    friend bool operator < (Hash x, Hash y) {
        if (x.len != y.len) return x.len < y.len;
        if (x.h1 != y.h1) return x.h1 < y.h1;
        return x.h2 < y.h2;
    }
    friend bool operator == (Hash x, Hash y) {
        return x.len == y.len && x.h1 == y.h1 && x.h2 == y.h2;
    }
} ht1[M], ht2[M];
int tot;
vector<Hash> h1[N], h2[N];
vector<int> vec[N];
map<Hash, int> mp, mp2;
string s1[N], s2[N];
Hash g1(int l, int r) { return ht1[r] - ht1[l - 1]; }
Hash g2(int l, int r) { return ht2[r] - ht2[l - 1]; }
bool ed;
signed main() {
    // cerr << (&bg - &ed) / 1048576.0 << '\n';
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    pw1[0] = pw2[0] = 1;
    F(i, 1, M - 1) {
        pw1[i] = pw1[i - 1] * B;
        pw2[i] = pw2[i - 1] * B % mod;
    }
    vector<int> len;
    F(i, 1, n) {
        cin >> s1[i] >> s2[i];
        if (s1[i] == s2[i]) continue;
        int m = s1[i].size(), l = 0, r = m - 1;
        len.push_back(m);
        h1[i].resize(m + 1, Hash());
        h2[i].resize(m + 1, Hash());
        F(j, 1, m) {
            h1[i][j] = h1[i][j - 1] + Hash(1, s1[i][j - 1], s1[i][j - 1]);
            h2[i][j] = h2[i][j - 1] + Hash(1, s2[i][j - 1], s2[i][j - 1]);
        }
        mp[h1[i][m] + h2[i][m]]++;
        // fen lei
        while (s1[i][r] == s2[i][r]) r--;
        Hash tp = h1[i][r + 1] - h1[i][l] + (h2[i][r + 1] - h2[i][l]);
        if (!mp2[tp]) mp2[tp] = ++tot;
        vec[mp2[tp]].emplace_back(m);
    }
    sort(len.begin(), len.end());
    len.erase(unique(len.begin(), len.end()), len.end());
    F(i, 1, tot) {
        sort(vec[i].begin(), vec[i].end());
        vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int m = t1.size(), ans = 0, L = 0, R = m - 1;
        while (t1[L] == t2[L]) L++;
        while (t1[R] == t2[R]) R--;
        F(j, 1, m) {
            ht1[j] = ht1[j - 1] + Hash(1, t1[j - 1], t1[j - 1]);
            ht2[j] = ht2[j - 1] + Hash(1, t2[j - 1], t2[j - 1]);
        }
        F(l, 0, L) {
            Hash v = g1(l + 1, R + 1) + g2(l + 1, R + 1);
            if (mp2.count(v)) {
                int id = mp2[v];
                for (int i : vec[id]) {
                    int p = l + i - 1;
                    if (p >= R && p < m) {
                        ans += mp[g1(l + 1, p + 1) + g2(l + 1, p + 1)];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}