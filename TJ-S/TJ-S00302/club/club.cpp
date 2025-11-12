#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 2e9 + 7;
int n, a[N][3], cnt[3];
int solve() {
    cin >> n;
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) cnt[0]++;
        else if (a[i][1] >= a[i][2]) cnt[1]++;
        else cnt[2]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += *max_element(a[i], a[i] + 3);
    if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) return ans;
    int k = 0;
    for (int i = 1; i <= 2; i++) if (cnt[i] > n / 2) k = i;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < 3; j++) if (a[i][j] > a[i][k]) {
            flag = false;
            break;
        }
        if (flag) {
            int mx = -inf;
            for (int j = 0; j < 3; j++) if (j != k) mx = max(mx, a[i][j] - a[i][k]);
            b.push_back(mx);
        }
    }
    sort(b.begin(), b.end(), greater<int>());
    assert(b.size() > n / 2);
    for (int i = 0; i < (int)b.size() - n / 2; i++) ans += b[i];
    return ans;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
