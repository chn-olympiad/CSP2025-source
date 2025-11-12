#include "bits/stdc++.h"
#define F(i,x,y) for (int i = (x); i <= (y); ++ i)
#define D(i,x,y) for (int i = (x); i >= (y); -- i)
#define ll long long
#define OPEN freopen ("road.in", "r", stdin); freopen ("road.out", "w", stdout);
#define IOS ios :: sync_with_stdio (false); cin.tie (0); cout.tie (0);

constexpr int N = 1e4 + 5, L = 1.2e6;

using namespace std;

int n, m, k;
struct Info {
    int x, y;
    ll d;
} t[L], t2[L];
int fa[N];

ll a[N][12];

int find (int x) {
    if (fa[x] == x) return x;
    return fa[x] = find (fa[x]);
}

int Merge (int x, int y) {
    int rx = find (x), ry = find (y);
    if (rx == ry) return 0;
    fa[rx] = ry;
    return 1;
}

void Sol1 () {
    ll ans = 0LL;
    int cnt = m;
    ll mx = 0LL;
    F (i, 1, n + 10) fa[i] = i;
    F (i, 1, k) {
        F (l, 1, n) t[++ cnt] = {n + i, l, a[l][i]};
    }

    sort (t + 1, t + cnt + 1, [] (Info x, Info y) {
        return x.d < y.d;
    }) ;

    F (j, 1, cnt) {
        if (Merge (t[j].x, t[j].y)) ans += t[j].d;
    }
    cout << ans << '\n';
}
constexpr ll inf = 1ll * 1e18;
ll ans = inf;
ll c[N];

int main () {
    OPEN IOS
    cin >> n >> m >> k;
    F (i, 1, m)
        cin >> t[i].x >> t[i].y >> t[i].d;
    F (j, 1, k) { cin >> c[j];
        F (i, 1, n)
        cin >> a[i][j];
    }
    if (k > 5) {
        Sol1 (); 
        return 0;
    }

    sort (t + 1, t + m + 1, [] (Info x, Info y) {
        return x.d < y.d;
    }) ;

    F (i, 0, (1 << k) - 1) {
        int cnt = 0;
        ll res = 0LL;
        F (j, 1, n + 5) fa[j] = j;
        F (j, 0, k - 1) {
            if (i & (1 << j)) {
                F (l, 1, n) t2[++ cnt] = {n + j + 1, l, a[l][j + 1]};
                res += c[j + 1];
            }
        }

        sort (t2 + 1, t2 + cnt + 1, [] (Info x, Info y) {
            return x.d < y.d;
        }) ;

        for (int j = 1, k = 1; j <= m || k <= cnt; ) {
            // cerr << j << ' ' << k << '\n';
            // assert (k <= m);
            if (j <= m && (k > cnt || t2[k].d >= t[j].d))
                if (Merge (t[j].x, t[j].y)) res += t[j].d, ++ j;
                else ++ j;
            else
                if (Merge (t2[k].x, t2[k].y)) res += t2[k].d, ++ k;
                else ++ k;
        }

        ans = min (ans, res);
    }
    cout << ans << '\n';
    return 0;
}