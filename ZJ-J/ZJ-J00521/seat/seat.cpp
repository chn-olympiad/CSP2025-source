#include <bits/stdc++.h>

using namespace std;


int a[105];

bool cmp(int a, int b) {
    return a > b;
}
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        scanf("%d", &a[i]);
    }
    int t = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int nx = 1, ny = 1;//lie hang
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == t) {
            cout << nx << " " << ny;return 0;
        }
        if (nx & 1) {
            if (ny != n) {
                ny++;
            }else {
                nx++;
            }
        }else {
            if (ny != 1) {
                ny--;
            }else {
                nx++;
            }
        }
    }
    return 0;
}