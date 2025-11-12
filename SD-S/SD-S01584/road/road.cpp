#include <iostream>
#include <algorithm>
#include <vector>
#define END cout.flush(); fclose(stdin); fclose(stdout);
using namespace std;

int n, m, idx, cnt, sum, f[10000010], c[20], a[20][1000010];
pair<int, pair<int, int>> e[10000010];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
}

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

bool merge(int u, int v, int w) {
    int fu = find(u), fv = find(v);
    if (fu != fv) {
        f[fu] = fv;
        sum += w;
        if (u <= n && v <= n) {
            cnt++;
        }
        return true;
    }
    return false;
}

void kruskal() {
    cnt = sum = 0;
    init(n);
    sort(e + 1, e + idx + 1);
    for (int i = 1; i <= idx; i++) {
        int u = e[i].second.first, v = e[i].second.second, w = e[i].first;
        if (merge(u, v, w)) {
            if (cnt == n - 1) {
                break;
            }
        }
    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {w, {u, v}};
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= (1 << k) - 1; i++) {
        idx = m;
        for (int j = 1; j <= k; j++) {
            if ((i >> (j - 1)) & 1) {
                for (int l = 1; l <= n; l++) {
                    // 1. 连到虚拟点
                    e[++idx] = {a[j][l] + c[j], {l, n + j * l}};
                    // 2. 虚拟点连到真点
                    e[++idx] = {c[j], {n + j * l, n + k * n + j * l}};
                    // 3. 真点连接到其它城市
                    for (int o = 1; o <= n; o++) {
                        if (o == l) {
                            continue;
                        }
                        e[++idx] = {a[j][o] + c[j], {n + k * n + j * l, o}};
                    }
                }
            }
        }
        kruskal();
        ans = min(ans, sum);
    }
    cout << ans;
    END;
    return 0;
}
