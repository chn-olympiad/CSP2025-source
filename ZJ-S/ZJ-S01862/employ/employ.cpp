#include <bits/stdc++.h>
namespace Cosh_X
{
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> PII;
    const ll N = 1e4 + 50, M = 998244353, K = 15, INF = 0x3f3f3f3f;
    inline ll read()
    {
        ll x = 0, f;
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
    inline ll qpow(ll a, ll b)
    {
        ll res = 1;
        while (b)
        {
            if (b & 1)
                (res *= a) %= M;
            (a *= a) %= M;
            b >>= 1;
        }
        return res;
    }
}
using namespace Cosh_X;
ll n, m, k;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n = read(), m = read();
    ll fact1 = 1;
    for (ll i = 1; i <= n; i++)
        fact1 = fact1 * i % M;
    cout << fact1 << '\n';
    return 0;
}

// g++ employ.cpp -O2 -std=c++14 -Wall -o employ