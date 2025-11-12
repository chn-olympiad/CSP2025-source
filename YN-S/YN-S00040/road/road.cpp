#include <bits/stdc++.h>
using namespace std;
const long long maxn = 10010, maxm = 1000010, INF = 9998244353;

long long n, m, k, u, v, w, c[50], a[50][maxn], dis[maxn][maxn], fa[maxn], ans, book[maxn], last[maxn];

struct Edge {
    long long u, v, w;
};

vector<Edge> e;

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void meme(int i)
{
    while (fa[i] != fa[fa[i]])
        fa[i] = fa[fa[i]];
}

int qin()
{
    int x = 0;
    char c;
    c = _getchar_nolock();
    while (c < '0' || c > '9')
        c = _getchar_nolock();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = _getchar_nolock();
    return x;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = qin();
    m = qin();
    k = qin();
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            dis[i][j] = INF;
    for (int i = 1; i <= m; i++)
    {
        u = qin();
        v = qin();
        w = qin();
        e.push_back((Edge) {
            u, v, w
        });
    }
    for (int i = 1; i <= k; i++)
    {
        c[i] = qin();
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = qin();
            e.push_back((Edge) {
                n + i, j, a[i][j] + c[i]
            });
        }
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    sort(e.begin(), e.end(), cmp);
    int cnt = 0, i = 0;
    while (cnt < n + k - 1)
    {
        u = e[i].u, v = e[i].v, w = e[i].w;
        book[u]++;
        book[v]++;
        if (u > n)
            last[u - n] = v;
        if (v > n)
            last[v - n] = u;
        if (fa[u] != fa[v])
        {
            fa[v] = fa[u];
            meme(v);
            ans += w;
            cnt++;
        }
        i++;
    }
    for (int i = 1; i <= k; i++)
    {
        if (book[i + n] % 2 == 1)
            for (int j = last[i]; j >= 1; j--)
                if (book[j] != 1)
                {
                    ans -= (a[i][j] + c[i]);
                    break;
                }
        ans -= book[i + n] / 2 * c[i];
    }

    cout << ans;
    return 0;
}