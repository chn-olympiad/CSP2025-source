#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define P emplace_back
#define pii pair<ll, ll>
#define fi first
#define se second
bool MBE;
namespace SOLVER {
const int N = 2e5 + 5, NN = 1e7 + 1e6; const ll M1 = 10000000000037ll, M2 = 10000000000051ll, P1 = 43, P2 = 23333;
int n, q, t[NN][26], vis[NN], in[NN], out[NN], tim, cnt, pos[2][2][N]; map<pii, int> rt1, rt2;
string s1, s2; vector<pii> add[4 * N], qry[4 * N]; int tt[4 * N], ans[N];
void ADD(int x, int v) {for(int i = x; i <= tim; i += i & -i) tt[i] += v;}
int QRY(int x, int s = 0) {for(int i = x; i; i -= i & -i) s += tt[i]; return s;}
void dfs(int u) {
    in[u] = tim + 1; if(vis[u]) tim++;
    rep(i, 0, 25) if(t[u][i]) dfs(t[u][i]);
    out[u] = tim;
}
void MAIN() {
    cin >> n >> q;
    rep(op, 0, 1) {
        int lim = op == 0 ? n : q;
        rep(i, 1, lim) {
            cin >> s1 >> s2; if(s1.length() != s2.length()) continue;
            int len = s1.length(), l = 0, r = len - 1;
            while(l < len && s1[l] == s2[l]) l++;
            while(r >= 0 && s1[r] == s2[r]) r--;
            if(l > r) continue; pii c = {0, 0};
            rep(j, l, r) {
                c.fi = (c.fi * P2 + s1[j] * P1 + s2[j]) % M1;
                c.se = (c.se * P2 + s1[j] * P1 + s2[j]) % M2;
            }
            // cerr << c.fi << ' ' << c.se << endl;
            if(!rt1.count(c)) {
                if(op == 0) rt1[c] = ++cnt, rt2[c] = ++cnt;
                else continue;
            }
            pos[op][0][i] = rt1[c], pos[op][1][i] = rt2[c];
            per(j, l - 1, 0) {
                if(!t[pos[op][0][i]][s1[j] - 'a']) {
                    if(op == 0) t[pos[op][0][i]][s1[j] - 'a'] = ++cnt;
                    else break;
                }
                pos[op][0][i] = t[pos[op][0][i]][s1[j] - 'a']; 
            }
            rep(j, r + 1, len - 1) {
                if(!t[pos[op][1][i]][s1[j] - 'a']) {
                    if(op == 0) t[pos[op][1][i]][s1[j] - 'a'] = ++cnt;
                    else break;
                }
                pos[op][1][i] = t[pos[op][1][i]][s1[j] - 'a'];
            }
            vis[pos[op][0][i]]++, vis[pos[op][1][i]]++;
        }
    }
    // cerr << 111 << endl;
    for(auto [x, u] : rt1) dfs(u); for(auto [x, u] : rt2) dfs(u);
    // rep(i, 1, cnt) {
        // rep(j, 0, 25) if(t[i][j]) cerr << i << ' ' << j << ' ' << t[i][j] << endl;
    // }
    // cerr << 222 << endl;
    // assert(tim <= 2 * (n + q));
    rep(i, 1, n) if(pos[0][0][i] && pos[0][1][i]) {
        // assert(in[pos[0][1][i]] && (out[pos[0][1][i]] + 1));
        add[in[pos[0][0][i]]].P(in[pos[0][1][i]], out[pos[0][1][i]]);
        add[out[pos[0][0][i]] + 1].P(-in[pos[0][1][i]], -out[pos[0][1][i]]);
    }
    // cerr << 333 << endl;
    rep(i, 1, q) if(pos[1][0][i] && pos[1][1][i]) 
        qry[in[pos[1][0][i]]].P(in[pos[1][1][i]], i);
    // cerr << 444 << endl;
    rep(i, 1, tim) {
        for(auto [l, r] : add[i]) {
            int v = 1; if(l < 0) v = -1, l *= -1, r *= -1;
            ADD(l, v), ADD(r + 1, -v);
        }
        for(auto [x, id] : qry[i]) ans[id] = QRY(x);
    }
    rep(i, 1, q) cout << ans[i] << '\n';
}
}
bool MED;
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    SOLVER::MAIN();
    cerr << (&MBE - &MED) / 1024 << " kb, " << clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
} 