#include <cstdio>
#include <algorithm>
using namespace std;
struct IO {
    IO () {
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;
const int M = 1.5e6 + 9;
const int N = 1e4 + 9;
typedef long long ll;
int n, m, k, cnt, tmp;
int fa[N], c[N], a[N][15];
struct Edge {
    int u, v, w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
} e[M];
int find (int u) {
    if (fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}
bool merge (int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return 0;
    fa[v] = u;
    return 1;
}
ll getAns () {
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(e + 1, e + cnt + 1);
    int tmp = 0; ll ans = 0;
    for (int i = 1; i <= cnt; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (merge(u, v)) ans += w, ++tmp;
        if (tmp == n - 1) break;
    }
    return ans;
}
int read () {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c <= '9' && c >= '0') x = x * 10 + c - '0', c = getchar();
    return x;
}
int main () {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        e[++cnt] = {u, v, w};
    }
    if (k == 0) {
        printf("%lld\n", getAns());
        return 0;
    }
    bool f = 0;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]), f |= c[i];
        int idx = 0;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j][i]);
            if (a[j][i] == 0) idx = j;
        }
        if (c[i] == 0) {
            for (int j = 1; j <= n; j++)
                if (j != idx)
                    e[++cnt] = {j, idx, a[j][i]};
        }
    }
    if (!f) {
        printf("%lld\n", getAns());
        return 0;
    }
    cnt = m;
    printf("%lld\n", getAns());
    return 0;
}