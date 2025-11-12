#include <bits/stdc++.h>
#define maxn 10010
#define maxm 1000010
#define ll long long
using namespace std;

int n, m, k;
struct Edge
{
    int u, v;
    ll w;
}e[maxm];
int fa[maxn];
ll ans;
int nxt[maxn * 2], to[maxn * 2], h[maxn * 2], tot;
ll val[maxn * 2];
ll f[maxn][maxn];
ll c[20], a[maxn][20];

void add(int u, int v, ll w)
{
    to[++tot] = v;
    nxt[tot] = h[u];
    h[u] = tot;
    val[tot] = w;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int cha_find(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = cha_find(fa[x]);
}

void Kruskal()
{
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }

    int cnt = 0;
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1; i <= m; i++)
    {
        int u = cha_find(e[i].u), v = cha_find(e[i].v);
        if(u == v) continue;

        fa[u] = v;
        ans += e[i].w;
        cnt++;
        if(cnt == n - 1) return;
    }
}


int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    if(k <= 0)
    {
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
        }

        Kruskal();

        printf("%lld", ans);
    }
    else
    {
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            ll w;
            scanf("%d%d%lld", &u, &v, &w);
            add(u, v, w), add(v, u, w);
        }
        for(int j = 1; j <= k; j++)
        {
            scanf("%lld", &c[j]);
            for(int i = 1; i <= n; i++)
            {
                scanf("%lld", &a[i][j]);
            }
        }

        for(int u = 1; u <= n; u++)
        {
            f[u][1] = val[h[u]];
        }

        for(int u = 1; u <= n; u++)
        {
            for(int i = h[u]; i; i = nxt[i])
            {
                int v = to[i];
            }
        }
    }

    return 0;
}
