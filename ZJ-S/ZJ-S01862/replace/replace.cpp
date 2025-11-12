#include <bits/stdc++.h>
namespace Cosh_X
{
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> PII;
    const ll N = 5e6 + 5, Base = 113, M = 998244353, INF = 0x3f3f3f3f;
}
using namespace Cosh_X;
ll pow1[N];
ll n, q, L, len[N], h1[N], h2[N];
unordered_multimap<ll, PII> mp;
inline void init()
{
    pow1[0] = 1;
    for (ll i = 1; i < N; i++)
        pow1[i] = (pow1[i - 1] * Base) % M;
}
inline ll get_hash(string s, ll h[])
{
    ll ans = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        ans = (ans * Base + s[i]) % M;
        h[i] = ans;
    }
    return ans;
}
inline ll get(ll l, ll r, ll h[])
{
    if (l > r)
        return 0;
    return (h[r] - ((l == 0 ? 0 : h[l - 1]) * pow1[r - l + 1] % M) + M) % M;
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    init();
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        L += s1.length() + s2.length();
        len[i] = s1.length();
        mp.insert({get_hash(s1, h1), {get_hash(s2, h2), len[i]}});
    }
    // if (n <= 1000 && L <= 2000)
    // {
    while (q--)
    {
        ll ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        get_hash(t1, h1);
        get_hash(t2, h2);
        for (auto it : mp)
        {
            ll s1 = it.first, s2 = it.second.first;
            for (ll l = 0; l + it.second.second - 1 < t1.length(); l++)
            {
                ll r = l + it.second.second - 1;
                if (get(l, r, h1) == s1 && get(l, r, h2) == s2 && get(0, l - 1, h1) == get(0, l - 1, h2) && get(r + 1, t1.length() - 1, h1) == get(r + 1, t1.length() - 1, h2))
                    ans++;
            }
        }
        cout << ans << '\n';
    }
    // }
    return 0;
}

// g++ replace.cpp -O2 -std=c++14 -Wall -o replace