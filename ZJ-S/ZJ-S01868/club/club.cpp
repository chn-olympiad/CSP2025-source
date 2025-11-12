#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int T, n, a[N][3], f[N], num[3], ans, b[N], cnt;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        num[0] = num[1] = num[2] = 0;
        ans = 0; cnt = 0;

        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        // cout << "qwq" << endl;
        for (int i = 1; i <= n; i++) {
            int mx = -1, u = 0;
            for (int j = 0; j <= 2; j++)
                if (a[i][j] > mx) mx = a[i][j], u = j;
            f[i] = u; num[u]++; ans += mx;
        }
        int flg = -1;
        for (int i = 0; i <= 2; i++)  
            if (num[i] > n / 2) flg = i;
        if (flg == -1) {
            printf("%d\n", ans); continue;
        }
        // cout << "qwqwq " << flg << endl;
        for (int i = 1; i <= n; i++) {
            if (f[i] == flg) {
                int mx = -1;
                for (int j = 0; j <= 2; j++)
                    if (j != flg) mx = max(mx, a[i][j]);
                b[++cnt] = mx - a[i][flg];
            }
        }
        // cout << "cnt = " << cnt << endl;
        sort(b + 1, b + cnt + 1);
        for (int i = cnt; i >= n / 2 + 1; i--)
            ans += b[i];
        printf("%d\n", ans);
    }
    return 0;
}