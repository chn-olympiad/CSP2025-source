#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e4 + 20, M = 1e6 + 10, inf = 1e13;
int n, m, k, fa[N], c[N], ans, sum, tot, cnt, siz[N];
bool op = 1;
pair<int, pair<pii, int>> e[M << 1];
int find(int u) {
    return ((fa[u] == u) ? u : fa[u] = find(fa[u]));
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int x, y, z;
    for (int i = 1;i <= m;i ++) {
        cin >> x >> y >> z;
        e[i] = {z, {{x, y}, 0}};
    }
    for (int i = 1;i <= k;i ++) {
        cin >> c[i];
        for (int j = 1;j <= n;j ++) {
            cin >> z;
            e[(i - 1) * n + j + m] = {z, {{i, j}, 1}};
        }
    }
    sort(e + 1, e + m + n * k + 1);
    ans = inf;
    for (int t = 0;t < (1 << k);t ++) {
        sum = tot = cnt = 0; // clear
        for (int i = 1;i <= k;i ++) { // -1
            if (!(t & (1 << i - 1))) continue;
            sum += c[i]; cnt ++;
        }
        for (int i = 1;i <= n + k;i ++) fa[i] = i;
        for (int i = 1;i <= n + k;i ++) siz[i] = 1;
        for (int i = 1;i <= n * k + m;i ++) {
            if (e[i].second.second && (!(t & (1 << e[i].second.first.first - 1))))
                continue;
            if (e[i].second.second) x = find(e[i].second.first.first + n);
            else x = find(e[i].second.first.first);
            y = find(e[i].second.first.second);
            if (x == y) continue;
            if (siz[x] > siz[y]) swap(x, y);
            tot ++;
            sum += e[i].first; fa[x] = y;
            siz[y] += siz[x]; siz[x] = 0;
            if (tot == n + cnt - 1) break;
        }
        // cout << t << " " << sum << "\n";
        ans = min(ans, sum);
        // for (int i = 1;i <= n + k;i ++) {
        //     if (i > n && (!(t & (1 << i - n - 1)))) continue;
        //     if (find(i) != find(1)) {
        //         cout << t << " " << i << "\n";
        //         op = 0;
        //     } 
        // }
        // if (tot != n + cnt - 1) op = 0;
    }   
    cout << ans;
    return 0;
}
// long long