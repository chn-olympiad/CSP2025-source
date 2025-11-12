#include <bits/stdc++.h>
using namespace std;

#define N 20000
#define K 20

long long n, m, k;

map<long long, long long> E[N];
long long c[K];
long long newold[K][N];

long long ans;
bool bis[N];
void dfs_withoutk(long long x)
{
    for (auto i: E[x])
    {
        if (!bis[i.first])
        {
            ans += i.second;
            bis[i.first] = true;
            dfs_withoutk(i.first);
        }
    }
}

void dfs_withk(long long x)
{

}

int main()
{
	freopen("road.in",  "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        E[u][v] = E[v][u] = w;
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", c+i);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &newold[i][j]);
        }
    }
    if (k == 0)
    {
        bis[1] = true;
        dfs_withoutk(1);
        printf("%lld", ans);
        return 0;
    }
    else if (c[1] == 0 && c[2] == 0 && c[3] == 0 && c[4] == 0 && c[5] == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                E[j+n][i] = newold[j][i];
            }
        }
        n += k;
        bis[1] = true;
        dfs_withoutk(1);
        printf("%lld", ans);
        return 0;
    }
	return 0;
}
