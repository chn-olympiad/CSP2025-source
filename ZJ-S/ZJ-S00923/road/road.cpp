#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second
typedef pair<LL, int> PP;
typedef double db;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int mod = 1e9 + 7;
int n, m, c, pos[N];
PP val[11][N];
int fa[N];
// int read() {
//     char ch = getchar();
//     LL ret = 0;
//     while(ch < '0' || ch > '9') ch = getchar();
//     while(ch >= '0' && ch <= '9') {
//         ret = (ret * 10 + ch - '0'), ch = getchar();
//         if(ch == '\n') break;
//     }
//     return ret;
// }
int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    fa[fx] = fy;
}
struct E {
    int x, y;
    LL val;
} a[M], b[N], tmp[N];
LL tot, bns, ans;
bool cmp(E wasd, E dsaw) {
    return wasd.val < dsaw.val;
}
void merge_edge(int p) {
    int tot1 = 0, j = 1;
    for(int i = 1; i <= m; i ++) {
        while(j <= n && val[p][j].x < a[i].val) tmp[++tot1] = {n + p, val[p][j].y, val[p][j].x}, j ++;
        tmp[++tot1] = a[i];
    }
    while(j <= n) tmp[++tot1] = {n + p, val[p][j].y, val[p][j].x}, j ++;
    m = tot1;
    for(int i = 1; i <= m; i ++) a[i] = tmp[i];
}
void kruskal(bool st) {
    // sort(a + 1, a + m + 1, cmp);
    for(int i = 1; i <= n + c; i ++) fa[i] = i;
    for(int i = 1; i <= m; i ++) {
        int x = a[i].x, y = a[i].y;
        if(find(x) == find(y)) continue;
        // cout << x << ' ' << y << endl;
        merge(x, y), bns += a[i].val;
        if(st) b[++tot] = a[i];
    }
}
LL cns = 0x3f3f3f3f3f3f3f3f;
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // freopen("road/road4.in", "r", stdin);
    db st_clock = clock();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> c;
    for(int i = 1; i <= m; i ++) {
        int wasd, dsaw, wasdwasd; cin >> wasd >> dsaw >> wasdwasd;
        a[i] = {wasd, dsaw, wasdwasd};
    }
    sort(a + 1, a + m + 1, cmp);
    kruskal(1), ans = bns, cns = bns;
    for(int i = 1; i <= c; i ++) {
        cin >> pos[i];
        for(int j = 1; j <= n; j ++) cin >> val[i][j].x, val[i][j].y = j;
        sort(val[i] + 1, val[i] + n + 1);
    }
    for(int mask = 0; mask < (1 << c); mask ++) {
        m = tot;
        for(int i = 1; i <= tot; i ++) a[i] = b[i];
        bns = 0;
        for(int i = 0; i < c; i ++) {
            if((mask >> i) & 1) merge_edge(i + 1), bns += pos[i + 1];
        }
        kruskal(0);
        cns = min(cns, bns);
    }
    cout << cns << endl;
    db ed_clock = clock();
    cerr << (db)((ed_clock - st_clock) / (db)(CLOCKS_PER_SEC)) << endl;
    return 0;
}