#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool f1;
const int N = 2e5 + 5, M = 2.5e6 + 5;
int n, q, fir[M], nxt[N], son[N], idx;
ll ans[N];
int Fir[M], Nxt[M << 1], Son[M << 1], Id[M << 1], W[M << 1];
string s1, s2;
struct ACAM {
    int nxt[M][26], idx, qu[M], he, tl, fail[M], sz[M], beg[M], dfn[M], rdfn[M];
    int Fir[M], Nxt[M];
    inline int ins(string &str) {
        int len = str.size(), p = 0;
        for(int i = 0; i < len; i++) {
            if(!nxt[p][str[i] - 'a']) nxt[p][str[i] - 'a'] = ++idx;
            p = nxt[p][str[i] - 'a'];
        }
        return p;
    }
    inline void getfail() {
        qu[++tl] = 0, he = 1;
        for(int i = 0; i < 26; i++) if(nxt[0][i]) {
            qu[++tl] = nxt[0][i];
        }
        int x;
        while(he < tl) {
            x = qu[++he];
            for(int i = 0; i < 26; i++) {
                if(nxt[x][i]) {
                    fail[nxt[x][i]] = nxt[fail[x]][i], qu[++tl] = nxt[x][i];
                }
                else {
                    nxt[x][i] = nxt[fail[x]][i];
                }
            }
        }
    }
    inline void getdfn() {
        for(int i = tl, x; i > 1; i--) {
            x = qu[i];
            sz[x]++, sz[fail[x]] += sz[x];
        }
        beg[0] = dfn[0] = 1;
        for(int i = 2, x; i <= tl; i++) {
            x = qu[i];
            beg[x] = dfn[x] = beg[fail[x]] + 1, beg[fail[x]] += sz[x];
        }
        for(int i = 0; i <= idx; i++) rdfn[dfn[i]] = i;
        for(int i = 1, x; i <= tl; i++) {
            x = qu[i];
            Nxt[x] = Fir[beg[x] + 1], Fir[beg[x] + 1] = x;
        }
    }
    inline void print() {
        for(int i = 0; i <= idx; i++) {
            printf("x = %d, fail = %d, sz = %d, dfn = %d, ou = %d, nxt = ", i, fail[i], sz[i], dfn[i], beg[i]);
            for(int j = 0; j < 26; j++) if(nxt[i][j]) printf("[%d] = %d ", j, nxt[i][j]);puts("");
        }
        printf("bfs order : ");for(int i = 1; i <= tl; i++) printf("%d ", qu[i]);puts("");
        printf("dfs order : ");for(int i = 1; i <= tl; i++) printf("%d ", rdfn[i]);puts("");
        puts("");
    }
}A1, A2;
struct BIT {
    int c[M], n;
    inline void upd(int x, int v) {
        while(x <= n) {
            // cerr << "bit-upd " << x << ' ' << v << '\n';
            c[x] += v, x += x & -x;
        }
    }
    inline int get(int x) {
        int res = 0;
        while(x) {
            // cerr << "bit-get " << x << ' ' << c[x] << '\n';
            res += c[x], x -= x & -x;
        }
        return res;
    }
    inline void modify(int l, int r, int v) {
        upd(l, v), upd(r + 1, -v);
    }
}bit;
bool f2;
int main() {
    // printf("%.2lfMB\n", (&f2 - &f1) / 1024.0 / 1024.0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1, x, y; i <= n; i++) {
        cin >> s1 >> s2;
        x = A1.ins(s1), y = A2.ins(s2);
        nxt[i] = fir[x], fir[x] = i, son[i] = y;
    }
    A1.getfail(), A2.getfail();
    A1.getdfn(), A2.getdfn();
    // cerr << A1.idx << ' ' << A2.idx << '\n';
    // A1.print(), A2.print();
    for(int I = 1, L, R, len, p1, p2, len2; I <= q; I++) {
        cin >> s1 >> s2;
        L = R = -1, len = s1.size(), len2 = s2.size();
        if(len ^ len2) continue ;
        for(int j = 0; j < len; j++) if(s1[j] != s2[j]) {L = j; break ;}
        for(int j = len - 1; ~j; j--) if(s1[j] != s2[j]) {R = j; break ;}
        p1 = p2 = 0;
        for(int i = 0; i < len; i++) {
            p1 = A1.nxt[p1][s1[i] - 'a'], p2 = A2.nxt[p2][s2[i] - 'a'];
            if(i >= R) idx++, Nxt[idx] = Fir[p1], Fir[p1] = idx, Son[idx] = p2, Id[idx] = I, W[idx] = 1;
        }
        p1 = p2 = 0;
        for(int i = L + 1; i < len; i++) {
            p1 = A1.nxt[p1][s1[i] - 'a'], p2 = A2.nxt[p2][s2[i] - 'a'];
            if(i >= R) idx++, Nxt[idx] = Fir[p1], Fir[p1] = idx, Son[idx] = p2, Id[idx] = I, W[idx] = -1;
        }
    }
    bit.n = A2.idx + 1;
    // cerr << idx << '\n';
    auto upd = [&](int x, int v) {
        // cerr << "Update " << x << ' ' << v << '\n';
        for(int i = fir[x]; i; i = nxt[i]) {
            // cerr << "upd " << i << ' ' << v << ' ' << A2.dfn[son[i]] << ' ' << A2.beg[son[i]] << '\n';
            bit.modify(A2.dfn[son[i]], A2.beg[son[i]], v);
        }
    };
    for(int i = 1, x; i <= A1.tl; i++) {
        x = A1.rdfn[i];
        // cerr << "tim " << i << ' ' << A1.rdfn[i] << '\n';
        for(int j = A1.Fir[i]; j; j = A1.Nxt[j]) {
            upd(j, -1);
        }
        upd(x, 1);
        for(int j = Fir[x]; j; j = Nxt[j]) {
            // cerr << "query " << Id[j] << ' ' << W[j] << ' ' << Son[j] << ' ' << A2.dfn[Son[j]] << '\n';
            ans[Id[j]] += W[j] * bit.get(A2.dfn[Son[j]]);
        }
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}