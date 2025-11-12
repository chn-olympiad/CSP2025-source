#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 10020;

struct Edge { int u, v, w; } e[1000010], E[20][N], e1[20][N];

int n, m, K, fa[N], cnt[20], c[20];
int nm[20];
LL Ans = 1e18;

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int u, int dep, LL ans, LL bs) {
    Ans = min(Ans, ans + bs);
    // cout << "cnt[dep] = " << cnt[dep] << " u = " << u << " dep = " << dep << endl;
    // if (cnt[dep] != n - 1 + dep) {
        
    //     // for (int i = 1; i <= cnt[dep]; i++)
    //     //     cout << "u = " << E[dep][i].u << " v = " << E[dep][i].v << " w = " << E[dep][i].w << endl;
    //     cout << "qwq" << endl; exit(0);
    // }
    // if (cnt[dep] <= 2) {
    //     exit(0);
    // }
    
    // if (u == K + 1) {
    //     Ans = min(Ans, ans); return;
    // }
    for (int i = u; i <= K; i++) {
        int c1 = 1, c2 = 1;
        for (int j = 1; j <= n + K; j++)
            fa[j] = j;
        LL res = 0; cnt[dep + 1] = 0;
        while (c1 <= cnt[dep] || c2 <= n) {
            if (c2 > n || c1 <= cnt[dep] && E[dep][c1].w < e1[i][c2].w) {
                int x = find(E[dep][c1].u), y = find(E[dep][c1].v);
                if (x != y) {
                    fa[x] = y, res += E[dep][c1].w;
                    E[dep + 1][++cnt[dep + 1]] = E[dep][c1];
                } 
                c1++;
            } else {
                int x = find(e1[i][c2].u), y = find(e1[i][c2].v);
                if (x != y) {
                    fa[x] = y, res += e1[i][c2].w; 
                    E[dep + 1][++cnt[dep + 1]] = e1[i][c2];
                }
                c2++;
            }
        }
        dfs(i + 1, dep + 1, res, bs + c[i]);
    }

}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // int st = clock();
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++) {
            int x; scanf("%d", &x);
            e1[i][j] = {n + i, j, x};
            // scanf("%d", &a[i][j]);
        }
        sort(e1[i] + 1, e1[i] + n + 1, cmp);
    }
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    LL ans = 0;
    for (int i = 1; i <= m; i++) {
        int u = find(e[i].u), v = find(e[i].v);
        if (u != v) {
            E[0][++cnt[0]] = {e[i].u, e[i].v, e[i].w};
            fa[u] = v; ans += e[i].w;
        }
    }
    // cout << "ans = " << ans << endl;
    dfs(1, 0, ans, 0);
    printf("%lld\n", Ans);
    // cout << "time = " << clock() - st << endl;
    return 0;
}