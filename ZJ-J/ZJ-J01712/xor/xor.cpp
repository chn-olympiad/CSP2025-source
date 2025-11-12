#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 5e5 + 10;
int a[maxn];
int n , k;
int sum[maxn];
int dp[maxn];
void sub1()
{
    for(int i = 1; i <= n; ++i)
    {
        bool flag = 0;
        int j = lower_bound(dp , dp + i , dp[i - 1]) - dp;
        for(int q = j; q < i; ++q)
        {
            if((sum[i] ^ sum[q]) == k)
            {
                flag = 1;
            }
        }
        dp[i] = max(dp[i] , dp[j] + flag);
        //cerr << dp[i] << " ";
    }
    printf("%lld\n",dp[n]);
}
unordered_map<int,int> vis;
void solve()
{
    vis[k] = 1;
    for(int i = 1; i <= n; ++i)
    {
        int j = lower_bound(dp , dp + i , dp[i - 1]) - dp;
        dp[i] = max(dp[i] , dp[j]);
        if(vis.count(sum[i]))
        {
            dp[i] = max(dp[i] , vis[sum[i]]);
        }
        vis[sum[i] ^ k] = dp[i] + 1;
        //cerr << dp[i] << " ";
    }
    printf("%lld\n",dp[n]);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%lld%lld",&n,&k);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld",a + i);
        sum[i] = sum[i - 1] ^ a[i];
    }
    if(n <= 1000)
    {
        sub1();
    }
    else
    {
        solve();
    }
    return 0;
}
