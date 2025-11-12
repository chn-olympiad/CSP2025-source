#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 5000050;
const int M = 200020;

const LL m1 = 998244853, m2 = 1e9 + 9, bs = 131;

struct Hash { LL x, y; } a[M];
bool operator < (Hash x, Hash y) {
    return x.x == y.x ? x.y < y.y : x.x < y.x;
}
bool operator == (Hash x, Hash y) {
    return x.x == y.x && x.y == y.y;
}

int n, q, cnt, t[N][28], tot, ts[M], tt[M], l[N], r[N], tr[N], cdfn, ans[M];
char s1[N], s2[N], s[N];
map<Hash, int> rtl, rtr;
vector<int> gs[N], gt[N];

int insert(int u, int len, int tp, int id) {
    if (u == 0) u = ++cnt;
    int x = u;
    for (int i = 1; i <= len; i++) {
        if (t[x][s[i] - 'a'] == 0)
            t[x][s[i] - 'a'] = ++cnt;
        x = t[x][s[i] - 'a'];
    }
    if (tp == 0) {
        gs[x].push_back(id);
    } else {
        ts[id] = x;
    }
    return u;
}

void insert1(int u, int len, int tp, int id) {
    if (u == 0) return;
    int x = u;
    for (int i = 1; i <= len + 1; i++) {
        if (t[x][s[i] - 'a'] == 0 || i == len + 1) {
            if (tp == 0) {
                gt[x].push_back(id);
            } else {
                tt[id] = x;
            }
            return;
        }
        x = t[x][s[i] - 'a'];
    }
    
}

void dfs1(int u) {
    // cout << "cs1 u = " << u << endl;
    l[u] = ++cdfn;
    for (int i = 0; i <= 25; i++) {
        if (t[u][i]) dfs1(t[u][i]);
    }
    r[u] = cdfn;
}

int lowbit(int x) { return x & -x; }

void upd(int x, int p) {
    if (x <= 0) return;
    for (int i = x; i; i -= lowbit(i))  
        tr[i] += p;
}

int query(int x) {
    if (x == 0) return 0;
    int ans = 0;
    for (int i = x; i <= cdfn; i += lowbit(i))
        ans += tr[i];
    return ans;
}

void dfs(int u) {
    // cout << "cs2 u = " << u << endl;
    for (auto x : gs[u]) {
        // cout << "gs: " << x << endl;
        upd(r[ts[x]], 1); upd(l[ts[x]] - 1, -1);
    }
    for (auto x : gt[u]) {
        // cout << "gt: " << x << endl;
        ans[x] += query(l[tt[x]]);
    }
    for (int i = 0; i <= 25; i++)
        if (t[u][i]) dfs(t[u][i]);
    for (auto x : gs[u]) {
        upd(r[ts[x]], -1); upd(l[ts[x]] - 1, 1);
    }
    // cout << "qwq" << endl;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);
        int len = strlen(s1 + 1), l, r;
        for (int j = 1; j <= len; j++)
            if (s1[j] != s2[j]) r = j;
        for (int j = len; j >= 1; j--)
            if (s1[j] != s2[j]) l = j;
        Hash hsh = {0, 0};
        for (int j = l; j <= r; j++) {  
            hsh.x = ((hsh.x * bs + s1[j]) * bs + s2[j]) % m1;
            hsh.y = ((hsh.y * bs + s1[j]) * bs + s2[j]) % m2;
        }
        int cnt = 0;
        for (int j = l - 1; j >= 1; j--)
            s[++cnt] = s1[j];
        rtl[hsh] = insert(rtl[hsh], cnt, 0, i);
        cnt = 0;
        for (int j = r + 1; j <= len; j++)
            s[++cnt] = s1[j];
        rtr[hsh] = insert(rtr[hsh], cnt, 1, i);
        a[++tot] = hsh;
    }
    // cout << "qwq" << endl;
    for (int i = 1; i <= q; i++) {
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);
        if (strlen(s1 + 1) != strlen(s2 + 1)) continue;
        int len = strlen(s1 + 1), l, r;
        for (int j = 1; j <= len; j++)
            if (s1[j] != s2[j]) r = j;
        for (int j = len; j >= 1; j--)
            if (s1[j] != s2[j]) l = j;
        Hash hsh = {0, 0};
        for (int j = l; j <= r; j++) {  
            hsh.x = ((hsh.x * bs + s1[j]) * bs + s2[j]) % m1;
            hsh.y = ((hsh.y * bs + s1[j]) * bs + s2[j]) % m2;
        }
        int cnt = 0;
        for (int j = l - 1; j >= 1; j--)
            s[++cnt] = s1[j];
        insert1(rtl[hsh], cnt, 0, i);
        cnt = 0;
        for (int j = r + 1; j <= len; j++)
            s[++cnt] = s1[j];
        insert1(rtr[hsh], cnt, 1, i);
    }
    // cout << "qwq" << endl;

    sort(a + 1, a + tot + 1);
    tot = unique(a + 1, a + tot + 1) - a - 1;
    for (int i = 1; i <= tot; i++) {
        // cout << "i = " << i << endl;
        cdfn = 0;
        dfs1(rtr[a[i]]); dfs(rtl[a[i]]);
        for (int j = 1; j <= cdfn; j++)
            tr[j] = 0;
        // cout << "cdfn = " << cdfn << endl;
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}