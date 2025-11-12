#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
    return (x > y);
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[1005] = {0};
    for (int i = 1; i <= n*m; i++) {
        cin >> a[i];
    }
    int ts = a[1], t_ind=0;
    sort(a + 1, a + n*m + 1, cmp);
    for (int i = 1; i <= n*m; i++) {
        if (a[i] == ts) {
            t_ind = i;
            break;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) { // 列
        if (i % 2 == 1) {
            for (int j = 1; j <= n; j++) { // 行
                cnt++;
                if (cnt == t_ind) {
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
        } else {
            for (int j = n; j >= 1; j--) {
                cnt++;
                if (cnt == t_ind) {
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}