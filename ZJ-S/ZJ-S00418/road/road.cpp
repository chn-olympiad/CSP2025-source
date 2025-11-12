#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e6 + 5;

int n, m, k, c[15], a[11][N];

struct Edge {
    int u, v, w;
    bool operator < (const Edge &t) const {
        return w < t.w;
    }
}e[N];

int fa[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
    return x * f;
}

signed main() {
    // int st = clock();
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1; i <= m; i++) e[i].u = read(), e[i].v = read(), e[i].w = read();
    bool flg = 1;
    for(int i = 1; i <= k; i++) {
        c[i] = read(); flg &= (c[i] == 0);
        for(int j = 1; j <= n; j++) a[i][j] = read();
    }
    if(flg) {
        for(int j = 1; j <= k; j++)
            for(int w = 1; w <= n; w++) e[++m] = {n + j, w, a[j][w]};
        for(int i = 1; i <= n + k; i++) fa[i] = i;
        sort(e + 1, e + 1 + m); int res = 0;
        for(int i = 1; i <= m; i++) {
            int x = find(e[i].u), y = find(e[i].v);
            if(x == y) continue; fa[x] = y; res += e[i].w;
        }
        cout << res << endl;
        return 0;
    }
    else {
        int ans = LLONG_MAX;
        for(int i = 0; i < (1 << k); i++) {
            int len = m, res = 0, cnt = 0;
            for(int j = 0; j < k; j++) {
                if((i >> j) & 1) {
                    res += c[j + 1], cnt++;
                    for(int w = 1; w <= n; w++) e[++len] = {n + cnt, w, a[j + 1][w]};
                }
            }
            for(int i = 1; i <= n + cnt; i++) fa[i] = i;
            sort(e + 1, e + 1 + len);
            for(int i = 1; i <= len; i++) {
                int x = find(e[i].u), y = find(e[i].v);
                if(x == y) continue; fa[x] = y;
                res += e[i].w;
            }
            ans = min(ans, res);
        }
        cout << ans << endl;
    }
    // cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
    return 0;
}