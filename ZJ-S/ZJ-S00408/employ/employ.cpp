#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510, mod = 998244353;
char a[N];
int b[N], n, m, dp[1 << 18][20], ans;
signed main() {
	freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%lld%lld%s", &n, &m, a + 1);
    for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    if(m == n) {
        for(int i = 1; i <= n; i++) if(a[i] == '0' || !b[i]) {
            printf("0");
            return 0;
        }
        ans = 1;
        for(int i = 1; i <= n; i++) ans = ans * i % mod;
        printf("%lld", ans);
        return 0;
    }
    // if(m == 1) {
    //     int x = 0;
    //     for(int i = 1; i <= n; i++) if(a[i] == '1') {
    //         x = i;
    //         break;
    //     }
    //     if(x == 0) {
    //         printf("0");
    //         return 0;
    //     }
    //     ans = 1;
    //     for(int i = 1; i < n; i++) ans = ans * i % mod;
    //     int cnt = 0;
    //     for(int i = 1; i <= n; i++) if(b[i] >= x) cnt++;
    //     printf("%lld", cnt * ans % mod);
    //     return 0;
    // }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) for(int j = 0; j < (1 << n); j++) if(__builtin_popcount(j) == i) {
        for(int k = 0; k <= i; k++) if(dp[j][k]) {
            for(int l = 1; l <= n; l++) if((j & (1 << (l - 1))) == 0) {
                if(a[i + 1] == '0' || b[l] <= i - k) dp[j ^ (1 << (l - 1))][k] = (dp[j ^ (1 << (l - 1))][k] + dp[j][k]) % mod;
                else dp[j ^ (1 << (l - 1))][k + 1] = (dp[j ^ (1 << (l - 1))][k + 1] + dp[j][k]) % mod;
            }
        }
    }
    for(int i = m; i <= n; i++) ans = (ans + dp[(1 << n) - 1][i]) % mod;
    printf("%lld", ans);
}