#include<bits/stdc++.h>
using namespace std;
int rd() {
    int x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x;
}
using ll = long long;
const int M = 1e6 + 10, K = 10, N = 1e4 + 10;
int n, m, k, c[K], d[K][N], fa[N + 20], siz[N + 20];
struct Edge{
    int u, v, w;
}a[M], b[(K + 2) * N];
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
inline bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y], fa[y] = x;
    return true;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    n = rd(), m = rd(), k = rd();
    for (int i = 1; i <= m; i++) a[i].u = rd(), a[i].v = rd(), a[i].w = rd();
    sort(a + 1, a + 1 + m, [](const Edge x, const Edge y) {return x.w < y.w;});
    int q = 0;
    for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for (int i = 1; i <= m; i++) {
        if (merge(a[i].u, a[i].v)) b[++q] = a[i];
    }
    for (int i = 0; i < k; i++) {
        c[i] = rd();
        for (int j = 1; j <= n; j++) {
            d[i][j] = rd();
            b[++q] = {j, n + 1 + i, d[i][j]};
        }
    }
    sort(b + 1, b + 1 + q, [](const Edge x, const Edge y) {return x.w < y.w;});
    ll ans = 1e18;
    for (int w = 0; w < (1 << k); w++) {
        ll sum = 0;
        for (int i = 0; i < k; i++) if ((w >> i) & 1) sum += c[i];
        for (int i = 1; i <= n + k; i++) fa[i] = i, siz[i] = 1;
        for (int j = 1; j <= q; j++) {
            if (b[j].v > n && ((w >> (b[j].v - 1 - n)) & 1) == 0) continue;
            if (merge(b[j].u, b[j].v)) sum += b[j].w;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}