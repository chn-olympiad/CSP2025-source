#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const i64 MOD  = 998244353;
const int N = 5005;
i64 f[N], g[N][N];
i64 a[N];

i64 power(int a, int k, int MOD)
{
    i64 res = 1;
    for (int i = 1; i <= k; i++)
    {
        res = res * a;
        res %= MOD;
    }
    return res % MOD;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    i64 Sum = 0, Max = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        Sum += a[i];
        Max = max(Max, a[i]);
    }
    sort(a + 1, a + 1 + n);
    g[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= Max; j++)
        {
            g[i][j] = (g[i][j] + g[i - 1][j]) % MOD;
            if (j >= a[i])
            {
                g[i][j] = (g[i][j] + g[i - 1][j - a[i]]) % MOD;
            }
        }
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= a[i]; j++)
        {
            f[i] = (f[i] + g[i - 1][j]) % MOD;
        }
    }
    i64 ans = 0;        
    for (int i = 3; i <= n; i++)        
    {
        i64 tot = power(2, i - 1, MOD);
        tot = (tot - f[i] + MOD) % MOD;               
        ans += tot;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
