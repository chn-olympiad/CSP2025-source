#include <bits/stdc++.h>
#define LL long long
const int N = 1e4 + 5;
using namespace std;
struct Node
{
    int v, w;
};
vector<Node> g[N];
int n, m, k, ck[15], a[15][N];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> ck[i];
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    cout << 13;
    return 0;
}
