#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 20;

struct Edge {
    int v, w;
};

struct Node {
    int v, dis, w;
    bool operator<(const Node Y) const {
        return dis > Y.dis;
    }
};

int n, m, k;
int c[K];

vector<Edge> e[N + K*2];

bool vis[N + K*2];
LL prim(int s)
{
    LL ans = 0;

    for(int i=1;i <= n+k*2;i++)
    {
        vis[i] = 0;
    }
    priority_queue<Node> Q;
    Q.push({s, 0, 0});

    while(!Q.empty())
    {
        int u = Q.top().v;
        int dis = Q.top().dis;
        int w = Q.top().w;
        Q.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        ans += w;

        for(auto v : e[u])
        {
            Q.push({v.v, dis+v.w, v.w});
        }
    }
    return ans;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for(int i=1;i <= m;i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    printf("%lld\n", prim(1));

    return 0;
}