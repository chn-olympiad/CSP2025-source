#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for(int i = (int)(a); i <= (int)(b); i ++)
#define DOW(i, a, b) for(int i = (int)(a); i >= (int)(b); i --)
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define poly vector<int>
const int N = 1e5 + 5;
int n, id[N], cnt[5];
pii a[N][5];
bool cmp(int x, int y) {
    if(a[x][1].fi != a[y][1].fi) return a[x][1].fi > a[y][1].fi;
    if(a[x][2].fi != a[y][2].fi) return a[x][2].fi > a[y][2].fi;
    return a[x][3].fi > a[y][3].fi;
}
void Solve() {
    cin >> n;
    int ans = 0;
    REP(i, 1, 3) cnt[i] = 0;
    REP(i, 1, n) REP(j, 1, 3) cin >> a[i][j].fi, a[i][j].se = j;
    REP(i, 1, n) sort(a[i] + 1, a[i] + 4, greater<pii>());
    REP(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    priority_queue<int, poly, greater<int>> q[4];
    REP(i, 1, n) {
        // int i = id[op];
        q[a[i][1].se].push(a[i][1].fi - a[i][2].fi);
        ans += a[i][1].fi, cnt[a[i][1].se] ++;
        if(cnt[a[i][1].se] > n / 2) {
            ans -= q[a[i][1].se].top();
            q[a[i][1].se].pop(); cnt[a[i][1].se] --;
        }
    }
    // cerr << n / 2 << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << '\n';
    cout << ans << '\n';
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}