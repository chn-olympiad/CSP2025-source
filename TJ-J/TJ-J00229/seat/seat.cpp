#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 15;

int n, m, a[MAXN * MAXN], s[MAXN][MAXN];

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int r = a[1];
    sort(a + 1, a + (n * m) + 1, greater<int>());
    for (int i = 1; i <= m; i++) {
        if (i % 2 == 0) {
            sort(a + (n * (i - 1)) + 1, a + (n * (i - 1)) + n + 1);
        } else {
            sort(a + (n * (i - 1)) + 1, a + (n * (i - 1)) + n + 1, greater<int>());
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            s[j][i] = a[(n * (i - 1)) + j];
            if (s[j][i] == r) {
                cout << i << " " << j;
                break;
            }
        }
    }
    return 0;
}//期望得分100pts。 
