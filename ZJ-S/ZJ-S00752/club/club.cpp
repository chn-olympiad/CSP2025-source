#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N][10], sum, id, ans;
priority_queue<int> q;
// 记得清空
void solve() {
    cin >> n; sum = ans = 0;
    for (int i = 1;i <= n;i ++)
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    int tot1, tot2, tot3;
    tot1 = tot2 = tot3 = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i][1] > max(a[i][2], a[i][3])) 
            tot1 ++;
        else if (a[i][2] > max(a[i][1], a[i][3])) 
            tot2 ++;
        else 
            tot3 ++;
    }
    for (int i = 1;i <= n;i ++) {
        ans += max(max(a[i][1], a[i][2]), a[i][3]);
    }
    if (tot1 <= n / 2 && tot2 <= n / 2 && tot3 <= n / 2) {
        cout << ans << "\n";
        return ;
    }
    if (tot1 > max(tot2, tot3)) id = 1;
    else if (tot2 > max(tot1, tot3)) id = 2;
    else id = 3;
    int tot = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i][id] >= max(a[i][id % 3 + 1], a[i][(id + 1) % 3 + 1])) {
            tot ++;
            q.push(max(a[i][id % 3 + 1], a[i][(id + 1) % 3 + 1]) - a[i][id]);
            // cout << max(a[i][id % 3 + 1], a[i][(id + 1) % 3 + 1]) - a[i][id] << " ";
        }
    }
    // cout << ans << "\n"; cout << tot << " " << n / 2 << "\n";
    for (int i = tot;i >= n / 2 + 1;i --) {
        // cout << q.top() << " ";
        ans += q.top(); q.pop();
    }
    while (!q.empty()) q.pop();
    cout << ans << "\n";
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T --) solve();
    return 0;
}