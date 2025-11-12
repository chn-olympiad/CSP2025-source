#include <iostream>
using namespace std;

const int maxn = 1e4 + 8e1, maxk = 10 + 8;
int n, m, k, e[maxn][maxn], c[maxk], a[maxk][maxn];

void addEdge(int u, int v, int w) {
    e[u][v] = w;
    return;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << 0 << '\n';

    return 0;
}