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
const int N = 200010,M = 1100010;
int n,m,k;
struct e_type {
    int a,b,w,id;
}e[M],e2[M];
int w[M];
bool vis[M];
int a[20][N];
int p[N],h[N];
bool cmp (e_type i,e_type j) {
    return i.w < j.w;
}
int find (int x) {
    return p[x] == x ? x : p[x] = find (p[x]);
}
void merge (int x,int y) {
    if (h[x] == h[y]) {
        p[x] = y;
        h[y]++;
        return ;
    }
    if (h[x] < h[y]) swap (x,y);
    p[y] = x;
}
void mian () {
    int S = clock ();
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++) cin >> e[i].a >> e[i].b >> e[i].w;
    for (int i = 1;i <= k;i++) {
        for (int j = 0;j <= n;j++) cin >> a[i][j];
    }
    sort (e + 1,e + m + 1,cmp);
    for (int i = 1;i <= n;i++) p[i] = i;
    for (int i = 1;i <= m;i++) {
        int a = find (e[i].a),b = find (e[i].b);
        if (a == b) continue;
        vis[i] = 1;
        merge (a,b);
    }
    int mm = 0;
    for (int i = 1;i <= m;i++) if (vis[i]) e2[++mm] = e[i];
    m = mm;
    for (int i = 1;i <= m;i++) e[i] = e2[i];
    for (int i = 1;i <= k;i++) {
        for (int j = 1;j <= n;j++) m++,e[m].a = j,e[m].b = n + i,e[m].w = a[i][j],e[m].id = i;
    }
    sort (e + 1,e + m + 1,cmp);
    LL ans = 1e18;
    for (int s = 0;s < 1 << k;s++) {
        LL res = 0;
        for (int i = 1;i <= n + k;i++) p[i] = i,h[i] = 0;
        for (int i = 1;i <= k;i++) if (s >> i - 1 & 1) res += a[i][0];
        for (int i = 1;i <= m;i++) {
            if (e[i].id && !(s >> e[i].id - 1 & 1)) continue;
            int a = find (e[i].a),b = find (e[i].b);
            if (a == b) continue;
            vis[i] = 1;
            res += e[i].w;
            merge (a,b);
        }
        tomin (ans,res);
    }
    cout << ans << endl;
    int T = clock ();
    // cout << "time: " << (double)(T - S) / (CLOCKS_PER_SEC) << endl;
}
signed main () {
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    int T = 1;
    // cin >> T;
    while (T--) mian ();
    return 0;
}
