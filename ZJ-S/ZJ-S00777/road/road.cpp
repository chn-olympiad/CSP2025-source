#include <bits/stdc++.h>

const int N = 1e4, M = 1e6, K = 10;
int n, m, k;
int fa[N + 5], c[K + 5], a[K + 5][N + 5], ca[(1 << K) + 5], lg[(1 << K) + 5];
long long re[(1 << K) + 5];

struct edge {
    int u, v, w;

    bool operator < (const edge &x) const {
        return w < x.w;
    }
} e[M + 5], tmp[N * K + 5], es[(1 << K) + 5][N + K + 5];

void init() {
    for (int i = 1; i <= n + k; ++ i) {
        fa[i] = i;
    }
    return;
}

int Fa(int u) {
    if (fa[u] == u) {
        return u;
    }
    return fa[u] = Fa(fa[u]);
}

long long solve(int S) {
    long long res = 0;
    memcpy(tmp + 1, e + 1, sizeof(edge) * (n - 1));
    int cn = n, Ca = 0;
    for (int i = 0; i < k; ++ i) {
        if (S & (1 << i)) {
            ++ Ca;
            res += c[i + 1];
            for (int j = 1; j <= n; ++ j) {
                tmp[cn].u = j;
                tmp[cn].v = n + i + 1;
                tmp[cn].w = a[i + 1][j];
                ++ cn;
            }
        }
    }

    std::sort(tmp + 1, tmp + cn);
    int cnt = 0;
    init();
    for (int i = 1; i < cn && cnt < n + Ca - 1; ++ i) {
        int u = tmp[i].u, v = tmp[i].v, w = tmp[i].w;
        int U = Fa(u), V = Fa(v);
        if (U == V) {
            continue;
        }

        fa[U] = V;
        res += w;
        ++ cnt;
    }
    return res;

    /*
    int T = S ^ (S & -S), j = lg[S & -S] + 1;
    re[S] = re[T] + c[j];
    long long res = re[S];
    ca[S] = ca[T] + 1;
    memcpy(tmp + 1, es[T] + 1, sizeof(edge) * (n + ca[T] - 1));
    int cn = n + ca[T] - 1;
    for (int i = 1; i <= n; ++ i) {
        ++ cn;
        tmp[cn].u = i;
        tmp[cn].v = n + j;
        tmp[cn].w = a[j][i];
    }

    std::sort(tmp + 1, tmp + cn + 1);
    int cnt = 0;
    init();
    for (int i = 1; i <= cn && cnt < n + ca[S] - 1; ++ i) {
        int u = tmp[i].u, v = tmp[i].v, w = tmp[i].w;
        int U = Fa(u), V = Fa(v);
        if (U == V) {
            continue;
        }

        fa[U] = V;
        res += w;
        ++ cnt;
    }
    return res;
    */
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++ i) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }

    for (int j = 1; j <= k; ++ j) {
        lg[1 << (j - 1)] = j - 1;
        scanf("%d", &c[j]);
        for (int i = 1; i <= n; ++ i) {
            scanf("%d", &a[j][i]);
        }
    }

    std::sort(e + 1, e + m + 1);
    int cnt = 0;
    long long ans = 0;
    init();
    for (int i = 1; i <= m && cnt < n - 1; ++ i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int U = Fa(u), V = Fa(v);
        if (U == V) {
            continue;
        }

        fa[U] = V;
        ans += w;
        ++ cnt;
        e[cnt] = e[i];
    }

    for (int S = 1; S < 1 << k; ++ S) {
        ans = std::min(ans, solve(S));
    }

    printf("%lld\n", ans);
    return 0;
}

