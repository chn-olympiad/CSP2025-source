#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define IOS ios :: sync_with_stdio (false),cin.tie (0),cout.tie (0)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
template <typename T1,typename T2> void tomax (T1 &x,T2 y) {
    if (y > x) x = y;
}
template <typename T1,typename T2> void tomin (T1 &x,T2 y) {
    if (y < x) x = y;
}
int fastio = (IOS,0);
#define endl '\n'
#define puts(s) cout << s << endl
const int N = 400010,M = 5000010,BASE = 13331,MOD = 1e9 + 9;
int n,q;
string s[N];
LL pw[M];
vector <LL> h[N];
int tr[M][26];
int len[M],fail[M];
vector <int> id[M];
int idx;
int que[M];
void insert (int ID,string s) {
    int u = 0;
    for (int i = 1;i < s.size ();i++) {
        int t = s[i] - 'a';
        if (!tr[u][t]) {
            tr[u][t] = ++idx;
            len[tr[u][t]] = len[u] + 1;
        }
        u = tr[u][t];
    }
    id[u].pb (ID);
}
void build () {
    int hh = 0,tt = -1;
    for (int i = 0;i < 26;i++) {
        if (tr[0][i]) que[++tt] = tr[0][i];
    }
    while (hh <= tt) {
        int u = que[hh++];
        for (int i = 0;i < 26;i++) {
            int &v = tr[u][i];
            if (!v) v = tr[fail[u]][i];
            else {
                fail[v] = tr[fail[u]][i];
                que[++tt] = v;
            }
        }
    }
}
LL H (int i,int l,int r) {
    if (l > r) return 0;
    return (h[i][r] - h[i][l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
}
void mian () {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        int m = s[i].size ();
        s[i] = ' ' + s[i];
        insert (i,s[i]);
        cin >> s[i];
        s[i] = ' ' + s[i];
        h[i].pb (0);
        for (int j = 1;j <= m;j++) h[i].pb ((h[i].back () * BASE + s[i][j] - 'a' + 1) % MOD);
    }
    build ();
    string s1,s2;
    while (q--) {
        cin >> s1 >> s2;
        if (s1.size () != s2.size ()) {
            puts ("0");
            continue;
        }
        int m = s1.size ();
        s1 = ' ' + s1,s2 = ' ' + s2;
        h[n + 1].clear (),h[n + 2].clear ();
        h[n + 1].pb (0),h[n + 2].pb (0);
        for (int i = 1;i <= m;i++) {
            h[n + 1].pb ((h[n + 1].back () * BASE + s1[i] - 'a' + 1) % MOD);
            h[n + 2].pb ((h[n + 2].back () * BASE + s2[i] - 'a' + 1) % MOD);
        }
        int u = 0;
        int ans = 0;
        int p1 = 0,p2 = m + 1;
        while (p1 + 1 <= m && s1[p1 + 1] == s2[p1 + 1]) p1++;
        while (p2 - 1 >= 1 && s1[p2 - 1] == s2[p2 - 1]) p2--;
        int l = p2 - p1 - 1;
        for (int i = 1;i <= m;i++) {
            int t = s1[i] - 'a';
            u = tr[u][t];
            int tmp = u;
            if (i < p2 - 1) continue;
            while (tmp) {
                if (i - len[tmp] + 1 > p1 + 1) break;
                if (id[tmp].size ()) {
                    for (int _p = 0,p;_p < id[tmp].size ();_p++) {
                        p = id[tmp][_p];
                        int l = i - len[tmp] + 1,r = i;
                        if (H (n + 1,1,l - 1) == H (n + 2,1,l - 1) && H (p,1,len[tmp]) == H (n + 2,l,r) && H (n + 1,r + 1,m) == H (n + 2,r + 1,m)) ans++;
                    }
                }
                tmp = fail[tmp];
            }
        }
        cout << ans << endl;
    }
}
signed main () {
    freopen ("replace.in","r",stdin);
    freopen ("replace.out","w",stdout);
    pw[0] = 1;
    for (int i = 1;i < M;i++) pw[i] = pw[i - 1] * BASE % MOD;
    int T = 1;
    // cin >> T;
    while (T--) mian ();
    return 0;
}