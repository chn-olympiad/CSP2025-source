#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef unsigned long long i64;

u64 t, n, a[100010][4], ans, dp[100010][4][4];
bitset<100010> vis;

struct pac {
    u64 i, j, val;
};

bool operator<(const pac &a, const pac &b) {
    return a.val < b.val;
}

void dfs(u64 i, u64 cur, u64 cnt1, u64 cnt2, u64 cnt3) {
    if (i > n) {
        ans = max(ans, cur);
        return;
    }
    if (cnt1 < n / 2)
        dfs(i + 1, cur + a[i][1], cnt1 + 1, cnt2, cnt3);
    if (cnt2 < n / 2)
        dfs(i + 1, cur + a[i][2], cnt1, cnt2 + 1, cnt3);
    if (cnt3 < n / 2)
        dfs(i + 1, cur + a[i][3], cnt1, cnt2, cnt3 + 1);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%llu", &t);
    while (t--) {
        scanf("%llu", &n);
        priority_queue<pac> q;
        for (u64 i = 1, x, y, z; i <= n; i++) {
            scanf("%llu%llu%llu", &x, &y, &z);
            a[i][1] = x;
            a[i][2] = y;
            a[i][3] = z;
            q.push({i, 1, x});
            q.push({i, 2, y});
            q.push({i, 3, z});
        }
        ans = 0;
        if (n <= 10)
            dfs(1, 0, 0, 0, 0);
        else if (true) {
            memset(dp, 0, sizeof dp);
            for (u64 i = 1; i <= n; i++)
                for (u64 j = 1; j <= 3; j++) 
                    for (u64 k = 1; k <= 3; k++) {
                        u64 tmp1 = dp[i - 1][j][0] + a[i][k];
                        if (tmp1 > dp[i][k][0] && dp[i - 1][j][k] < n / 2) {
                            dp[i][k][0] = tmp1;
                            dp[i][k][1] = dp[i - 1][j][1] + (k == 1);
                            dp[i][k][2] = dp[i - 1][j][2] + (k == 2);
                            dp[i][k][3] = dp[i - 1][j][3] + (k == 3);
                        }
                    }
            ans = max(ans, dp[n][1][0]);
            ans = max(ans, dp[n][2][0]);
            ans = max(ans, dp[n][3][0]);
        } else {
            vis.reset();
            u64 cnt[4] = {0};
            while (!q.empty()) {
                pac x = q.top();
                q.pop();
                if (vis[x.i])
                    continue;
                if (cnt[x.j] >= n / 2)
                    continue;
                cnt[x.j]++;
                vis[x.i] = true;
                ans += x.val;
            }
        }
        printf("%llu\n", ans);
    }
}
