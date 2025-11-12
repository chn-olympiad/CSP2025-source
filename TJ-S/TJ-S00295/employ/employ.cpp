#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int mod = 998244353;
typedef long long LL;

int n, m;
char s[N];
int c[N];

int p(int k) {
    int res = 1;
    for (int i = 2; i <= k; i ++ ) res = (res * (LL)i) % mod;
    return res;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);

    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        if (c[i] == 0)
            cnt ++ ;

    if (n - cnt + 1 < m) puts("0");
    else if (n - cnt + 1 == m) printf("%d\n", ((LL)cnt * p(n - 1)) % mod);
    else printf("%d\n", p(n));

    return 0;
}
