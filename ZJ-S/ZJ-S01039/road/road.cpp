#include<bits/stdc++.h>
#define int long long
#define rep(i, r) for(int i = 1; i <= r; i++)
#define Rep(i, l, r) for(int i = l; i <= r; i++)
#define lep(i, r) for(int i = r; i; i--)
#define Lep(i, l, r) for(int i = r; i >= l; i--)
using namespace std;
//bool p1;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, f[N + 10], c[15];
long long ans;
struct edge {
    int u, v, w;
} a[M], b[N], d[15][N];
int find(int x) {
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}
bool vis[15];
struct node {
    int u, v, w, d, i;
    node(){}
    node(edge x, int id, int k) {
        u = x.u, v = x.v, w = x.w, d = id, i = k;
    }
    bool operator<(const node& x) const {
        return w > x.w;
    }
};
void dfs(int s, int t) {
    if(s == k + 1) {
        // cerr << "Case :" << t << "\nUsed:";
        // rep(i, k) if(vis[i]) cerr << i << ' ';
        // cerr << '\n';

        long long sum = 0;
        priority_queue<node, vector<node> > q;
        q.push(node(b[1], 0, 1));
        rep(i, k) if(vis[i]) q.push(node(d[i][1], i, 1)), sum += c[i];
        int tot = 1;
        rep(i, n + k) f[i] = i;
        while(tot < n + t) {
            node t = q.top();
            q.pop();
            int x = find(t.u), y = find(t.v);
            if(x != y) {
                f[x] = y;
                sum += t.w;
                tot++;
                // cerr << "Choose:" <<t.u << ' '<<t.v << ' '<<t.w <<'\n';
            }
            if(!t.d) if(t.i < n - 1) q.push(node(b[t.i + 1], 0, t.i + 1));
            if(t.d) if(t.i < n) q.push(node(d[t.d][t.i + 1], t.d, t.i + 1));
        }
        ans = min(ans, sum);
        return ;
    }
    dfs(s + 1, t);
    vis[s] = true;
    dfs(s + 1, t + 1);
    vis[s] = false;
}
//bool p2;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    cerr << "Memory Used:" << (&p2 - &p1) / 1024.0 / 1024.0 << "Mb.";
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    rep(i, k) {
        cin >> c[i];
        rep(j, n) {
            int w;
            cin >> w;
            d[i][j] = {n + i, j, w};
        }
        stable_sort(d[i] + 1, d[i] + n + 1, [](edge x, edge y) {
            return x.w < y.w;
        });
    }
    rep(i, n) f[i] = i;
    stable_sort(a + 1, a + m + 1, [](edge x, edge y) {
        return x.w < y.w;
    });
    int tot = 0;
    rep(i, m) {
        int x = find(a[i].u), y = find(a[i].v);
        if(x != y) {
            f[x] = y;
            b[++tot] = a[i];
            ans += a[i].w;
            if(tot == n - 1) break;
        }
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}
//chzx_lfw AK IOI!!!!!