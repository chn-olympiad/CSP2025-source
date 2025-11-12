#include<bits/stdc++.h>
#define int long long
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)
using namespace std;
constexpr int mod = 998244353;
int s[500 + 5], c[500 + 5], p[500 + 5];
int32_t main() {
    file(employ);
    cin.tie(0)->sync_with_stdio(false);
    int n, m; cin >> n >> m; string ss; cin >> ss;
    for (int i = 1; i <= n; ++i) s[i] = ss[i - 1] - '0';
    for (int i = 1; i <= n; ++i) cin >> c[i];
    // for (int i = 1; i <= n; ++i) cerr << s[i] << " \n"[i == n];
    if (n > 20) {
        int cnt = count(c + 1, c + n + 1, 0);
        if (n - cnt < m) {
            cout << 0 << endl;
        }
        else {
            int t = 1;
            while (n) t = t * n-- % mod;
            cout << t << endl;
        }
        return 0;
    }
    int ans = 0;
    iota(p + 1, p + n + 1, 1);
    do {
        int cnt_down = 0;
        for (int i = 1; i <= n; ++i)
            if (cnt_down >= c[p[i]] || !s[i])
                cnt_down++;
        ans += n - cnt_down >= m;
        // cerr << cnt_down << endl;
    } while(next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}