#include <bits/stdc++.h>
// #define int long long
namespace Cosh_X
{
    using namespace std;
    typedef long long ll;
    typedef pair<int, int> PII;
    const int N = 5e3 + 5, INF = 0x3f3f3f3f, M = 998244353;
    inline int read()
    {
        int x = 0, f;
        char ch = getchar();
        while (!isdigit(ch) && ch != '-')
            ch = getchar();
        f = (ch == '-' ? (ch = getchar(), -1) : 1);
        while (isdigit(ch))
        {
            x = (x << 1) + (x << 3) + ch - '0';
            ch = getchar();
        }
        return x * f;
    }
    inline int qpow(int a, int b)
    {
        int res = 1;
        while (b)
        {
            if (b & 1)
                res = (1ll * res * a) % M;
            a = (1ll * a * a) % M;
            b >>= 1;
        }
        return res;
    }
}
using namespace Cosh_X;
int n, a[N], sum = 0, f[N][N], cnt[N], pow1[N], fact[N], factinv[N];
inline void init()
{
    pow1[0] = fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pow1[i] = (1ll * pow1[i - 1] * 2) % M;
        fact[i] = (1ll * fact[i - 1] * i) % M;
    }
    factinv[N - 1] = qpow(fact[N - 1], M - 2);
    for (int i = N - 2; i; i--)
        factinv[i] = (1ll * factinv[i + 1] * (i + 1)) % M;
}
inline int C(int n, int m)
{
    if (n < m)
        return 0;
    if (n == m)
        return 1;
    return (1ll * fact[n] * factinv[n - m] % M * 1ll * factinv[m] % M);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = read();
    init();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        cnt[a[i]]++;
        sum = max(sum, a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        // cerr << a[i] << ' ';
        for (int j = 0; j <= sum; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] > j)
                f[i][j] = (0ll + f[i][j] + pow1[i - 1]) % M;
            else
                f[i][j] = (0ll + f[i][j] + f[i - 1][j - a[i]]) % M;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i += cnt[a[i]])
    {
        ans = (0ll + ans + (1ll * cnt[a[i]] * f[i - 1][a[i]] % M)) % M;
        // cerr << i << ' ' << f[i - 1][a[i]] << '\n';
        for (int k = 2; k <= cnt[a[i]]; k++)
        {
            // cerr << k << ' ' << C(cnt[a[i]], k) << ' ' << pow1[i - 1] << ' ' << '\n';
            ans = (0ll + ans + (1ll * C(cnt[a[i]], k) * (k == 2 ? pow1[i - 1] - 1 : pow1[i - 1]) % M)) % M;
        }
        // cerr << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}

// g++ polygon.cpp -std=c++14 -Wall -O2 -o polygon