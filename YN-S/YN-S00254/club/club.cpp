#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][4];

struct node {
    int num;
    int t[4];
} dp[N][4];

int main() {
    freopen("club.in", "r", stdin);
    freopen("clud.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++)
                cin >> a[i][j];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++)
                    if (dp[i - 1][k].t[j] + 1 <= n / 2)
                        if (dp[i][j].num < dp[i - 1][k].num + a[i][j]) {
                            dp[i][j].t[j - 1]--;
                            dp[i][j].num = dp[i - 1][k].num + a[i][j];
                            dp[i][j].t[j]++;
                        }
            }
        }
        int maxx = INT_MIN;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                maxx = max(maxx, dp[i][j].num);
            }
        }
        cout << maxx;
    }
    return 0;
}