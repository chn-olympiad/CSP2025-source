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
const int N = 100010;
int n;
int a[N][3];
int id[N];
int cnt[3];
void mian () {
    cin >> n;
    for (int i = 0;i < 3;i++) cnt[i] = 0;
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        id[i] = 0;
        for (int j = 0;j < 3;j++) {
            cin >> a[i][j];
            if (a[i][j] > a[i][id[i]]) id[i] = j;
        }
        ans += a[i][id[i]];
        cnt[id[i]]++;
    }
    int p = 0;
    for (int i = 0;i < 3;i++) if (cnt[i] > cnt[p]) p = i;
    if (cnt[p] > n / 2) {
        vector <int> v;
        for (int i = 1;i <= n;i++) {
            if (id[i] != p) continue;
            int minx = 1e9;
            for (int j = 0;j < 3;j++) {
                if (j == id[i]) continue;
                tomin (minx,a[i][id[i]] - a[i][j]);
            }
            v.pb (minx);
        }
        sort (v.begin (),v.end ());
        for (int i = 0;i < cnt[p] - n / 2;i++) ans -= v[i];
    }
    cout << ans << endl;
}
signed main () {
    freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);
    int T = 1;
    cin >> T;
    while (T--) mian ();
    return 0;
}