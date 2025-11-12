#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e3+7, mod = 998244353;
int n;
int a[maxn];
int c[maxn * maxn];

signed main(signed argc, char const *argv[]) {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    c[0]++;
    c[a[1]]++;
    c[a[2]]++;
    c[a[1] + a[2]]++;
    int ans = 0, pfx = a[1] + a[2];
    for (int i = 3; i <= n; i++) {
        for (int j = a[i] + 1; j <= pfx; j++) {
            ans += c[j];
            ans %= mod;
        }
        pfx += a[i];
        for (int j = pfx; j >= a[i]; j--) {
            c[j] += c[j - a[i]];
            c[j] %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
