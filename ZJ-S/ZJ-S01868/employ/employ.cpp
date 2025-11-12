#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 110;
const LL mod = 998244353;

int n, m, a[N], c[N], nm[N], sm[N];
LL f[N][N][N], f1[N][N], jc[N], jc1[N];
char s[N];

LL C(int x, int y) {
    return jc[x] * jc1[y] % mod * jc1[x - y] % mod;
}

LL power(LL x, LL y) {
    LL z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod; y >>= 1;
    }
    return z;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        nm[c[i]]++;
    }
    sm[0] = nm[0];
    for (int i = 1; i <= n; i++)
        sm[i] = sm[i - 1] + nm[i];
    jc[0] = jc1[0] = 1;
    for (int i = 1; i <= n; i++)
        jc[i] = jc[i - 1] * i % mod,
        jc1[i] = power(jc[i], mod - 2);

    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        memset(f1, 0, sizeof(f1));
        for (int j = 0; j <= i - 1; j++) {
            for (int k = 0; k <= i - 1; k++) {
                int num = i - 1 - j;
                if (sm[k] - num < 0) continue;
                if (a[i] == 0) {
                    (f1[j][k + 1] += f[i - 1][j][k] * (sm[k] - num)) %= mod;
                    (f1[j + 1][k + 1] += f[i - 1][j][k]) %= mod;
                } else {
                    (f1[j][k + 1] += f[i - 1][j][k] * (sm[k] - num)) %= mod;
                    (f[i][j + 1][k] += f[i - 1][j][k]) %= mod;
                }
            }
        }
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= i; k++) {
                for (int l = 0; l <= min(j, nm[k]); l++) {
                    // if (f1[j][k]) cout << "k = " << k << endl;
                    (f[i][j - l][k] += f1[j][k] * C(j, l) % mod * C(nm[k], l) % mod * jc[l]) %= mod;
                }
            }
        // for (int j = 0; j <= i; j++)
        //     for (int k = 0; k <= i; k++)
        //         cout << "i = " << i << " j = " << j << " k = " << k << " f = " << f[i][j][k] << endl;
    }
    LL ans = 0;
    for (int i = 0; i <= n - m; i++) {
        ans = (ans + f[n][n - sm[i]][i] * jc[n - sm[i]]) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}