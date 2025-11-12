#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int b[10005][10005], a[10005], dist[10005];
long long ans;
bool vis[10005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    memset(b, 127, sizeof(b));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        b[u][v] = w;
        b[v][u] = w;
    }
    for (int i = 1; i <= k; i++) {
        int c;
        scanf("%d", &c);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j]);
            for (int k = 1; k < j; k++) {
                b[j][k] = (int)min(1LL * b[j][k], 1LL * a[j] + a[k] + c);
                b[k][j] = b[j][k];
            }
        }
    }
    vis[1] = true;
    for (int i = 2; i <= n; i++) {
        dist[i] = b[1][i];
    }
    for (int i = 2; i <= n; i++) {
        int mymin = -1, minp = -1;
        for (int j = 2; j <= n; j++) {
            if (!vis[j]) {
                if (dist[j] < mymin || mymin == -1) {
                    mymin = dist[j];
                    minp = j;
                }
            }
        }
        vis[minp] = true;
        ans += mymin;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                dist[j] = min(dist[j], b[minp][j]);
            }
        }

    }
    printf("%lld", ans);
    return 0;
}
