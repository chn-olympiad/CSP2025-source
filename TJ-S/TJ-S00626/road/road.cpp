#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 10010;
int fa[maxn + 20] = {0};
struct edge {
    int u, v;
    ll w;
    bool operator < (const edge b) const {
        return w < b.w;
    }
} e[1000010], E[maxn], T[maxn * 11];
int find(int x) {
    return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}
ll C[20] = {0}, G[20][maxn] = {0};
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i ++) {
        scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
    }
    for (int i = 1; i <= k; i ++) {
        scanf("%lld", &C[i]);
        for (int j = 1; j <= n; j ++) {
            scanf("%lld", &G[i][j]);
        }
    }
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= n; i ++) {
        fa[i] = i;
    }
    int cnt = 0;
    ll num = 0;
    for (int i = 1; i <= m; i ++) {
        int a = find(e[i].u);
        int b = find(e[i].v);
        if (a != b) {
            fa[b] = a;
            E[++ cnt] = e[i];
            num += e[i].w;
        }
    }
    // calc
    ll res = num;
    for (int sta = 1; sta < (1 << k); sta ++) {
        ll val = 0;
        for (int i = 1; i < n; i ++) {
            T[i] = E[i];
        }
        int pos = n - 1, tot = n;
        for (int i = 1; i <= k; i ++) {
            if ((sta >> (i - 1)) & 1) {
                val += C[i];
                tot ++;
                for (int u = 1; u <= n; u ++) {
                    T[++ pos] = edge{i + n, u, G[i][u]};
                }
            }
        }
        for (int i = 1; i <= n + k; i ++) {
            fa[i] = i;
        }
        sort(T + 1, T + 1 + pos);
        int cnt_ = 0;
        for (int i = 1; i <= pos; i ++) {
            int a = find(T[i].u), b = find(T[i].v);
            if (a != b) {
                fa[b] = a;
                val += T[i].w;
                cnt_ ++;
            }
            if (cnt_ == tot) {
                break;
            }
        }
        res = min(res, val);
    }
    printf("%lld\n", res);
    return 0;
}