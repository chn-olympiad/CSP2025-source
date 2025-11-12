#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 3.5e2 + 8;
int n, ori[maxn][3 + 8];
long long f[maxn][maxn][maxn];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> ori[i][j];
            }
        }
        memset(f, 0, sizeof(f));
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int E = min(i, n/2);
            for (int a = E; a >= 0; a--) {
                for (int b = E; b >= 0; b--) {
                    if (a + b > n) continue;
                    for (int c = E; c >= 0; c--) {
                        if (a + b + c > n) continue;
                        if (a >= 1) f[a][b][c] = max(f[a][b][c], f[a - 1][b][c] + ori[i][1]);
                        if (b >= 1) f[a][b][c] = max(f[a][b][c], f[a][b - 1][c] + ori[i][2]);
                        if (c >= 1) f[a][b][c] = max(f[a][b][c], f[a][b][c - 1] + ori[i][3]);
                        ans = max(ans, f[a][b][c]);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
