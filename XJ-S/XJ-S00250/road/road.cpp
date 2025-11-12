#include <bits/stdc++.h>
#define LL long long
using namespace std;

template <typename type>
inline void read(type &x)
{
    x = 0; static bool flag; flag = 0; char ch = getchar();
    while (!isdigit(ch)) flag = ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    flag ? x = -x : 0;
}

const int N = 1e4 + 5;
const int M = 2e6 + 5;
const LL INF = 1e18 + 7;

int n, m, k;
int fa[N];
LL ans = 0;

int cnt, head[N];
struct edge
{
    int nxt, u, v; LL w;
}e[M];

int getf(int x)
{
    return fa[x] == x ? x : fa[x] = getf(fa[x]);
}

void add_edge(int u, int v, int w)
{
    e[++ cnt].nxt = head[u];
    e[cnt].u = u; e[cnt].v = v; e[cnt].w = w;
    head[u] = cnt;
}

bool cmp(edge A, edge B)
{
    return A.w < B.w;
}
void merge(int x, int y)
{
    int fx = getf(x), fy = getf(y);
    fa[fx] = fy;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    read(n); read(m); read(k);
    for (int i = 1; i <= n; i ++)
        fa[i] = i;
    for (int i = 1; i <= m; i ++)
    {
        int u, v; LL w;
        read(u), read(v), read(w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    sort(e + 1, e + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i ++)
    {
        if (getf(e[i].u) == getf(e[i].v)) continue;
        ans += e[i].w;
        merge(e[i].u, e[i].v);
    }
    printf("%lld\n", ans);
    return 0;//Rem bless
}