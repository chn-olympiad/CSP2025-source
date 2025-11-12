#include <bits/stdc++.h>
using namespace std;

#define file(name) assert(freopen(#name".in", "r", stdin)), assert(freopen(#name".out", "w", stdout))
#define _f(i, a, b) for(int i = a; i <= b; ++i)
#define _d(i, a, b) for(int i = a; i >= b; --i)
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define all(container) container.begin(), container.end()

bool fir;

constexpr int N = 2e5 + 5, L = 5e6 + 5, mod = 1e9 + 7, base = 998244353;

int n, q, pw[L];
pii sp[N], ttp[N], ps[N], pt[N];
ll ans[N];
string s[N][2], t[N][2];
map<int, vector<pii>> mp;
map<int, int> sc, tc;
pii gt(string a, string b) {
    assert(a.length() == b.length());
    assert(a != b);
    int l = a.length(), p = 0, q = 0;
    _f(i, 0, l - 1) {
        if(a[i] == b[i]) ++p;
        else break;
    }
    _d(i, l - 1, 0) {
        if(a[i] == b[i]) ++q;
        else break;
    }
    return make_pair(p, q);
}
void add(int &x, int y) { x += y; if(x >= mod) x -= mod; }
void sub(int &x, int y) { x -= y; if(x < mod) x += mod; }
int gethsh(string s, string t, int l, int r) {
    int ret = 0;
    _f(i, l, r) ret = 1ll * ret * base % mod, add(ret, (int)s[i]), ret = 1ll * ret * base % mod, add(ret, (int)t[i]);
    return ret;
}
int gethsh(string s, int l, int r) {
    int ret = 0;
    _f(i, l, r) ret = 1ll * ret * base % mod, add(ret, (int)s[i]);
    return ret;
}

struct {
    int f[L], n;
    void init(int _n) {
        n = _n;
        fill(f, f + n + 1, 0);
    }
    int lowbit(int x) {return x & (-x); }
    void add(int x, int k) {
        while(x <= n) f[x] += k, x += lowbit(x);
    }
    void add(int l, int r, int k) {
        add(l, k), add(r + 1, -k);
    }
    int qry(int x) {
        int ret = 0;
        while(x) ret += f[x], x -= lowbit(x);
        return ret;
    }
} bit;

vector<pii> vec[L];
int dfn[L], ed[L], jzc;

void ad(int x, int k) {
    bit.add(dfn[x], ed[x], k);
}

struct trie {
    int cnt, son[L][26];
    void init() {
        _f(i, 1, cnt) fill(son[i], son[i] + 26, 0);
        cnt = 1;
    }
    void dfs(int x) {
        dfn[x] = ++jzc;
        _f(i, 0, 25) if(son[x][i]) dfs(son[x][i]);
        ed[x] = jzc;
    }
    void solve(int x) {
        for(auto [v, i] : vec[x]) {
            if(!i) ad(v, 1);
            else ans[i] = bit.qry(dfn[v]);
        }
        _f(i, 0, 25) if(son[x][i]) solve(son[x][i]);
        for(auto [v, i] : vec[x]) {
            if(!i) ad(v, -1);
            else break;
        }
    }
} t1, t2;

map<pii, int> mpc;

bool eds;

void solve() {
    cin >> n >> q, pw[0] = 1;
    _f(i, 1, L - 5) pw[i] = 1ll * pw[i-  1] * base % mod;
    _f(i, 1, n) {
        cin >> s[i][0] >> s[i][1];
        if(s[i][0] == s[i][1]) continue;
        sp[i] = gt(s[i][0], s[i][1]);
        auto [p, q] = sp[i];
        int u = gethsh(s[i][0], s[i][1], p, s[i][0].length() - q - 1);
        mp[u].emplace_back(i, 0), sc[u]++;
    }
    _f(i, 1, q) {
        cin >> t[i][0] >> t[i][1];
        if(t[i][0].length() != t[i][1].length()) continue;
        ttp[i] = gt(t[i][0], t[i][1]);
        auto [p, q] = ttp[i];
        int u = gethsh(t[i][0], t[i][1], p, t[i][0].length() - q - 1);
        mp[u].emplace_back(i, 1), tc[u]++;
    }
    for(auto [x, vec1] : mp) {
        if(!sc[x] || !tc[x]) continue;
        t1.init(), t2.init();
        mpc.clear();
        for(auto [id, tp] : vec1) {
            if(tp == 0) {
                auto [p, q] = sp[id];
                int now = 1;
                _d(i, p - 1, 0) {
                    int x = s[id][0][i] - 'a';
                    if(!t1.son[now][x]) t1.son[now][x] = ++t1.cnt;
                    now = t1.son[now][x];
                }
                ps[id].fi = now;
                now = 1;
                int li = s[id][0].length();
                _f(i, li - q, li - 1) {
                    int x = s[id][0][i] - 'a';
                    if(!t2.son[now][x]) t2.son[now][x] = ++t2.cnt;
                    now = t2.son[now][x];
                }
                ps[id].se = now;
                vec[ps[id].fi].emplace_back(ps[id].se, 0);
            } else {
                auto [p, q] = ttp[id];
                int now = 1;
                _d(i, p - 1, 0) {
                    int x = t[id][0][i] - 'a';
                    if(!t1.son[now][x]) t1.son[now][x] = ++t1.cnt;
                    now = t1.son[now][x];
                }
                pt[id].fi = now;
                now = 1;
                int li = t[id][0].length();
                _f(i, li - q, li - 1) {
                    int x = t[id][0][i] - 'a';
                    if(!t2.son[now][x]) t2.son[now][x] = ++t2.cnt;
                    now = t2.son[now][x];
                }
                pt[id].se = now;
                vec[pt[id].fi].emplace_back(pt[id].se, id);
            }
        }
        bit.init(t2.cnt);
        jzc = 0, t2.dfs(1);
        t1.solve(1);
        _f(i, 1, t1.cnt) vec[i].clear();
    }
    _f(i, 1, q) cout << ans[i] << '\n';
}

signed main() {
    file(replace4);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    cerr << (&fir - &eds) / 1048576.0 << '\n';
    return 0;
}