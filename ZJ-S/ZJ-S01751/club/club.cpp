#include <bits/stdc++.h>
using namespace std;

int T, n, a[100024], b[100024], c[100024], d[100024], e[100024];

int work(int* x, int* ya, int* yb, int k, int ix) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (d[i] == ix) e[++cnt] = x[i] - max(ya[i], yb[i]);
    sort(e + 1, e + cnt + 1);
    int dans = 0;
    for (int i = 1; i <= k; i++) dans += e[i];
    return dans;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        int ca = 0, cb = 0, cc = 0, ans = 0, m;
        cin >> n;
        m = (n >> 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            if (a[i] >= b[i] && a[i] >= c[i]) ca++, ans += a[i], d[i] = 1;
            else if (b[i] >= a[i] && b[i] >= c[i]) cb++, ans += b[i], d[i] = 2;
            else cc++, ans += c[i], d[i] = 3;
        }
        if (ca > m) ans -= work(a, b, c, ca - m, 1);
        if (cb > m) ans -= work(b, a, c, cb - m, 2);
        if (cc > m) ans -= work(c, a, b, cc - m, 3);
        cout << ans << '\n';
    }
    return 0;
}