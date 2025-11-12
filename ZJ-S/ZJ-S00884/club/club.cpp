#include <bits/stdc++.h>

const int maxn = 205;
int n;
int a[maxn][3];
int dp[maxn / 2][maxn / 2][maxn / 2];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out","w",stdout);

    int t;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;

        for (int i = 0; i < n; ++i)
            std::cin >> a[i][0] >> a[i][1] >> a[i][2];

        for (int i = 0; i <= n / 2; ++i)
            for (int j = 0; j <= n / 2; ++j)
                for (int k = 0; k <= n / 2; ++k)
                    dp[i][j][k] = 0;

        for (int i = 0; i < n; ++i) // the i th person
        {
            for (int j = 0; j <= n / 2 && j <= i; ++j)
            {
                for (int k = 0; k <= n / 2 && k <= i; ++k)
                {
                    int l = i - j - k;
                    if (l > n / 2 || l < 0)
                        continue;

                    dp[j + 1][k][l] = std::max(dp[j + 1][k][l], dp[j][k][l] + a[i][0]);
                    dp[j][k + 1][l] = std::max(dp[j][k + 1][l], dp[j][k][l] + a[i][1]);
                    dp[j][k][l + 1] = std::max(dp[j][k][l + 1], dp[j][k][l] + a[i][2]);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= n / 2; ++i)
            for (int j = 0; j <= n / 2; ++j)
                for (int k = 0; k <= n / 2; ++k)
                    ans = std::max(dp[i][j][k], ans);

        std::cout << ans << std::endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

