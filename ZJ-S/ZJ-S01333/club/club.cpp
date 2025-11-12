#include <bits/stdc++.h>
using namespace std;

int a[100005][3], d[100005], r[100005];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T --) {
        int n, k[3], res = 0;
        k[0] = k[1] = k[2] = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            int ma = max({a[i][0], a[i][1], a[i][2]});
            res += ma;
            for (int j = 0; j < 3; j ++) {
                if (a[i][j] == ma) {
                    ++ k[j];
                    d[i] = j;
                    break;
                }
            }
        }
        if (k[0] <= n / 2 && k[1] <= n / 2 && k[2] <= n / 2) {
            cout << res << '\n';
            continue;
        }
        int D = 0;
        for (int i = 0; i < 3; i ++) {
            if (k[i] > n / 2) {
                D = i;
                break;
            }
        }
        for (int i = 1; i <= n; i ++) {
            if (d[i] != D) {
                r[i] = INT_MAX;
                continue;
            }
            int ma = 0;
            for (int j = 0; j < 3; j ++) {
                if (j != d[i]) ma = max(ma, a[i][j]);
            }
            r[i] = a[i][d[i]] - ma;
        }
        sort(r + 1, r + n + 1);
        for (int i = 1; i <= k[D] - n / 2; i ++) {
            res -= r[i];
        }
        cout << res << '\n';
    }
    return 0;
}