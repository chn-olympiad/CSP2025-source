#include <bits/stdc++.h>
using namespace std;
int n,m,k,money[10005],new_edge[10][10005];
int dsu[10005];

int fin(int u) {
    if (dsu[u] == u) return u;
    dsu[u] = fin(dsu[u]);
    return fin(dsu[u]);
}
void unite(int u,int v) {dsu[fin(u)] = fin(v);}
struct Edge
{
    int u,v,w;
}edges[1000005];
bool cmp(Edge x,Edge y) {return x.w < y.w;}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (int i = 1,u,v,w; i <= m; i++)
    {
        cin >> u >> v >> w;
        edges[i].u = u,edges[i].v = v,edges[i].w = w;
    }
    int c = 1,ans = 0;
    sort(edges + 1,edges + m + 1,cmp);

    for (int i = 1,u,v,w; i < n; i++)
    {
        u = edges[c].u,v = edges[c].v,w = edges[c].w;
        while(fin(u) == fin(v)) c++,u = edges[c].u,v = edges[c].v,w = edges[c].w;
        ans += w;
        unite(u,v);
    }
    if (k == 0)
    {
        cout << ans;
        return 0;
    }
    ans = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> money[i];
        int pos;
        for (int j = 1; j <= n; j++)
        {
            cin >> new_edge[i][j];
            if(new_edge[i][j] == 0) pos = j;
        }
        for (int j = 1; j <= n; j++)
        {
            edges[m + (i - 1) * n + j].u = pos,edges[m + (i - 1) * n + j].v = j,edges[m + (i - 1) * n + j].w = new_edge[i][j];
        }
    }
    for (int i = 1; i <= n; i++) dsu[i] = i;
    sort(edges + 1,edges + m + k * n + 1,cmp);
    c = k + 1;
    for (int i = 1,u,v,w; i < n; i++)
    {
        u = edges[c].u,v = edges[c].v,w = edges[c].w;
        while(fin(u) == fin(v)) c++,u = edges[c].u,v = edges[c].v,w = edges[c].w;
        ans += w;
        unite(u,v);
    }
    cout << ans;
    return 0;
}
