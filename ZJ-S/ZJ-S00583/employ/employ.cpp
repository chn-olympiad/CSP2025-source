#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    char ch = getchar();
    int x = 0, m = 1;
    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 505, mod = 998244353;

void Add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int add(int x, int y) {
    return ((x += y) >= mod) ? (x - mod) : x;
}

int a[N], cnt[N], sum[N], f[2][N][N], fac[N], C[N][N];

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        char ch = getchar();
        while (!isdigit(ch)) ch = getchar();
        a[i] = ch - '0';
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++) cnt[read()]++, fac[i] = fac[i - 1] * i % mod;
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
    sum[0] = cnt[0];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + cnt[i];
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int t = i & 1;
        for (int j = 0; j <= i; j++) for (int k = 0; k <= i; k++) f[t][j][k] = 0;
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                if (n - sum[i - j - 1] < k) f[t ^ 1][j][k] = 0;
                if (!f[t ^ 1][j][k]) continue;
                int res = f[t ^ 1][j][k] * max(0ll, sum[i - j - 1] - (i - k - 1)) % mod;
                if (res) for (int x = 0; x <= min(k, cnt[i - j]); x++) Add(f[t][j][k - x], C[cnt[i - j]][x] * fac[x] % mod * C[k][x] % mod * res % mod);
                if (n - sum[i - j - 1] > k) {
                    if (!a[i]) for (int x = 0; x <= min(k + 1, cnt[i - j]); x++) Add(f[t][j][k + 1 - x], C[cnt[i - j]][x] * fac[x] % mod * C[k + 1][x] % mod * f[t ^ 1][j][k] % mod);
                    else Add(f[t][j + 1][k + 1], f[t ^ 1][j][k]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = m; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (n - sum[n - i] == j) Add(ans, f[n & 1][i][j] * fac[j] % mod);
        }
    }
    write(ans);
    putchar('\n');
}