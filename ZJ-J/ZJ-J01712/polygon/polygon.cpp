#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 5e3 + 10;
constexpr int mod = 998244353;
int a[maxn];
int vis[maxn];
int ans = 0;
int n;
void dfs(int u)
{
    if(u > n)
    {
        int sum = 0;
        int maxv = 0;
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(vis[i])
            {
                ++cnt;
                sum += a[i];
                maxv = max(maxv , a[i]);
            }
        }
        if(cnt >= 3 && sum > 2 * maxv)
        {
            ++ans;
        }
        return;
    }
    dfs(u + 1);
    vis[u] = 1;
    dfs(u + 1);
    vis[u] = 0;
}
void sub1()
{
    dfs(1);
    printf("%lld\n",ans);
}
int quick_pow(int b , int p)
{
    int ret = 1;
    b %= mod;
    while(p > 0)
    {
        if(p&1)
        {
            ret *= b;
            ret %= mod;
        }
        b *= b;
        b %= mod;
        p >>= 1;
    }
    return ret;
}
void sub2()
{
    int ans = quick_pow(2 , n);
    int c = (n * (n - 1)) / 2;
    ans -= c;
    ans = (ans % mod + mod) % mod;
    printf("%lld\n",ans);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%lld",&n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld",a + i);
    }
    sort(a + 1 , a + n + 1);
    if(n <= 20)
    {
        sub1();
    }
    else if(a[n] == 1)
    {
        sub2();
    }
    return 0;
}
