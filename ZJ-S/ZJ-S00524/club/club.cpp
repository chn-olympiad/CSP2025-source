#include <bits/stdc++.h>
#define int long long
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define rep(i, x, y) for (int i = (x); i >= (y); i--)
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define pb emplace_back
#define all(v) (v).begin(), (v).end()
using namespace std;
const int N = 1e5 + 5;
int n;
pii a[N][3];
void Main() {
    cin >> n;
    int ans = 0, cnt[3] = {0, 0, 0};
    For (i, 1, n) {
        For (j, 0, 2) {
            cin >> a[i][j].fi; a[i][j].se = j;
        }
        sort(a[i], a[i] + 3, [&](pii x, pii y) {
            return x > y;
        });
        ans += a[i][0].fi;
        cnt[a[i][0].se]++;
    }
    int pos = -1;
    For (i, 0, 2) {
        if (cnt[i] > n / 2) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << ans << '\n';
        return;
    }
    vi val;
    For (i, 1, n) {
        if (a[i][0].se == pos) {
            val.pb(a[i][1].fi - a[i][0].fi);
        }
    }
    sort(all(val), [&](int x, int y) {
        return x > y;
    });
    For (i, 0, cnt[pos] - n / 2 - 1) ans += val[i];
    cout << ans << '\n';
    return;
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) Main();
    return 0;
}