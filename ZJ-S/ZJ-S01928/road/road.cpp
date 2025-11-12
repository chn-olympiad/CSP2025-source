#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
    int x = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar());
    for(; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + (c ^ 48);
    return x;
}
ll readl()
{
    ll x = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar());
    for(; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + (c ^ 48);
    return x;
}
const int N = 1e4, M = 1e6;
struct edge
{
    int u, v;
    ll w;
}a[M + M + 5], aa[M + M + 5];
int n, m, k;
struct node
{
    ll c, w[N + 5];
}b[14];
bool cmpA(edge a, edge b)
{
    return a.w < b.w;
}
int f[N + 5];
int find(int x)
{
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}
int cnt = 0;
ll kruskar()
{
    ll ans = 0;
    sort(a + 1, a + 1 + m, cmpA);
    for(int i = 1; i <= n + cnt; i++)
        f[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int x = a[i].u, y = a[i].v, w = a[i].w;
        int xx = find(x), yy = find(y);
        if(xx == yy)
            continue;
        ans += w;
        f[xx] = yy;
    }
    return ans;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    bool A = 1;
    n = read(), m = read(), k = read();
    // scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++)
    {
        a[i].u = read(), a[i].v = read(), a[i].w = readl();
        // scanf("%d%d%lld", &a[i].u, &a[i].v, &a[i].w);
        aa[i] = a[i];
    }
    for(int i = 1; i <= k; i++)
    {
        b[i].c = readl();
        // scanf("%lld", &b[i].c);
        if(b[i].c != 0) A = 0;
        for(int j = 1; j <= n; j++)
            b[i].w[j] = readl();
            // scanf("%lld", &b[i].w[j]);
    }
    if(k == 0)
    {
        ll ans = kruskar();
        printf("%lld\n", ans);
    }
    else if(A)
    {
        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j <= n; j++)
                a[++m] = {i + n, j, b[i].w[j]};
        }
        cnt = k;
        ll ans = kruskar();
        printf("%lld\n", ans);
    }
    else
    {
        ll ans = LONG_LONG_MAX;
        int M = m;
        for(int st = 0; st < (1 << k); st++)
        {
            ll now = 0;
            cnt = 0;
            memset(f, 0, sizeof(f));
            memset(a, 0, sizeof(a));
            for(int i = 1; i <= n; i++)
                f[i] = i;
            m = M;
            for(int i = 1; i <= m; i++)
                a[i] = aa[i];
            for(int i = 1; i <= k; i++)
            {
                if((st & (1 << (i - 1))) == 0) continue;
                cnt++;
                now = now + b[i].c;
                for(int j = 1; j <= n; j++)
                    a[++m] = {i + n, j, b[i].w[j]};
            }
            now += kruskar();
            ans = min(ans, now);
            // printf("%d:%d\n", st, now);
        }
        printf("%lld\n", ans);
    }
    return 0;
}