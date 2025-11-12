#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e5+7, cetn = 307;
int t;
int n;
struct node {
    int a[5];
    pair<int, int> s[5];
    #define x first
    #define y second
    bool operator<(node const &p) const {
        if (s[1].y == p.s[1].y) {
            if (s[2].y == p.s[2].y)
                return s[3].y > p.s[3].y;
            else
                return s[2].y > p.s[2].y;
        }
        return s[1].y > p.s[1].y;
    }
    #undef x
    #undef y
};
node a[maxn];
int dp[cetn][cetn][cetn];

bool cmp(pair<int, int> u, pair<int, int> v) {
    return u.second > v.second;
}

signed main(signed argc, char const *argv[]) {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].a[1] >> a[i].a[2] >> a[i].a[3];
            a[i].s[1] = make_pair(1, a[i].a[1]);
            a[i].s[2] = make_pair(2, a[i].a[2]);
            a[i].s[3] = make_pair(3, a[i].a[3]);
            sort(a[i].s + 1, a[i].s + 4, cmp);
        }
        if (n > 200) {
            sort(a + 1, a + n + 1);
            int c[5] = {0};
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= 3; j++) {
                    int k = a[i].s[j].first;
                    if (c[k] < n / 2) {
                        c[k]++;
                        ans += a[i].s[j].second;
                        break;
                    }
                }
            }
            cout << ans << endl;
        } else {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                for (int j1 = 0; j1 <= i; j1++)
                    for (int j2 = 0; j2 <= i; j2++) {
                        int j3 = i - j1 - j2;
                        if (j3 > (i + 3) / 2 || j3 < 0)
                            continue;
                        int &ret = dp[i][j1][j2];
                        ret = 0;
                        if (j1)
                            ret = max(ret, dp[i - 1][j1 - 1][j2] + a[i].a[1]);
                        if (j2)
                            ret = max(ret, dp[i - 1][j1][j2 - 1] + a[i].a[2]);
                        if (j3)
                            ret = max(ret, dp[i - 1][j1][j2] + a[i].a[3]);
                    }
            for (int j1 = 0; j1 <= n / 2; j1++)
                for (int j2 = 0; j2 <= n / 2; j2++) {
                    int j3 = n - j1 - j2;
                    if (j3 > n / 2)
                        continue;
                    ans = max(ans, dp[n][j1][j2]);
                }
            cout << ans << endl;
        }
    }
    return 0;
}