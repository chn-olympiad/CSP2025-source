#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 5e2 + 10;
constexpr int mod = 998244353;
char s[maxn];
int c[maxn];
int n , m;
int p[maxn];
int ans = 0;
int vis[maxn];
void dfs(int u)
{
    if(u > n)
    {
        int cnt = 0;
        int sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(cnt >= c[p[i]])
            {
                ++cnt;
            }
            else if(s[i] == '0')
            {
                ++cnt;
            }
            else
            {
                ++sum;
            }
        }
        if(sum >= m)
        {
            ++ans;
            ans %= mod;
        }
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(vis[i])
        {
            continue;
        }
        vis[i] = 1;
        p[u] = i;
        dfs(u + 1);
        p[u] = 0;
        vis[i] = 0;
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    #endif // ONLINE_JUDGE

    scanf("%lld%lld",&n,&m);
    scanf("%s",s + 1);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld",c + i);
    }
    dfs(1);
    ans %= mod;
    printf("%lld\n",ans);
    return 0;
}
