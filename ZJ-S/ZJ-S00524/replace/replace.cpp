#include <bits/stdc++.h>
// #define int long long
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define rep(i, x, y) for (int i = (x); i >= (y); i--)
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define pb emplace_back
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
const int N = 2e5 + 5, V = 5e6 + 5;
int n, q;
int son[V][26], go[V][26], fail[V], dep[V], cnt[V], fa[24][V], d[V];
int tot;
int pos[V], szh;
void Main() {
    cin >> n >> q;
    For (i, 1, n) {
        string s1, s2; cin >> s1 >> s2;
        int m = s1.size(), now = 0;
        For (j, 0, m - 1) {
            if (!son[now][s1[j] - 'a']) son[now][s1[j] - 'a'] = ++tot, dep[tot] = dep[now] + 1;
            now = son[now][s1[j] - 'a'];
            if (!son[now][s2[j] - 'a']) son[now][s2[j] - 'a'] = ++tot, dep[tot] = dep[now] + 1;
            now = son[now][s2[j] - 'a'];
        }
        cnt[now]++;
    }
    queue<int> qu;
    For (i, 0, 25) {
        if (son[0][i]) {
            go[0][i] = son[0][i];
            qu.push(son[0][i]);
        }
    }
    while (!qu.empty()) {
        int x = qu.front(); qu.pop();
        pos[++szh] = x;
        For (i, 0, 25) {
            if (son[x][i]) {
                go[x][i] = son[x][i];
                fail[son[x][i]] = go[fail[x]][i];
                qu.push(son[x][i]);
            } else {
                go[x][i] = go[fail[x]][i];
            }
        }
    }
    For (i, 1, szh) {
        int x = pos[i];
        cnt[x] += cnt[fail[x]];
        fa[0][x] = fail[x];
        d[x] = d[fail[x]] + 1;
        For (j, 1, __lg(d[x] + 1)) fa[j][x] = fa[j - 1][fa[j - 1][x]];
    }
    while (q--) {
        string t1, t2; cin >> t1 >> t2;
        int m = t1.size();
        int l = m, r = -1;
        For (i, 0, m - 1) {
            if (t1[i] != t2[i]) {
                if (l == m) l = i;
                r = i;
            }
        }
        int now = 0;
        ll ans = 0;
        For (i, 0, m - 1) {
            now = go[now][t1[i] - 'a'];
            now = go[now][t2[i] - 'a'];
            if (i >= r) {
                int len = 2 * (i - l + 1);
                if (dep[now] >= len) {
                    int x = now;
                    rep (j, __lg(d[now] + 1), 0) {
                        if (dep[fa[j][x]] >= len) {
                            x = fa[j][x];
                        }
                    }
                    ans += cnt[now] - cnt[fa[0][x]];
                }
            }
        }
        cout << ans << '\n';
    }
    return;
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    int T;
    T = 1;
    while (T--) Main();
    return 0;
}