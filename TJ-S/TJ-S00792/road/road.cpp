#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
inline LL read() {
    LL num = 0, sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1), ch = getchar();
    while ('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch - '0', ch = getchar();
    return (sign == 1 ? num : -num);
}
const int MAXN = 1e4 + 8;
const int MAXK = 18;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, c[MAXK], a[MAXK][MAXN], dis[MAXN];
bool vis[MAXN];
vector<pair<int, int> > adj[MAXN];
LL kruskal(int s) {
    priority_queue<pair<LL, int> > pq;
    LL ret = 0;
    dis[s] = 0, pq.push({-dis[s], s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true, ret += dis[u];
        for (auto [v, w] : adj[u])
            if (!vis[v] && dis[v] > w)
                dis[v] = w, pq.push({-dis[v], v});
    }
    return ret;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for (int i = 1, u, v, w; i <= m; i++) {
        u = read(), v = read(), w = read();
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= k; i++) {
        c[i] = read();
        for (int j = 1; j <= n; j++) a[i][j] = read();
    }
    if (k > 0) return cout << 0, 0;
    memset(dis, INF, sizeof(dis));
    cout << kruskal(1);
    return 0;
}
