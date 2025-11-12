#include <bits/stdc++.h>

const int maxn = 1e5;
int n, a[3][maxn + 5], b[3][maxn + 5], c[maxn + 5];
int cnt[3];
int ans;

void solve() {
    scanf("%d", &n);
    cnt[0] = cnt[1] = cnt[2] = 0;
    ans = 0;
    for (int i = 1; i <= n; ++ i) {
        scanf("%d%d%d", &a[0][i], &a[1][i], &a[2][i]);
        if (a[0][i] >= a[1][i] && a[0][i] >= a[2][i]) {
            ++ cnt[0];
            b[0][cnt[0]] = i;
            ans += a[0][i];
        } else if (a[1][i] >= a[0][i] && a[1][i] >= a[2][i]) {
            ++ cnt[1];
            b[1][cnt[1]] = i;
            ans += a[1][i];
        } else {
            ++ cnt[2];
            b[2][cnt[2]] = i;
            ans += a[2][i];
        }
    }

    int t = -1;
    if (cnt[0] > n / 2) {
        t = 0;
    } else if (cnt[1] > n / 2) {
        t = 1;
    } else if (cnt[2] > n / 2) {
        t = 2;
    }

    if (t == -1) {
        printf("%d\n", ans);
        return;
    }

    for (int i = 1; i <= cnt[t]; ++ i) {
        if (a[(t + 1) % 3][b[t][i]] >= a[(t + 2) % 3][b[t][i]]) {
            c[i] = a[t][b[t][i]] - a[(t + 1) % 3][b[t][i]];
        } else {
            c[i] = a[t][b[t][i]] - a[(t + 2) % 3][b[t][i]];
        }
    }

    std::sort(c + 1, c + cnt[t] + 1);
    for (int i = 1; i <= cnt[t] - n / 2; ++ i) {
        ans -= c[i];
    }
    printf("%d\n", ans);
    return;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T --) {
        solve();
    }
    return 0;
}

