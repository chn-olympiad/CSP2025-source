#define file_io(id) do { \
	freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); } while(false)
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6 + 10;

struct edge {
    int to;
    int weight;
    int nxt;
};

int n, m, k, c[MAXN];
int cnt = 0, head[MAXN], dis[MAXN];
bool vis[MAXN];
edge e[MAXN];
long long ans = 0;

void add(int u, int v, int w) {
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    e[cnt].weight = w;
    head[u] = cnt;
}

void prim() {
    fill(dis + 1, dis + n + 1, 0x3f3f3f3f);
    dis[1] = 0;

    int marked = 0;
    while (true) {
        if (marked == n) break;
        int min_dis = 0x3f3f3f3f, u;
        for (int i = 1; i <= n; i++)
            if (dis[i] < min_dis && !vis[i]) min_dis = dis[i], u = i;
        vis[u] = true, marked++;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (vis[v]) continue;
            if (e[i].weight < dis[v])
                dis[v] = e[i].weight;
        }
    }

    ans = accumulate(dis + 1, dis + n + 1, 0);
}

int main() {
	file_io("road");
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }

    prim();

    cout << ans << endl;
	return 0;
}
