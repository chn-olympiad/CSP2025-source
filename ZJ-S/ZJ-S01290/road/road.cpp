#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e4 + 20, M = 1e6 + 10, K = 20;
struct Edge{
    int a, b, c;
    bool operator < (const Edge &w) const
    {
        return c < w.c;
    }
}e[M];
vector<Edge> vec[K], now;
int n, m, k;
LL ans;
int c[K];
int p[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dfs(int step, LL res)
{
    if(step > k) return;
    dfs(step + 1, res);
    vector<Edge> backup = now, g;
    res += c[step];
    int i = 0, j = 0, sz = now.size();
    while(i < sz || j < n)
    {
        if(i >= sz) g.push_back(vec[step][j]), j ++;
        else if(j >= n) g.push_back(now[i]), i ++;
        else if(vec[step][j] < now[i]) g.push_back(vec[step][j]), j ++;
        else g.push_back(now[i]), i ++;
    }
    now.clear();
    LL ress = res;
    for(int i = 1; i <= n + k; i ++) p[i] = i;
    for(auto x : g)
    {
        int a = x.a, b = x.b, w = x.c;
        a = find(a), b = find(b);
        if(a != b)
        {
            now.push_back(x);
            p[a] = b;
            ress += w;
        }
    }
    ans = min(ans, ress);
    dfs(step + 1, res);
    res -= c[step];
    now = backup;
}

void kruskal()
{
    sort(e + 1, e + 1 + m);
    for(int i = 1; i <= n + k; i ++) p[i] = i;
    for(int i = 1; i <= m; i ++)
    {
        int a = e[i].a, b = e[i].b, w = e[i].c;
        a = find(a), b = find(b);
        if(a != b)
        {
            p[a] = b;
            ans += w;
            now.push_back(e[i]);
        }
    }
}

int read()
{
    int ret = 0;
    char c = getchar();
    while(c > '9' || c < '0') c = getchar();
    while(c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48), c = getchar();
    return ret;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++)
        e[i].a = read(), e[i].b = read(), e[i].c = read();
    for(int i = 1; i <= k; i ++)
    {
        c[i] = read();
        int x;
        for(int j = 1; j <= n; j ++)
        {
            x = read();
            vec[i].push_back({i + n, j, x});
        }
        sort(vec[i].begin(), vec[i].end());
    }
    kruskal();
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}