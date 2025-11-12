#include <bits/stdc++.h>
using namespace std;
namespace Main {
#define int long long
#define endl '\n'
#define pb push_back
#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename ...Tail>
void debug_out(Head H, Tail... T) {
    cerr << ' ' << H;
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif // LOCAL
const int N = 1e4 + 55, M = 1e6 + 55, INF = 1e18;
int n, m, k, c[10], ans, sum, cnt, cnt2;
struct edge {
    int x, y, w;
} e2[M], e[N], b[N * 10];
bool operator <(const edge &a, const edge &b) {
    return a.w < b.w;
}
struct node {
    int x, w;
};
namespace dsu {
    int fa[N];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] ^ x ? fa[x] = get(fa[x]): x;
    }
    bool merge(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        fa[x] = y;
        return true;
    }
}
void kruskal() {
    dsu::init(n);
    for (int i = 1; i <= m; i++) {
        auto [x, y, w] = e2[i];
        if (dsu::merge(x, y)) e[++cnt] = e2[i];
    }
}
int kruskal2(int y) {
    dsu::init(n + k);
    int pct = __builtin_popcountll(y), edgenum = 0, sum = 0;
    for (int i = 1, j = 1; edgenum < n + pct - 1; ) {
        auto [xi, yi, wi] = e[i];
        auto [xj, yj, wj] = b[j];
        int tj = xj - n - 1;
        if (j <= cnt2 && ~(y >> tj) & 1) {
            j++;
            continue;
        }
        if (j > cnt2 || (i <= n && wi < wj)) {
            if (dsu::merge(xi, yi)) edgenum++, sum += wi;
            i++;
        } else {
            if (dsu::merge(xj, yj)) edgenum++, sum += wj;
            j++;
        }
    }
    return sum;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(0), ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w;
        e2[i] = {x, y, w};
    }
    sort(e2 + 1, e2 + m + 1);
    kruskal();
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        for (int j = 1, x; j <= n; j++)
            cin >> x, b[++cnt2] = {i + n + 1, j, x};
    }
    sort(b + 1, b + cnt2 + 1);
    ans = INF;
    for (int i = 0; i < (1 << k); i++) {
        int sum = 0;
        for (int j = 0; j < k; j++)
            if ((i >> j) & 1) sum += c[j];
        ans = min(ans, sum + kruskal2(i));
    }
    cout << ans << endl;
    return 0;
}
}
signed main() {
    Main::main();
    return 0;
}
