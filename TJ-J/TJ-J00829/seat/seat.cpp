#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, R;
    int cnt = 0;
    cin >> n >> m >> R;
    for (int i = 1; i <= n * m - 1; i++) {
        int temp;
        cin >> temp;
        if (temp > R) cnt++;
    }
    int ans1 = cnt / m + 1;
    int flag = ans1 % 2;
    cnt %= m;
    int ans2 = 0;
    if (flag == 1) {
        ans2 = cnt + 1;
    } else {
        ans2 = m - cnt;
    }
    cout << ans1 << " " << ans2;
    return 0;
}
