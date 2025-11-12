#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 11;
int aaa[MAXN][5];
int t;
int n;
int ans = 0;
int dp[MAXN][4];
int cnt[MAXN][4][4];


struct Sa{
    int a1, a2, a3;
}a[4];

bool cmp(Sa aa, Sa bb)
{
    if (aa.a1 != bb.a1)
        return aa.a1 > bb.a1;
    else if (aa.a2 != bb.a2)
        return aa.a2 > bb.a2;
    return aa.a3 > bb.a3;
}


void dfs(int cur, int t1, int t2, int t3, int sum)
{
    if (cur == n + 1)
        ans = max(ans, sum);
    if (t1 < n / 2)
        dfs(cur + 1, t1 + 1, t2, t3, sum + aaa[cur][1]);
    if (t2 < n / 2)
        dfs(cur + 1, t, t2 + 1, t3, sum + aaa[cur][2]);
    if (t3 < n / 2)
        dfs(cur + 1, t1, t2, t3 + 1, sum + aaa[cur][3]);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n;
        ans = 0;
        if (n <= 4){
			for (int i = 1; i <= n; i++)
				cin >> aaa[i][1] >> aaa[i][2] >> aaa[i][3];
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
		}
		else
        {
            memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
            cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++){
                for (int k = 1; k <= 3; k++){
                    if (cnt[i - 1][k][1] + 1 <= n / 2 && dp[i][1] < a[i].a1 + dp[i - 1][k]){
                        dp[i][1] = a[i].a1 + dp[i - 1][k];
                        cnt[i][1][1] = cnt[i - 1][k][1];
                        cnt[i][1][2] = cnt[i - 1][k][2];
                        cnt[i][1][3] = cnt[i - 1][k][3];
                        cnt[i][1][1] = cnt[i - 1][k][1] + 1;
                    }

                    if (cnt[i - 1][k][2] + 1 <= n / 2 && dp[i][2] < a[i].a2 + dp[i - 1][k]){
                        dp[i][2] = a[i].a2 + dp[i - 1][k];
                        cnt[i][2][1] = cnt[i - 1][k][1];
                        cnt[i][2][2] = cnt[i - 1][k][2];
                        cnt[i][2][3] = cnt[i - 1][k][3];
                        cnt[i][2][2] = cnt[i - 1][k][2] + 1;
                    }

                    if (cnt[i - 1][k][3] + 1 <= n / 2 && dp[i][3] < a[i].a3 + dp[i - 1][k]){
                        dp[i][3] = a[i].a3 + dp[i - 1][k];
                        cnt[i][3][1] = cnt[i - 1][k][1];
                        cnt[i][3][2] = cnt[i - 1][k][2];
                        cnt[i][3][3] = cnt[i - 1][k][3];
                        cnt[i][3][3] = cnt[i - 1][k][3] + 1;
                    }
                }
        }

        ans = max(max(dp[n][1], dp[n][2]), dp[n][3]);
        cout << ans << "\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
