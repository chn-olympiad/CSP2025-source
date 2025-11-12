#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int N = 2e5 + 10;
const int M = 5e6 + 10;
const int K1 = 97, K2 = 47;
const int B1 = 998244853, B2 = 1000000009;
int n, q, L1, L2, b1[M], b2[M];
string s1[N], s2[N], t1[N], t2[N];
inline vector<pii > sethash(string & s) {
    int n = s.size();
    vector<pii > f(n + 1);
    for (int i = 0; i < n; i++) {
        f[i+1] = {((ll)f[i].first * K1 + s[i] - 'a') % B1, ((ll)f[i].second * K2 + s[i] - 'a') % B2};
    }
    return f;
}
inline pii gethash(vector<pii > & f, int x, int y) {
    return {((f[y].first - (ll)f[x - 1].first * b1[y - x + 1]) % B1 + B1) % B1
            , ((f[y].second - (ll)f[x - 1].second * b2[y - x + 1]) % B2 + B2) % B2};
}
void solve1() {
    vector<vector<pair<pii, pii> > > a(max(L1, L2) + 2);
    for (int i = 1; i <= n; i++) {
        vector<pii > f1 = sethash(s1[i]), f2 = sethash(s2[i]);
        a[s1[i].size()].emplace_back(make_pair(f1.back(), f2.back()));
    }
    for (int i = 0; i <= max(L1, L2); i++) sort(a[i].begin(), a[i].end());
    for (int p = 1; p <= q; p++) {
        if (t1[p].size() != t2[p].size()) {
            cout << 0 << '\n';
            continue;
        }
        int len = t1[p].size(), st, ed;
        auto f1 = sethash(t1[p]);
        auto f2 = sethash(t2[p]);
        for (int i = 0; i < len; i++) if (t1[p][i] != t2[p][i]) {
            st = i; break;
        }
        for (int i = len - 1; i >= 0; i--) if (t1[p][i] != t2[p][i]) {
            ed = i; break;
        }
        int res = 0;
        for (int i = 0; i <= st; i++) {
            for (int j = ed; j < len; j++) if (a[j - i + 1].size()) {
                pii x = gethash(f1, i + 1, j + 1), y = gethash(f2, i + 1, j + 1);
                res += (upper_bound(a[j-i+1].begin(), a[j-i+1].end(), make_pair(x, y))
                        - lower_bound(a[j-i+1].begin(), a[j-i+1].end(), make_pair(x, y)));
            }
        }
        cout << res << '\n';
    }
}
inline bool isspecial(string & s) {
    int c1 = 0, c2 = 0;
    for (char c : s) {
        if (c == 'a') c1++;
        if (c == 'b') c2++;
    }
    return c1 + 1 == s.size() && c2 == 1;
}
void solve2() {
    solve1();
}
void solve3() {
    solve1();
}
void solvedefault() {
    solve1();
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i], L1 += s1[i].size() + s2[i].size();
    for (int i = 1; i <= q; i++) cin >> t1[i] >> t2[i], L2 += t1[i].size() + t2[i].size();
    b1[0] = b2[0] = 1;
    for (int i = 1; i <= max(L1, L2); i++) b1[i] = (ll)b1[i-1] * K1 % B1, b2[i] = (ll)b2[i-1] * K2 % B2;
    if (max(n, q) <= 1000 && max(L1, L2) <= 2000) {
        solve1();
        return 0;
    }
    if (q == 1) {
        solve2();
        return 0;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) if (!isspecial(s1[i]) || !isspecial(s2[i])) flag = false;
    for (int i = 1; i <= q; i++) if (!isspecial(t1[i]) || !isspecial(t2[i])) flag = false;
    if (flag) {
        solve3();
        return 0;
    }
    solvedefault();
    return 0;
}
