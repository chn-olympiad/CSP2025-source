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
const int N = 20,M = (1 << 18) + 10,MOD = 998244353;
int n,m;
char str[N];
int a[N];
int f[M][N];
int ppc[M];
void mian () {
    cin >> n >> m >> str + 1;
    for (int i = 1;i < 1 << n;i++) ppc[i] = ppc[i - (i & -i)] + 1;
    for (int i = 1;i <= n;i++) cin >> a[i];
    f[0][0] = 1;
    for (int s = 0;s < 1 << n;s++) {
        for (int i = 1;i <= n;i++) {
            if (s >> i - 1 & 1) continue;
            for (int c = 0;c <= n;c++) {
                int v = str[ppc[s] + 1] == '0' || c >= a[i];
                (f[s | (1 << i - 1)][c + v] += f[s][c]) %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0;i <= n - m;i++) (ans += f[(1 << n) - 1][i]) %= MOD;
    cout << ans << endl;
}
signed main () {
    freopen ("employ.in","r",stdin);
    freopen ("employ.out","w",stdout);
    int T = 1;
    // cin >> T;
    while (T--) mian ();
    return 0;
}