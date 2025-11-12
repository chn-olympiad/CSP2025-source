#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
const long long K = 15;
const long long N = 1e4 + 10;
const long long M = 1e6 + 10;
const long long INF = 2e9;
struct Edge {
    long long u, v, w, id;
} ed[2 * M];
long long a[K][N], c[K];
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
long long fa[N];
long long find(long long x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
bool ck1() {
    long long flag = 0;
    for(long long i = 1; i <= k; i++) {
        long long flag1 = 0;
        if(c[i]) flag = 1;
        for(long long j = 1; j <= n; j++)
            if(!a[i][j]) flag1 = 1;
        if(!flag1) flag = 1;
    }
    return flag ^ 1;
}
long long flag[N];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for(long long i = 1; i <= m; i++)
        scanf("%lld%lld%lld", &ed[i].u, &ed[i].v, &ed[i].w);
    for(long long i = 1; i <= k; i++) {
        scanf("%lld", &c[i]);
        for(long long j = 1; j <= n; j++)
            scanf("%lld", &a[i][j]);
    }
    if(k == 0) {
        sort(ed + 1, ed + m + 1, cmp);
        for(long long i = 1; i <= n; i++)
            fa[i] = i;
        long long ans = 0;
        for(long long i = 1; i <= m; i++) {
            Edge x = ed[i];
            x.u = find(x.u), x.v = find(x.v);
            // printf("%lld %lld\n", x.u, x.v);
            if(x.u != x.v) ans += x.w, fa[x.u] = x.v;
        }
        printf("%lld\n", ans);
    } else if(ck1()) {
        long long cnt = m;
        for(long long i = 1; i <= k; i++) {
            long long pl = 0;
            for(long long j = 1; j <= n; j++) 
                if(a[i][j] == 0) pl = j;
            for(long long j = 1; j <= n; j++) {
                if(j == pl) continue;
                ed[++cnt] = {j, pl, a[i][j], i};
            }
        }
        sort(ed + 1, ed + cnt + 1, cmp);
        for(long long i = 1; i <= n; i++)
            fa[i] = i;
        long long ans = 0;
        for(long long i = 1; i <= cnt; i++) {
            Edge x = ed[i];
            x.u = find(x.u), x.v = find(x.v);
            // printf("%lld %lld\n", x.u, x.v);
            if(x.u != x.v) ans += x.w, fa[x.u] = x.v;
        }
        printf("%lld\n", ans);
    } else {
        long long cnt = m;
        sort(ed + 1, ed + m + 1, cmp);
        for(long long i = 1; i <= n; i++)
            fa[i] = i;
        long long ans1 = 0;
        for(long long i = 1; i <= m; i++) {
            Edge x = ed[i];
            x.u = find(x.u), x.v = find(x.v);
            // printf("%lld %lld\n", x.u, x.v);
            if(x.u != x.v) ans1 += x.w, fa[x.u] = x.v;
        }
        for(long long i = 1; i <= k; i++) {
            long long pl = 0;
            a[i][0] = INF;
            for(long long j = 1; j <= n; j++) 
                if(a[i][j] < a[i][pl]) pl = j;
            for(long long j = 1; j <= n; j++) {
                if(j == pl) continue;
                ed[++cnt] = {j, pl, a[i][pl] + a[i][j] + c[i], i};
            }
        }
        sort(ed + 1, ed + cnt + 1, cmp);
        for(long long i = 1; i <= n; i++)
            fa[i] = i;
        long long ans = 0;
        for(long long i = 1; i <= cnt; i++) {
            Edge x = ed[i];
            x.u = find(x.u), x.v = find(x.v);
            // printf("%lld %lld\n", x.u, x.v);
            if(x.u != x.v) {
                ans += x.w, fa[x.u] = x.v;
                if(!flag[x.id]) flag[x.id] = 1;
                else ans -= c[x.id];
            }
        }
        printf("%lld\n", min(ans, ans1));        
    }
}