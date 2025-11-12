#include <bits/stdc++.h>
#define int long long
#define rep(i, r) for(int i = 1; i <= r; i++)
#define Rep(i, l, r) for(int i = l; i <= r; i++)
#define lep(i, r) for(int i = r; i; i--)
#define Lep(i, l, r) for(int i = r; i >= l; i--)
using namespace std;
const int N = 1e5 + 5;
//bool p1;
int n, cnt[3];
long long ans;
struct node {
    int x, del;
} a[3][N];
void calc(int x) {
    stable_sort(a[x] + 1, a[x] + cnt[x] + 1, [](node x, node y) {
        return x.del < y.del;
    });
    rep(i, cnt[x] - (n >> 1)) ans -= a[x][i].del;
}
void solve() {
    ans = cnt[0] = cnt[1] = cnt[2] = 0;
    cin >> n;
    rep(i, n) {
        int x, y, z, maxx;
        cin >> x >> y >> z;
        maxx = max({x, y, z});
        ans += maxx;
        if(maxx == x) a[0][++cnt[0]] = {x, x - max(y, z)};
        if(maxx == y) a[1][++cnt[1]] = {y, y - max(x, z)};
        if(maxx == z) a[2][++cnt[2]] = {z, z - max(y, x)};
    }
    if(cnt[0] > (n >> 1)) calc(0);
    if(cnt[1] > (n >> 1)) calc(1);
    if(cnt[2] > (n >> 1)) calc(2);
    cout << ans << '\n';
}
//bool p2;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
//    cerr << "Memory Used:" << (&p2 - &p1) / 1024.0 / 1024.0 << "Mb.";
    int T;
    cin >> T;
    while(T--) solve();
    return 0; 
}
//chzx_lfw AK IOI!!!!!