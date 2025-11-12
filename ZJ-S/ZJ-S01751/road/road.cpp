#include <bits/stdc++.h>
using namespace std;

#define N 1024
#define M 1010024

int n, m, k, xcnt, fa[N];
int eu[M], ev[M], ew[M], ord[M], xord[N];
int c[14], cord[11024];

#define Index(X, Y) (m + ((X) - 1) * n + (Y))

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long ans = 0x3f3f3f3f3f3f3f3fll;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) cin >> eu[i] >> ev[i] >> ew[i], ord[i] = i;
    sort(ord + 1, ord + m + 1, [](int x, int y) { return ew[x] < ew[y]; });
    for (int i = 1; i <= m; i++) {
        int u = find(eu[ord[i]]), v = find(ev[ord[i]]);
        if (u != v) xord[++xcnt] = ord[i], fa[u] = v;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) cin >> ew[Index(i, j)], eu[Index(i, j)] = i + n, ev[Index(i, j)] = j;
    }
    for (int i = 0; i < (1 << k); i++) {
        long long tmp = 0;
        int cnt = xcnt;
        for (int j = 1; j <= n + k; j++) fa[j] = j;
        for (int j = 1; j <= xcnt; j++) cord[j] = xord[j];
        for (int j = 1; j <= k; j++) if (i & (1 << j - 1)) {
            tmp += c[j];
            for (int l = 1; l <= n; l++) cord[++cnt] = Index(j, l);
        }
        sort(cord + 1, cord + cnt + 1, [](int x, int y) { return ew[x] < ew[y]; });
        for (int j = 1; j <= cnt; j++) {
            int u = find(eu[cord[j]]), v = find(ev[cord[j]]);
            if (u != v) tmp += ew[cord[j]], fa[u] = v;
        }
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}