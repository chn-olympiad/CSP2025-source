#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5, inf = 1e16;

int n, m, ct[4];
struct stu {
    int a[4], mx1, mx2, sub;
} s[N];
void solve() {
    int ans = 0;
    cin >> n;
    ct[1] = ct[2] = ct[3] = 0;
    F(i, 1, n) {
        int mx1 = 0, mx2 = 0;
        F(j, 1, 3) {
            cin >> s[i].a[j];
            if (!mx1 || s[i].a[j] >= s[i].a[mx1]) {
                mx2 = mx1, mx1 = j;
            } else if (!mx2 || s[i].a[j] > s[i].a[mx2]) {
                mx2 = j;
            }
        }
        s[i].mx1 = mx1, s[i].mx2 = mx2;
        s[i].sub = - s[i].a[mx1] + s[i].a[mx2];
        ans += s[i].a[mx1], ct[mx1]++;
    }
    F(t, 1, 3) if (ct[t] > n / 2) {
        vector<int> ve;
        F(i, 1, n) {
            if (s[i].mx1 == t) {
                ve.push_back(s[i].sub);
            }
        }
        sort(ve.begin(), ve.end());
        while (ct[t] > n / 2) {
            ans += ve.back();
            ve.pop_back();
            ct[t]--;
        }
        break;
    }
    cout << ans << '\n';
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}