#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

const int N = 10015, M = 2000005;
Edge e [M], ee [M], eee [15][N], tmp [15][M];
int fa [N], siz [N];
int c [15], a [15][N];
int n, m, k;
long long ans = 9e18;

bool cmp (Edge a, Edge b)
{
    return a.w < b.w;
}

int find (int u)
{
    if (fa [u] == u)
    {
        return u;
    }
    return fa [u] = find (fa [u]);
}

bool merge (int u, int v)
{
    u = find (u), v = find (v);
    if (u == v)
    {
        return 1;
    }
    if (siz [u] < siz [v])
    {
        swap (u, v);
    }
    fa [v] = u;
    siz [u] += siz [v];
    return 0;
}

long long kruska ()
{
    for (int i = 1; i <= n + k; i++)
    {
        fa [i] = i;
        siz [i] = 1;
    }
    long long ret = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!merge (ee [i].u, ee [i].v))
        {
            ret += ee [i].w;
        }
    }
    return ret;
}

void dfs (int step, long long sum)
{
    if (step > k)
    {
        ans = min (ans, sum + kruska ());
        return ;
    }
    int ttp = m;
    for (int i = 1; i <= m; i++)
    {
        tmp [step][i] = ee [i];
    }
    int l = 1, r = 1, cur = 0;
    while (l <= m && r <= n)
    {
        if (tmp [step][l].w < eee [step][r].w)
        {
            ee [++cur] = tmp [step][l];
            l++;
        }
        else
        {
            ee [++cur] = eee [step][r];
            r++;
        }
    }
    while (l <= m)
    {
        ee [++cur] = tmp [step][l];
        l++;
    }
    while (r <= n)
    {
        ee [++cur] = eee [step][r];
        r++;
    }
    m = cur;
    dfs (step + 1, sum + c [step]);
    m = ttp;
    for (int i = 1; i <= m; i++)
    {
        ee [i] = tmp [step][i];
    }
    dfs (step + 1, sum);
}

int main ()
{
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf ("%d%d%d", &e [i].u, &e [i].v, &e [i].w);
    }
    sort (e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        ee [i] = e [i];
    }
    for (int i = 1; i <= k; i++)
    {
        scanf ("%d", c + i);
        for (int j = 1; j <= n; j++)
        {
            eee [i][j] = Edge {i + n, j, 0};
            scanf ("%d", &eee [i][j].w);
        }
        sort (eee [i] + 1, eee [i] + n + 1, cmp);
    }
    dfs (1, 0);
    printf ("%lld\n", ans);
    return 0;
}