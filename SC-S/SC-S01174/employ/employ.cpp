#include <bits/stdc++.h>
#define db(x...) fprintf(stderr,x)
const int N = 20, U = (1 << 18) + 10, mod = 998244353;
int f[U][N], n, m, S[N], c[N], cnt[U];
int at (int s, int i) { return (s >> (i - 1)) & 1; }
int getcnt (int s) {
    int ans = 0;
    while (s) {
        ans += (s & 1);
        s >>= 1;
    }
    return ans;
}
int main () {
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf ("%1d", &S[i]);
    for (int i = 1; i <= n; i++) scanf ("%d", &c[i]);
    if (n == m) {
        for (int i = 1; i <= n; i++)
            if (!c[i] || !S[i]) {
                printf ("0\n");
                fclose (stdin);
                fclose (stdout);    
                return 0;
            }
        printf ("1\n");
        fclose (stdin);
        fclose (stdout);
        return 0;
    } else if (n <= 18) {
        int u = (1 << n) - 1;
        for (int i = 0; i <= u; i++) cnt[i] = getcnt (i);
        for (int i = m; i <= n; i++) f[u][i] = 1;
        for (int s = u - 1; s >= 0; s--) {
            for (int i = 0; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (at (s, j)) continue;
                    int F = cnt[s] - i;
                    // if (s == 3 && i == 1) printf ("fsdf  %d j = %d\n", F, j);
                    if (F >= c[j] || !S[cnt[s] + 1]) f[s][i] += f[s + (1 << (j - 1))][i];
                    else f[s][i] += f[s + (1 << (j - 1))][i + 1];
                    if (f[s][i] >= mod) f[s][i] -= mod;
                }
            }
        }
        printf ("%d\n", f[0][0]);        
    } else {
        int ans = 1;
        for (int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
        printf ("%d\n", ans);
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}