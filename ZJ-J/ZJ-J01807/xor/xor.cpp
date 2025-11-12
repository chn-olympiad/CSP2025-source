#include <bits/stdc++.h>
namespace Cosh_X
{
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> PII;
    const ll N = 5e5 + 5, INF = 0x3f3f3f3f3f3f3f3f;
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
}
using namespace Cosh_X;
ll n, k, a[N], sum[N], f[N];
map<ll, ll> mx;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    n = read(), k = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read();
    for (ll i = 1; i <= n; i++)
        sum[i] = sum[i - 1] ^ a[i];
    for (ll i = 1; i <= n; i++)
    {
        if ((k ^ sum[i]) && (!mx.count(k ^ sum[i])))
            f[i] = f[i - 1];
        else
            f[i] = max(f[i - 1], mx[k ^ sum[i]] + 1LL);
        mx[sum[i]] = max(mx[sum[i]], f[i]);
    }
    cout << f[n] << '\n';
    return 0;
}

// g++ xor.cpp -std=c++14 -Wall -O2 -o xor