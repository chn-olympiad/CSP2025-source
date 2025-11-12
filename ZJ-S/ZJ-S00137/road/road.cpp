#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e4 + 5;
struct Edge
{
    i64 u, v, w;
};
struct Node
{
    i64 v, w;
};
int n, m, k;
vector<Node> adj[N];
vector<Edge> NG;
int c[15], cost[15][N];
int fa[N];
int get(int x)
{
    if (x == fa[x]) 
    {
        return x;
    }
    int root = get(fa[x]);
    fa[x] = root;
    return root;
}
i64 ans = 0x3f3f3f3f3f3f3f3f;
void solve(int k)
{
    i64 awa = 0;
    vector<Edge> G;
    G = NG;
    int cnt = 0;
    for (int bit = 0, i = n + 1; bit <= log2(k); bit++, i++)
    {
        if ((k >> bit) & 1)
        {
            cnt++;
            for (int j = 1; j <= n; j++)
            {
                G.push_back({i, j, cost[i - n][j]});
            }
            awa += c[i - n];
        }
    }
    n += cnt;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    sort(G.begin(), G.end(), [](Edge a, Edge b)
    {
        return a.w < b.w;
    });
    i64 tot = 0, sum = 0;
    for (auto e : G)
    {
        int u = e.u, v = e.v, w = e.w;
        int x = get(u), y = get(v);
        if (x != y)
        {
            fa[x] = y;
            tot++;
            sum += w;
        }
        if (tot == n - 1)
        {
            ans = min(ans, sum + awa);
            return;
        }
    }
}
void solve0()
{
    i64 awa = 0;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    sort(NG.begin(), NG.end(), [](Edge a, Edge b)
    {
        return a.w < b.w;
    });
    i64 tot = 0, sum = 0;
    for (auto e : NG)
    {
        int u = e.u, v = e.v, w = e.w;
        int x = get(u), y = get(v);
        if (x != y)
        {
            fa[x] = y;
            tot++;
            sum += w;
        }
        if (tot == n - 1)
        {
            ans = min(ans, sum + awa);
            return;
        }
    }
}
void spec()
{
    vector<Edge> G;
    G = NG;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            G.push_back({i + n, j, cost[i][j]});
        }
    }
    n += k;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    sort(G.begin(), G.end(), [](Edge a, Edge b)
    {
        return a.w < b.w;
    });
    i64 tot = 0, sum = 0;
    for (auto e : G)
    {
        int u = e.u, v = e.v, w = e.w;
        int x = get(u), y = get(v);
        if (x != y)
        {
            fa[x] = y;
            tot++;
            sum += w;
        }
        if (tot == n - 1)
        {
            ans = min(ans, sum);
            return;
        }
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        NG.push_back({u, v, w});
    }
    i64 sum = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
        sum += c[i];
    }
    if (k == 0)
    {
        solve0();
        cout << ans << endl;
        return 0;
    }
    if (sum == 0)
    {
        spec();
        cout << ans << endl;
        return 0;
    }
    if (k <= 5)
    {
        for (int i = 0; i <= (1 << (k)) - 1; i++)
        {
            solve(i);
        }
    }
    else
    {
        srand(time(0));
        for (int i = 1; i <= 5; i++)
        {
            int bit = rand() % (1 << k);
            solve(bit);
        }
    }
    cout << ans << endl;
    return 0;
}