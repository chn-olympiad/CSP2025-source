#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 100005;
ll T , n , a[N][3] , id[N] , cnt[3];
vector<ll> v;

signed main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld" , &T);
    while(T--)
    {
        scanf("%lld", &n);
        ll ans = 0;
        memset(cnt, 0, sizeof cnt);
        for(ll i = 1 ; i <= n ; i++) for (ll j = 0; j < 3; j++) cin >> a[i][j];
        for (ll i = 1; i <= n ; i++)
        {
            ll mx = -1;
            for (ll j = 0; j < 3; j++)
            {
                if(a[i][j] > mx)
                    mx = a[i][j], id[i] = j;
            }
            ans += mx;
            cnt[id[i]]++;
        }
        ll num = 0;
        for (ll i = 0; i < 3; i++) if(cnt[i] > (n >> 1)) num = i;
        for (ll i = 1; i <= n ; i++) if(id[i] == num)
        {
            v.push_back(min(a[i][id[i]] - a[i][(id[i] + 1) % 3] , a[i][id[i]] - a[i][(id[i] + 2) % 3]));
        }
        sort(v.begin(), v.end()); ll pos = 0;
        while(cnt[num] > (n >> 1)) ans -= v[pos++] , cnt[num]--;
        printf("%lld\n", ans);
    }
    return 0;
}
