#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 1e4 + 5;

struct Edge {
    int u, v;
    i64 w;
};

struct To {
    int v;
    i64 w;
};

int n, m, k, fa[N];
i64 c[15];
To a[15][N];
std::vector<Edge> e[1030], tmp;

int find(int x) {
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c ^ 48);
        c = getchar();
    }
    return x;
}

void sol() {
    // clock_t begin = clock();
    std::cin >> n >> m >> k;
    // n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        // u = read(), v = read(), w = read();
        tmp.push_back(Edge{u, v, w});
    }

    std::sort(tmp.begin(), tmp.end(), [] (const Edge &lhs, const Edge &rhs) -> bool {
        return lhs.w < rhs.w;
    });

    i64 ans = 0, cnt = 0;
    for (auto i : tmp) {
        int u = i.u, v = i.v;
        i64 w = i.w;
        if (find(u) == find(v)) continue;
        cnt++;
        fa[find(u)] = find(v);
        ans += w;
        e[0].push_back(Edge{u, v, w});
        if (cnt == n - 1) break;
    }

    for (int i = 1; i <= k; i++) {
        std::cin >> c[i];
        // c[i] = read();
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j].w;
            // a[i][j].w = read();
            a[i][j].v = j;
        }
        std::sort(a[i] + 1, a[i] + n + 1, [] (const To &lhs, const To &rhs) -> bool {
            if (lhs.w != rhs.w) return lhs.w < rhs.w;
            return lhs.v < rhs.v;
        });
    }

    for (int K = 1; K < (1 << k); K++) {
        int pK = K - (K & -K);
        std::vector<Edge> E(0);
        for (int i = 1; i <= n + k; i++) {
            fa[i] = i;
        }
        i64 res = 0, cnt = 0;
        int popc = 0;
        for (int i = 1; i <= k; i++) {
            if ((K >> (i - 1)) & 1) {
                popc++;
                res += c[i];
                if ((1 << (i - 1)) != (K & -K)) continue;
                for (int j = 1; j <= n; j++) {
                    E.push_back(Edge{n + i, a[i][j].v, a[i][j].w});
                }
            }
        }

        for (int i = 0, j = 0; i < (int)e[pK].size() || j < (int)E.size();) {
            int u, v;
            i64 w;
            if (j == (int)E.size() || e[pK][i].w < E[j].w) u = e[pK][i].u, v = e[pK][i].v, w = e[pK][i].w, i++;
            else u = E[j].u, v = E[j].v, w = E[j].w, j++;
            if (find(u) == find(v)) continue;
            res += w;
            cnt++;
            fa[find(u)] = find(v);
            e[K].push_back(Edge{u, v, w});
            if (cnt == n + popc - 1) break;
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << "\n";

    // clock_t end = clock();
    // std::cout << 1. * (end - begin) / CLOCKS_PER_SEC << "\n";
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // init();
    int T = 1;
    // std::cin >> T;
    while (T--) sol();
    return 0;
}