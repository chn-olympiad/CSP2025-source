#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
typedef long long ll;
#define de(x) cerr << "> line " << __LINE__ << ": " << #x << " = " << x << endl

namespace __dsu_t
{
    int fa[N];
    inline void build(const int &n)
    {
        iota(fa, fa + n + 1, 0);
    }
    int find(int x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
}

struct node
{
    int x, y, w;
    node(int _x = 0, int _y = 0, int _w = 0) : x(_x), y(_y), w(_w) {}
};
inline ll spanTree(vector<node> &g, const int &point_cnt)
{
    sort(g.begin(), g.end(), [&](const node &lhs, const node &rhs)
         { return lhs.w < rhs.w; });
    using namespace __dsu_t;
    build(point_cnt);
    int cnt = 1;
    ll res = 0;
    for (int i = 0; i < (int)g.size(); i++)
    {
        int x = g[i].x, y = g[i].y, w = g[i].w;
        x = find(x);
        y = find(y);
        if (x == y)
            continue;
        fa[y] = x;
        res += w;
        if (++cnt == point_cnt)
            break;
    }
    return res;
}

int id[10];
int n, m, K, c[10], a[10][N];
vector<pair<int, int>> g[N];
int now_chs, col[N];

void dfs(int x, int fa, int w)
{
    int minp = 0;
    for (int i = 1; i < now_chs; i++)
    {
        if (a[id[i]][x] < a[id[minp]][x])
        {
            minp = i;
        }
    }
    if (w > a[id[minp]][x])
        col[x] = minp;
    else
        col[x] = -1;
    for (auto o : g[x])
    {
        int y = o.first;
        if (y == fa)
            continue;
        dfs(y, x, o.second);
    }
}

ll now_minu;
int eg[10][10];
void dfs1(int x, int fa, int w, int C)
{
    if (~col[x])
    {
        C = col[x];
        now_minu += w - a[id[C]][x];
    }
    for (int i = 0; i < now_chs; i++)
    {
        if (i == C)
            continue;
        eg[C][i] = min(eg[C][i], a[id[i]][x]);
    }
    for (auto o : g[x])
    {
        int y = o.first;
        if (y == fa)
            continue;
        dfs1(y, x, o.second, C);
    }
}

pair<int, int> dfs2(int x, int fa)
{
    if (~col[x])
        return {0x3f3f3f3f, -1};
    int minp = 0;
    for (int i = 1; i < now_chs; i++)
    {
        if (a[id[i]][x] < a[id[minp]][x])
        {
            minp = i;
        }
    }
    pair<int, int> res = make_pair(a[id[minp]][x], minp);
    for (auto o : g[x])
    {
        int y = o.first;
        if (y == fa)
            continue;
        res = min(res, dfs2(y, x));
    }
    return res;
}

inline ll solve()
{
    now_minu = 0;
    for (int i = 0; i < now_chs; i++)
    {
        for (int j = 0; j < now_chs; j++)
        {
            eg[i][j] = 0x3f3f3f3f;
        }
    }
    dfs(1, 0, 0);
    col[1] = dfs2(1, 0).second;
    dfs1(1, 0, 0, 0);
    vector<node> e;
    for (int i = 0; i < now_chs; i++)
    {
        for (int j = 0; j < now_chs; j++)
        {
            if (eg[i][j] != 0x3f3f3f3f)
            {
                e.emplace_back(node(i, j, eg[i][j]));
            }
        }
    }
    now_minu -= spanTree(e, now_chs);
    return now_minu;
}

vector<node> e;
ll spanTree0()
{
    sort(e.begin(), e.end(), [&](const node &lhs, const node &rhs)
         { return lhs.w < rhs.w; });
    using namespace __dsu_t;
    build(n);
    int cnt = 1;
    ll res = 0;
    for (int i = 0; i < (int)e.size(); i++)
    {
        int x = e[i].x, y = e[i].y, w = e[i].w;
        x = find(x);
        y = find(y);
        if (x == y)
            continue;
        fa[y] = x;
        res += w;
        g[e[i].x].emplace_back(e[i].y, w);
        g[e[i].y].emplace_back(e[i].x, w);
        if (++cnt == n)
            return res;
    }
    return res;
}

void Main()
{
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1, x, y, w; i <= m; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        e.emplace_back(node(x, y, w));
    }
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &c[i]);
        int p = 0;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                p = j;
        }
        if (c[i] == 0 && p)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == p)
                    continue;
                e.emplace_back(node(p, j, a[i][j]));
            }
            --K, --i;
        }
    }
    ll st = spanTree0();
    ll res = 0;
    for (int S = 1; S < (1 << K); S++)
    {
        now_chs = 0;
        ll sum = 0;
        for (int i = 0; i < K; i++)
        {
            if (S & (1 << i))
            {
                id[now_chs] = i;
                now_chs++;
                sum += c[i];
            }
        }
        res = max(res, solve() - sum);
    }
    printf("%lld\n", st - res);
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    Main();
    return 0;
}