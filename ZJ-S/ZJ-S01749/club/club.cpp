#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 1e5 + 10;
constexpr int maxk = 1e1 + 10;
int a[maxn][maxk];
int choice[maxn];
int cnt[maxk];
int n;
int ans = 0;
void dfs(int u)
{
    for(int i = 1; i <= 3; ++i)
    {
        if(cnt[i] > n / 2)
        {
            return;
        }
    }
    if(u > n)
    {
        int sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            sum += a[i][choice[i]];
        }
        //cerr << sum << endl;
        ans = max(ans , sum);
        return;
    }
    for(int i = 1; i <= 3; ++i)
    {
        choice[u] = i;
        ++cnt[i];
        dfs(u + 1);
        --cnt[i];
        choice[u] = 0;
    }
}
void sub1()
{
    ans = 0;
    dfs(1);
    printf("%lld\n",ans);
}
int x[maxn];
void subA()
{
    for(int i = 1; i <= n; ++i)
    {
        x[i] = a[i][1];
    }
    sort(x + 1 , x + n + 1);
    reverse(x + 1 , x + n + 1);
    ans = 0;
    for(int i = 1; i <= n / 2; ++i)
    {
        ans += a[i][1];
    }
    printf("%lld\n",ans);
}
typedef struct t
{
    int a , b , id;
    bool operator<(const t &x) const
    {
        return this->a - this->b < x.a - x.b;
    }
}t;
t b[maxn];
void subB()
{
    ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        b[i].a = a[i][1];
        b[i].b = a[i][2];
        b[i].id = i;
    }
    sort(b + 1 , b + n + 1);
    reverse(b + 1 , b + n + 1);
    for(int i = 1; i <= n; ++i)
    {
        if(i <= n / 2)
        {
            ans += a[b[i].id][1];
        }
        else
        {
            ans += a[b[i].id][2];
        }
    }
    printf("%lld\n",ans);
}
int vis[maxn];
void solve()
{
    ans = 0;
    memset(vis , 0 , sizeof(vis));
    for(int i = 1; i <= n; ++i)
    {
        b[i].a = a[i][1];
        b[i].b = max(a[i][2] , a[i][3]);
        b[i].id = i;
    }
    sort(b + 1 , b + n + 1);
    reverse(b + 1 , b + n + 1);
    for(int i = 1; i <= n / 2 && b[i].a > b[i].b; ++i)
    {
        ans += a[b[i].id][1];
        vis[b[i].id] = 1;
    }
    for(int i = 1; i <= n; ++i)
    {
        b[i].a = a[i][2];
        b[i].b = max(a[i][1] , a[i][3]);
        b[i].id = i;
    }
    sort(b + 1 , b + n + 1);
    reverse(b + 1 , b + n + 1);
    for(int i = 1; i <= n / 2 && b[i].a > b[i].b; ++i)
    {
        ans += a[b[i].id][2];
        vis[b[i].id] = 1;
    }
    for(int i = 1; i <= n; ++i)
    {
        b[i].a = a[i][3];
        b[i].b = max(a[i][2] , a[i][1]);
        b[i].id = i;
    }
    sort(b + 1 , b + n + 1);
    reverse(b + 1 , b + n + 1);
    for(int i = 1; i <= n / 2 && b[i].a > b[i].b; ++i)
    {
        ans += a[b[i].id][3];
        vis[b[i].id] = 1;
    }
    int maxv = 0;
    int max2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            maxv = 0;
            max2 = 0;
            for(int j = 1; j <= 3; ++j)
            {
                if(a[i][j] >= maxv)
                {
                    max2 = maxv;
                    maxv = a[i][j];
                }
                else if(a[i][j] >= max2)
                {
                    max2 = a[i][j];
                }
            }
            ans += max2;
        }
    }
    printf("%lld\n",ans);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    #endif // ONLINE_JUDGE
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        bool suba = 1;
        bool subb = 1;
        scanf("%lld",&n);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= 3; ++j)
            {
                scanf("%lld",&a[i][j]);
                if(j == 2 || j == 3)
                {
                    if(a[i][j] != 0)
                    {
                        suba = 0;
                    }
                }
                if(j == 3)
                {
                    if(a[i][j] != 0)
                    {
                        subb = 0;
                    }
                }
            }
        }
        ans = 0;
        if(n <= 10)
        {
            sub1();
        }
        else if(suba)
        {
            subA();
        }
        else if(subb)
        {
            subB();
        }
        else
        {
            solve();
        }
    }
    return 0;
}
