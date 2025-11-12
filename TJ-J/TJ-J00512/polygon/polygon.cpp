#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5000 + 10;
const int P = 998244353;
int n, m, a[N], c[N][N], b[N], f[N], nxt[N], ans;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    m = a[n];

    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % P;
    }
    b[0] = 1;
    for (int i = 1; i <= n; i++) b[i] = (ll)b[i-1] * 2 % P;

    for (int i = 0; i <= n + 1; i++) nxt[i] = -1;
    a[n + 1] = a[n] + 1;
    for (int j = 0, i = 1; i <= n + 1; i++) if (i == 1 || a[i] != a[i - 1]) {
        nxt[j] = i;
        j = i;
    }

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (nxt[i] != -1 && nxt[i] > 3) {
            if (i >= 3) {
                int sub = 0;
                for (int j = 0; j <= a[i]; j++) sub = (sub + f[j]) % P;
                ans = ((ans + ((ll)b[i - 1] - sub) * (nxt[i] - i) % P) % P + P) % P;
            }
            for (int j = 2; j <= nxt[i] - i; j++) {
                if (j == 2) ans = ((ans + (ll)c[nxt[i] - i][j] * (b[i - 1] - 1) % P) % P + P) % P;
                else ans = (ans + (ll)c[nxt[i] - i][j] * b[i - 1]) % P;
            }
        }
        for (int j = m; j >= a[i]; j--) f[j] = (f[j] + f[j - a[i]]) % P;
    }
    ans = (ans % P + P) % P;
    cout << ans << '\n';
    return 0;
}
