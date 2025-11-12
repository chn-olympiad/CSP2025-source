/*
start at 14:55
finish at 15:02
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100100, M = 3;
int T, n, m;
int a[N][M], cnt[M], b[N], c[N];
void solve() {
    scanf("%d", &n), m = 0;
    int u = -1, ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = -1;
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &a[i][j]);
            if (p == -1 || a[i][j] > a[i][p]) p = j;
        }
        ++cnt[p], ans += a[i][p], c[i] = p;
    }
    for (int i = 0; i < 3; ++i) if (u == -1 || cnt[i] > cnt[u]) u = i;
    for (int i = 1; i <= n; ++i) if (c[i] == u) {
        int mx = 0;
        for (int j = 0; j < 3; ++j) if (j != u) mx = max(mx, a[i][j]);
        b[++m] = mx - a[i][u];
    }
    sort(b + 1, b + m + 1, greater<int>());
    for (int i = 1, c = cnt[u]; i <= m; ++i) if (c > n / 2) ans += b[i], --c;
    printf("%d\n", ans);
    for (int i = 0; i < 3; ++i) cnt[i] = 0;
    for (int i = 1; i <= n; ++i) c[i] = -1;
    return;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}