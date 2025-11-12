#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 1e5 + 5;

int n, maxn[N];
array<int, 3> stu[N];
ll ans, res;
ll dp[2][2500][2500];

void dfs(int now, int cnt1, int cnt2, int cnt3) {
    if (now > n) {
        ans = max(ans, res);
        return;
    }
    if (cnt1 < n / 2) {
        res += stu[now][0];
        dfs(now + 1, cnt1 + 1, cnt2, cnt3);
        res -= stu[now][0];
    }
    if (cnt2 < n / 2) {
        res += stu[now][1];
        dfs(now + 1, cnt1, cnt2 + 1, cnt3);
        res -= stu[now][1];
    }
    if (cnt3 < n / 2) {
        res += stu[now][2];
        dfs(now + 1, cnt1, cnt2, cnt3 + 1);
        res -= stu[now][2];
    }
}

int flg2 = 1, flg3 = 1;

void solve() {
    cin >> n;
    ans = 0;
    res = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> stu[i][0] >> stu[i][1] >> stu[i][2];
        if (stu[i][1] != 0)
            flg2 = 0;
        if (stu[i][2] != 0)
            flg3 = 0;
    }
    // dfs(1, 0, 0, 0);
    // cout << ans << "\n";
    if (flg2 && flg3) {
        sort(stu + 1, stu + 1 + n, [&] (array<int, 3> a, array<int, 3> b) {
            return a[0] > b[0];
        });
        for (int i = 1; i <= n / 2; i ++)
            ans += stu[i][0];
        cout << ans;
        return;
    }

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= i && j <= n / 2; j ++) {
            for (int k = 0; k <= (i - j) && k <= n / 2; k ++) {
                int l = i - j - k;
                if (l > n / 2 || l < 0)
                    continue;
                if (j != 0)
                    dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i - 1) % 2][j - 1][k] + stu[i][0]);
                if (k != 0)
                    dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i - 1) % 2][j][k - 1] + stu[i][1]);
                if (l != 0)
                    dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i - 1) % 2][j][k] + stu[i][2]);
                ans = max(ans, dp[i % 2][j][k]);
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
     freopen("club.in", "r", stdin);
     freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T --)
        solve();
    return 0;
}