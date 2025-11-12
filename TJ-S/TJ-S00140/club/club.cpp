#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5 + 5, MAXJ = 8;

int t, n, cnt[MAXJ], a[MAXN][MAXJ], a1[MAXN];

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        bool checkA = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
                if (a[i][2] != 0 || a[i][3] != 0) {
                    checkA = 0;
                }
            }
        }
        if (checkA) {
            memset(a1, 0, sizeof(a1));
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                a1[i] = a[i][1];
            }
            sort(a1 + 1, a1 + n + 1, greater<int>());
            for (int i = 1; i <= n / 2; i++) {
                sum += a1[i];
            }
            cout << sum << "\n";
            continue;
        }
        int ans = 0, cnt1 = 0, a2 = 0, a3 = 0, a4 = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= n; j++) {
                if (cnt[i] <= n / 2) {
                    if (i == 1) {
                        a2 += a[i][j];
                        cnt[i]++;
                    } else if (i == 2) {
                        a3 += a[i][j];
                        cnt[i]++;
                    } else {
                        a4 += a[i][j];
                        cnt[i]++;
                    }
                    cnt1 += a2 + a3 + a4;
                    ans = max(ans, cnt1);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}//5ptsQAQ
