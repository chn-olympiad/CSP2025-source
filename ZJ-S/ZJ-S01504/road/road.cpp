#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 120005, M = 1e6 + 5, inf = 1e16;
bool bg;
int n, m, k, tot, ans, a[15][N], fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
struct edge {
    int u, v, w;
    friend bool operator < (edge x, edge y) {
        return x.w < y.w;
    } 
} e[M], mst[N], c[N], b[15][N], ls[N];
void merge(edge *a, edge *b, int n, int m) {
    int cnt = 0, i = 1, j = 1;
    while (i <= n && j <= m) {
        if (a[i].w < b[j].w) ls[++cnt] = a[i++];
        else ls[++cnt] = b[j++];
    }
    while (j <= m) ls[++cnt] = b[j++];
    while (i <= n) ls[++cnt] = a[i++];
    F(i, 1, cnt) a[i] = ls[i];
}
bool ed;
signed main() {
    // cerr << (&bg - &ed) / 1048576.0 << '\n';
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    F(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    F(i, 1, k) {
        F(j, 0, n) {
            cin >> a[i][j];
            if (j) b[i][j] = {n + i, j, a[i][j]};
        }
        sort(b[i] + 1, b[i] + n + 1);
    }

    sort(e + 1, e + m + 1);
    F(i, 1, n) fa[i] = i;
    F(i, 1, m) {
        auto [u, v, w] = e[i];
        if (find(u) == find(v)) continue;
        fa[find(u)] = find(v);
        mst[++tot] = e[i], ans += w;
    }
    for (int s = 1; s < 1 << k; s++) {
        int sum = 0, cnt = tot;
        F(i, 1, tot) c[i] = mst[i];
        F(i, 1, k) if (s >> i - 1 & 1) {
            sum += a[i][0];
            merge(c, b[i], cnt, n);
            cnt += n;
            // F(j, 1, n) c[++cnt] = {n + i, j, a[i][j]};
        }
        // sort(c + 1, c + cnt + 1);
        F(i, 1, n + k) fa[i] = i;
        F(i, 1, cnt) {
            auto [u, v, w] = c[i];
            if (find(u) == find(v)) continue;
            fa[find(u)] = find(v), sum += w;
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}