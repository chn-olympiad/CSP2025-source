#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define mk(a, b) makr_pair(a, b)
using namespace std;
template<typename P>
inline void read(P &x) {
    P res = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        res = (res << 3) + (res << 1) + (ch ^ 48);
        ch = getchar();
    }
    x = res * f;
}
template<typename PP, typename ...Arg>
inline void read(PP &x, Arg &...args) { read(x); read(args...); }
int T = 1;

const int N = 210, M = 1e5 + 10;

int n;
int a[M][3];
ll f[N][N][N];

void solve() {
    read(n);
    bool f1 = 1;
    memset(f, 0, sizeof(f));
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 2; ++j) {
            read(a[i][j]);
            sum += a[i][j];
            if (a[i][1] != 0 || a[i][2] != 0) f1 = 0;
        }
    }
    if (f1) return (void)(cout << sum << endl);
    for (int i = 0; i <= n / 2; ++i) {
        for (int j = 0; j <= n / 2; ++j) {
            for (int k = 0; k <= n / 2; ++k) {
                if (i != 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i + j + k][0]);
                if (j != 0) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k] + a[i + j + k][1]);
                if (k != 0) f[i][j][k] = max(f[i][j][k], f[i][j][k - 1] + a[i + j + k][2]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n / 2 ; ++i) {
        for (int j = 0; j <= n / 2 ; ++j) {
            ans = max(ans, f[i][j][n - i - j]);
        }
    }
    cout << ans << endl;
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    read(T);
    while (T--) solve();
    return 0;
}