#include <bits/stdc++.h>
namespace Cosh_X
{
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> PII;
    const ll N = 3e5 + 5, INF = 0x3f3f3f3f;
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
ll a[N][5], now[N];
bool vis[N];
ll cnt[5], n;
priority_queue<PII> q;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ll _ = read();
    while (_--)
    {
        while (!q.empty())
            q.pop();
        n = read();
        while (!q.empty())
            q.pop();
        ll ans = 0;
        cnt[1] = cnt[2] = cnt[3] = 0;
        for (ll i = 1; i <= n; i++)
        {
            vis[i] = 0;
            a[i][1] = read();
            a[i][2] = read();
            a[i][3] = read();
            ll mxid = 0;
            for (ll j = 1; j <= 3; j++)
            {
                if (a[i][j] > a[i][mxid])
                    mxid = j;
            }
            ans += a[i][mxid];
            cnt[mxid]++;
            now[i] = mxid;
        }
        ll tot = 0, id = 0;
        for (ll i = 1; i <= 3; i++)
        {
            if (cnt[i] > n / 2)
                tot = cnt[i] - (n / 2), id = i;
        }
        if (tot)
        {
            for (ll i = 1; i <= n; i++)
            {
                if (now[i] == id)
                {
                    for (ll j = 1; j <= 3; j++)
                    {
                        if (j != now[i])
                            q.push({-a[i][now[i]] + a[i][j], i});
                    }
                }
            }
        }
        while (tot--)
        {
            if (!vis[q.top().second])
            {
                vis[q.top().second] = 1;
                ans += q.top().first;
            }
            else
                tot++;
            q.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}

// g++ club.cpp -O2 -std=c++14 -Wall -o club