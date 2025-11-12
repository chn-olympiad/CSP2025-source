#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
struct DSU {
    int fa[20005];
    DSU() {
        for(int i = 1; i <= 20000; i++) fa[i] = i;
    }
    inline int merge(int x, int y) {
        int fx = findf(x), fy = findf(y);
        if(fx == fy) return 0;
        return fa[fx] = fy, 1;
    }
    int findf(int x) {
        if(fa[x] == x) return x;
        return fa[x] = findf(fa[x]);
    }
} dsu;
struct EDGE {
    int x, y, z;
} e[1000005];
long long c[15], a[15][10005];
namespace case0 {
    inline bool cmp(EDGE x, EDGE y) {
        return x.z < y.z;
    }
    inline void main() {
        sort(e + 1, e + 1 + m, cmp);
        long long ans = 0;
        for(int i = 1; i <= m; i++) {
            if(dsu.merge(e[i].x, e[i].y)) ans += e[i].z;
            
        }
        cout << ans << endl;
    }
}
namespace sol {
    /*
    克鲁斯卡尔重构树搞出来。
    先对每个特殊点单独考虑修复了是什么样子的。
    肯定会连接花费最少的点。
    然后从大到小考虑重构树上的点。
    肯定会分成两个连通块，其中一个内肯定没有和特殊点连边的点，然后在这个里面找个最小的。
    考虑同时修多个特殊点，每次决策取min即可，因为每次不管连哪个都不会对后来的产生影响。
    */


    inline bool cmp(EDGE x, EDGE y) {
        return x.z < y.z;
    }
    int node = n;
    struct BIT {
        int t[100005];
        BIT() {
            memset(t, 0, sizeof(t));
        }
        inline void add(int x, int y) {
            // cout << "added " << x << " " << y << endl;
            for(; x <= 100000; x += x & -x) t[x] += y;
        }
        inline int ask(int x, int ret = 0) {
            for(; x; x -= x & -x) ret += t[x];
            return ret;
        }
    } t;
    struct edge {
        int to, nxt;
    } ed[100005];
    int cnt = 0, tot = 0;
    long long head[20005], dfn[20005], mp[20005], mi[20005][15], fa[20005], l[20005], r[20005], nr[15], val[20005];
    long long cost[15][20005];
    inline void add(int x, int y) {
        ed[++cnt] = {y, head[x]};
        head[x] = cnt;
    }
    void dfs(int x) {
        mp[l[x] = dfn[x] = ++tot] = x;
        for(int i = head[x]; i; i = ed[i].nxt) {
            int y = ed[i].to;
            if(y == fa[x]) continue;
            fa[y] = x;
            dfs(y);
            for(int j = 1; j <= k; j++) {
                if(mi[x][j] != -1) {
                    if(a[j][mi[x][j]] > a[j][mi[y][j]]) mi[x][j] = mi[y][j];
                } else mi[x][j] = mi[y][j];
            }
        }
        r[x] = tot;
    }
    inline void main() {
        memset(val, -1, sizeof(val));
        memset(mi, -1, sizeof(mi));
        for(int i = 1; i <= k; i++) a[i][0] = 0x3f3f3f3f3f3f3f3f;
        sort(e + 1, e + 1 + m, cmp);
        long long ans = 0;
        int count = n;
        for(int i = 1; i <= m; i++) {
            int fx = dsu.findf(e[i].x), fy = dsu.findf(e[i].y);
            if(fx == fy) continue;
            ++count;
            val[count] = e[i].z;
            add(fx, count); add(fy, count);
            add(count, fx); add(count, fy);
            dsu.merge(e[i].x, count); dsu.merge(e[i].y, count);
            ans += e[i].z;
        }
        if(k == 0) return cout << ans << endl, void();
        for(int i = 1; i <= n; i++) for(int j = 1; j <= k; j++) mi[i][j] = i;
        dfs(count);
        for(int i = 1; i <= k; i++) {
            int p = 1;
            t = BIT();
            for(int j = 2; j <= n; j++) if(a[i][j] < a[i][p]) p = j;
            t.add(dfn[p], 1);  //t.add(dfn[p] + 1, -1);
            nr[i] = p;
            for(int j = count; j >= n + 1; j--) {
                int son[2] = {0, 0}, pos = 0;
                for(int k = head[j]; k; k = ed[k].nxt) if(ed[k].to != fa[j]) son[pos++] = ed[k].to;
                if(t.ask(r[son[0]]) - t.ask(l[son[0]] - 1)) {
                    cost[i][j] = a[i][mi[son[1]][i]];
                    t.add(dfn[mi[son[1]][i]], 1);// t.add(dfn[mi[son[1]][i]] + 1, -1);
                } else if(t.ask(r[son[1]]) - t.ask(l[son[1]] - 1)) {
                    cost[i][j] = a[i][mi[son[0]][i]];
                    t.add(dfn[mi[son[0]][i]], 1);// t.add(dfn[mi[son[0]][i]] + 1, -1);
                } else assert(0);
            }
        }
        // for(int i = 1; i <= k; i++) {
        //     for(int j = 1; j <= n; j++) {
        //         assert(a[i][nr[i]] <= a[i][j]);
        //     }
        // }
        long long ret = 0x3f3f3f3f3f3f3f3fll;
        for(int s = 0; s < (1 << k); s++) {
            long long sum = 0;
            for(int i = 1; i <= k; i++) if(s & (1 << (i - 1))) sum += c[i] + a[i][nr[i]];
            for(int i = count; i >= n + 1; i--) {
                long long Mi = 0x3f3f3f3f3f3f3f3fll;
                for(int j = 1; j <= k; j++) if(s & (1 << (j - 1))) Mi = min(Mi, cost[j][i]);
                if(Mi > val[i]) continue;
                sum += Mi - val[i];
                ret = min(ret, ans + sum);
            }
        }
        cout << ret << endl;
    }
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >> e[i].x >> e[i].y >> e[i].z;
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    // case0::main();
    sol::main();

    return 0;
}
