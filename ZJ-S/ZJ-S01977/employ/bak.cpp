#include <bits/stdc++.h>
using namespace std;
const int N = 105, mod = 998244353;
int n, m, s[N], buc[N], f[N][N][N], g[N][N][N], ct0[N], fac[N], ifac[N], a[N];
char str[N];
inline void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}
inline int pls(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
inline int ksm(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod, y >>= 1;
    }
    return res;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d%s", &n, &m, str + 1);
    for(int i = 1; i <= n; i++) if(str[i] == '0') {
        ct0[i] = 1;
    }
    for(int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        s[x]++, buc[x]++;
        a[i] = x;
    }
    static int p[N];
    for(int i = 1; i <= n; i++) p[i] = i;
    int ans = 0;
    do {
        int ct = 0;
        for(int i = 1; i <= n; i++) if(a[p[i]] <= ct || str[i] == '0') ct++;
        if(ct + m <= n) ans++;
    }while(next_permutation(p + 1, p + n + 1));
    printf("%d\n", ans);
    return 0;
}