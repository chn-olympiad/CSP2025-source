#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 1e6 + 5;
int n;
struct node {
    int x, y, z, mx, del;
}a[maxn];
bool cmp(node x, node y) {
    if (x.del == y.del)
        return x.mx > y.mx;
    return x.del > y.del;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) a[i].x = a[i].y = a[i].z = a[i].mx = a[i].del = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].mx = max(a[i].x, max(a[i].y, a[i].z));
        if (a[i].mx == a[i].x) {
            a[i].del = a[i].mx - max(a[i].y, a[i].z);
        }
        else if (a[i].mx == a[i].y) {
            a[i].del = a[i].mx - max(a[i].x, a[i].z);
        }
        else if (a[i].mx == a[i].z) {
            a[i].del = a[i].mx - max(a[i].y, a[i].x);
        }
    }
    int one = 0, two = 0, three = 0, ans = 0;
    sort(a + 1, a + 1 + n, cmp);
    // debug
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << endl;
    // }
    for (int i = 1; i <= n; i++) {
        if (a[i].x == a[i].mx) {
            if (one >= n / 2) {
                if (a[i].y > a[i].z) {
                	ans += a[i].y;
					two++;
				}
                else {
                	ans += a[i].z;
					three++;
				}
            }
            else {
                ans += a[i].x;
                one++;
            }
        }
        else if (a[i].y == a[i].mx) {
            if (two >= n / 2) {
                if (a[i].x > a[i].z) {
                	ans += a[i].x;
					one++;
				}
                else
                    ans += a[i].z, three++;
            }
            else {
                ans += a[i].y;
                two++;
            }
        }
        else if (a[i].z == a[i].mx) {
            if (three >= n / 2) {
                if (a[i].x > a[i].y)
                    ans += a[i].x, one++;
                else
                    ans += a[i].y, two++;
            }
            else {
                ans += a[i].z;
                three++;
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
