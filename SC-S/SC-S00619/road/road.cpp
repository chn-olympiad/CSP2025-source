#include <cstdio>
#include <vector>
#include <algorithm>

const long long N = 1e4 + 10, M = 20, Inf = 1e18;

struct Edge {
    long long u, v, w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};

std :: vector <Edge> E;
long long n, m, k, cnt, c[M], a[M][N], fa[N];

void read(long long &p) {
    p = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') p = (p << 3) + (p << 1) + c - '0', c = getchar();
    return ;
}

long long find(long long x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(long long a, long long b) {
    fa[find(a)] = find(b);
    return ;
}

long long Kruscal() {
    long long res = 0;
    for (auto e : E) {
        long long u = e.u, v = e.v, w = e.w;
        if (find(u) != find(v)) {
            merge(u, v);
            res += w;
            if (++ cnt >= n - 1) break;
        }
    }
    return res;
}

int main() {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    read(n), read(m), read(k);
    for (long long i = 1; i <= n + k; i ++) fa[i] = i;
    for (long long i = 1; i <= m; i ++) {
        long long u, v, w;
        read(u), read(v), read(w);
        E.push_back({u, v, w});
    }

    bool flag = true;
    for (long long i = 1; i <= k; i ++) {
        read(c[i]);
        if (c[i]) flag = false;
        for (long long j = 1; j <= n; j ++) {
            read(a[i][j]);
            if (!a[i][j]) merge(j, i + n);
        }
    }

    long long ans;
    if (flag) {

        for (long long i = 1; i <= k; i ++)
            for (long long j = 1; j < n; j ++)
                for (long long p = j + 1; p <= n; p ++)
                    E.push_back({j, p, a[i][j] + a[i][p]});

        std :: sort(E.begin(), E.end());

        ans = Kruscal();
    } else {
        std :: sort(E.begin(), E.end());
        ans = Kruscal();
    }

    printf("%lld\n", ans);

    return 0;
}