#include <bits/stdc++.h>
using namespace std;

const int N = 10010, M = 1000010, K = 10;

int n, m, k;
struct Edge {
    int u, v, w;
} e[M];
struct Cont {
    int c, d[N];
} a[K];
bitset<K> st;
int fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int idx = 0;
    for (int i = 1, u, v, w; i <= m; i ++)
        cin >> u >> v >> w,
        e[++ idx] = {u, v, w};
    for (int i = 1; i <= k; i ++) {
        cin >> a[i].c;
        for (int j = 1; j <= n; j ++)
            cin >> a[i].d[j];
    }
    sort(e + 1, e + idx + 1, [](Edge p, Edge q) {
        return p.w < q.w;
    });
    for (int i = 1; i <= n; i ++)
        fa[i] = i;
    long long ans = 0;
    for (int i = 1, cnt = 0; i <= idx; i ++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        long long tmp = 1e14;
        int choose = 0;
        for (int j = 1; j <= k; j ++) {
            long long x = a[j].d[u] + a[j].d[v];
            if (!st[j]) x += a[j].c;
            if (tmp > x) {
                tmp = x;
                if (!st[j]) choose = j;
            }
        }
        if (w > tmp) {
            if (choose) st[choose] = 1;
            ans += tmp;
        }
        else ans += w;  
        fa[fu] = fv;
        if (++ cnt == n)
            break;
    }
    cout << ans;
    return 0;
}
/*
5 7 0
1 2 1
1 3 2
2 3 8
2 5 11
3 4 5
3 5 2
4 5 3
*/