#include <bits/stdc++.h>

const int N = 500;
const int P = 998244353;
int n, m, c[N + 5], f[N + 5][N + 5];
int cnt[N + 5], s0[N + 5];
int fac[N + 5], inv[N + 5], caf[N + 5];
char s[N + 5];

int A(int aa, int bb) {
    if (aa + bb >= P) {
        return aa + bb - P;
    }
    return aa + bb;
}

int M(int aa, int bb) {
    return 1ll * aa * bb % P;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%d%s", &n, &m, s + 1);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &c[i]);
    }

    fac[0] = fac[1] = inv[1] = caf[0] = caf[1] = 1;
    for (int i = 2; i <= n; ++ i) {
        fac[i] = M(fac[i - 1], i);
        inv[i] = A(P, -M(inv[P % i], P / i));
        caf[i] = M(fac[i - 1], inv[i]);
    }

    for (int i = 1; i <= n; ++ i) {
        if (s[i] == '0') {
            s0[i] = s0[i - 1] + 1;
        } else {
            s0[i] = s0[i - 1];
        }
    }

    std::sort(c + 1, c + n + 1);
    for (int i = 0, j = 1; i <= n; ++ i) {
        while (j <= n && c[j] <= i) {
            ++ j;
        }
        cnt[i] = j - 1;
    }

    for (int i = m; i <= n; ++ i) {
        f[0][i] = 1;
    }
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == '0') {
            continue;
        }

        for (int j = n; j >= 0; -- j) {
            for (int k = 0; k <= n; ++ k) {
                f[j][k] = 0;
                if (n - cnt[j + s0[i - 1]] - k > 0) {
                    f[j][k] = A(f[j][k], M(f[j][k + 1], n - cnt[j + s0[i - 1]] - k));
                }
                if (j >= 1 && cnt[j - 1 + s0[i - 1]] - (j - 1) > 0) {
                    f[j][k] = A(f[j][k], M(f[j - 1][k], cnt[j - 1 + s0[i - 1]] - (j - 1)));
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n - s0[n] - m; ++ i) {
        ans = A(ans, M(f[i][0], fac[s0[n]]));
    }
    printf("%d\n", ans);
    return 0;
}

