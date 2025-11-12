#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 998244353;

constexpr int maxn = 500;
int n, m;
int ans = 0;
string diff;
int c[505];
int a[505];

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    cin >> diff;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        a[i] = i;
    }

    do {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt >= c[a[i]] || diff[i] == '0') { ++ cnt; }
        }
        if (n - cnt >= m) { ++ ans; }
        if (ans >= mod) { ans -= mod; }
    } while (next_permutation(a, a+n));

    cout << ans << endl;
    return 0;
}
