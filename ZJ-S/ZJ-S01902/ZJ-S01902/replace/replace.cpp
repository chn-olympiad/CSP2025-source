#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ui = unsigned;
const int N = 2e5 + 10, M = 5e6 + 10;
int n, q, m = 0, rtl[M], rtr[M], t[M + N][26], cnt = 0, dtL[N], dtR[N], dfn[M], ret = 0, sz[N * 2], ed[M], bel[N];
struct Has{
    ui mod, bas, val;
    Has(int _md, int _bs):mod(_md), bas(_bs), val(0) {}
    void ins(char c) {val = (1uLL * val * bas + c - 'a' + 1) % mod;}
};
string t1, t2;
map<pair<ui, ui>, int> mp; 
void dfs(int u) {
    dfn[u] = ++ret;
    for (int c = 0; c < 26; c++) {
        if (!t[u][c]) continue;
        dfs(t[u][c]);
    }
    ed[u] = ret;
}
int ans[N];
struct Node{
    int op, a, b, c, d;
};
vector<Node> G[N];
struct LSH{
    int b[M], cnt = 0;
    void clear() {
        cnt = 0;
    }
    void ins(int x) {
        b[++cnt] = x;
    }
    void init() {
        sort(b + 1, b + 1 + cnt);
        cnt = unique(b + 1, b + 1 + cnt) - b - 1;
    }
    int qry(int x) {
        return lower_bound(b + 1, b + 1 + cnt, x) - b;
    }
}DS;
vector<pair<int, int> > T1[N * 7];
struct Point{
    int l, r, t;
};
vector<Point> T2[N * 7];
#define lowbit(x) (x & (-x))
struct Fenwick{
    int C[N * 7], nn;
    void init(int x) {
        nn = x;
        for (int i = 1; i <= nn; i++) C[i] = 0;
    }
    void add(int x, int v) {
        for (int i = x; i <= nn; i += lowbit(i)) C[i] += v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += C[i];
        return ret;
    }
}ds;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    ios :: sync_with_stdio(false);
    cin.tie( 0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> t1 >> t2;
        if (t1 == t2) continue;
        int len = t1.size(), dl = -1, dr = -1;
        for (int j = 0; j < len; j++) 
            if (t1[j] != t2[j]) {
                if (dl == -1) dl = j;
                dr = j;
            }
        Has ha(1000000007, 31), hb(1000000009, 37);
        for (int j = dl; j <= dr; j++) {
            ha.ins(t1[j]), ha.ins(t2[j]);
            hb.ins(t1[j]), hb.ins(t2[j]);
        }
        pair<ui, ui> pr = make_pair(ha.val, hb.val);
        if (mp.find(pr) == mp.end()) {
            mp[pr] = ++m;
            rtl[m] = ++cnt, rtr[m] = ++cnt;
        }
        bel[i] = mp[pr];
        int u1 = rtl[mp[pr]], u2 = rtr[mp[pr]];
        for (int j = dl - 1; j >= 0; j--) {
            int c = t1[j] - 'a';
            if (!t[u1][c]) t[u1][c] = ++cnt;
            u1 = t[u1][c];
        }
        dtL[i] = u1;
        for (int j = dr + 1; j < len; j++) {
            int c = t1[j] - 'a';
            if (!t[u2][c]) t[u2][c] = ++cnt;
            u2 = t[u2][c];
        }
        dtR[i] = u2;
    } 
    for (int i = 1; i <= m; i++) ret = 0, dfs(rtl[i]), sz[i * 2 - 1] = ret, ret = 0, dfs(rtr[i]), sz[i * 2] = ret;
    for (int i = 1; i <= n; i++) if (bel[i]) G[bel[i]].push_back({1, dfn[dtL[i]], ed[dtL[i]], dfn[dtR[i]], ed[dtR[i]]});
    for (int i = 1; i <= q; i++) {
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) continue;
        int len = t1.size(), dl = -1, dr = -1;
        for (int j = 0; j < len; j++) 
            if (t1[j] != t2[j]) {
                if (dl == -1) dl = j;
                dr = j;
            }
        Has ha(1000000007, 31), hb(1000000009, 37);
        for (int j = dl; j <= dr; j++) {
            ha.ins(t1[j]), ha.ins(t2[j]);
            hb.ins(t1[j]), hb.ins(t2[j]);
        } 
        pair<ui, ui> pr = make_pair(ha.val, hb.val);
        if (mp.find(pr) == mp.end()) continue;
        int u1 = rtl[mp[pr]], u2 = rtr[mp[pr]];
        for (int j = dl - 1; j >= 0; j--) {
            int c = t1[j] - 'a';
            if (!t[u1][c]) break;
            u1 = t[u1][c];

        }
        for (int j = dr + 1; j < len; j++) {
            int c = t1[j] - 'a';
            if (!t[u2][c]) break;
            u2 = t[u2][c];
        }
        G[mp[pr]].push_back((Node){2, dfn[u1], dfn[u2], i});
    } 
    for (int i = 1; i <= m; i++) {
        DS.clear();
        for (Node it : G[i]) {
            if (it.op == 1) DS.ins(it.a), DS.ins(it.b), DS.ins(it.c), DS.ins(it.d);
            else DS.ins(it.a), DS.ins(it.b);
        }
        DS.init();
        for (int i = 1; i <= DS.cnt + 1; i++) T1[i].clear(), T2[i].clear();
        for (Node it : G[i]) {
            if (it.op == 1) {
                T2[DS.qry(it.a)].push_back({DS.qry(it.c), DS.qry(it.d), 1});
                T2[DS.qry(it.b) + 1].push_back({DS.qry(it.c), DS.qry(it.d), -1});
            } else {
                T1[DS.qry(it.a)].emplace_back(DS.qry(it.b), it.c);
            }
        }
        ds.init(DS.cnt);
        for (int i = 1; i <= DS.cnt; i++) {
            for (auto it : T2[i]) {
                ds.add(it.l, it.t);
                ds.add(it.r + 1, -it.t);
            }
            for (auto it : T1[i]) {
                ans[it.second] = ds.qry(it.first);
            }
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}