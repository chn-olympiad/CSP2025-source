#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppllpll;
const int MAXN = 1e5+5;

int n;
pll a[MAXN][5];
ppllpll b[MAXN];
pll sta[5][MAXN];
int wb[5];
int to[5];
ll ans;

inline void solve()
{
    ans = 0;
    memset(wb, 0, sizeof wb);
    to[1] = to[2] = to[3] = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &a[i][1].first, &a[i][2].first, &a[i][3].first);
        a[i][1].second = 1, a[i][2].second = 2, a[i][3].second = 3;
        sort(a[i] + 1, a[i] + 4, greater<pll>() );
        b[i].second = a[i][1];
        b[i].first = pll(a[i][1].first - a[i][2].first, a[i][2].second);
        ans += a[i][1].first;
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++)
    {
        int cur = b[i].second.second;
        if(wb[cur] - to[cur] + 1 >= n/2)
        {
            ans -= sta[cur][to[cur]].first;
            to[cur]++;
        }
        sta[cur][++wb[cur]] = b[i].first;
    }
    printf("%lld\n", ans);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(; T--; ) solve();


    return 0;
}