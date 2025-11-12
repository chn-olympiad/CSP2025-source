#include <bits/stdc++.h>
using namespace std;
int a[100005][3],dp[205][205];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(dp,0xc0c0c0c0,sizeof(dp));
        for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
        dp[0][0] = 0;
        for (int k = 1; k <= n; k++)
        {
            for (int i = n / 2; i >= 0; i--)
            {
                for (int j = n / 2; j >= 0; j--)
                {
                    if(i == 0 && j == 0) dp[i][j] = dp[i][j] + a[k][2];
                    else if (i == 0) dp[i][j] = max(dp[i][j - 1] + a[k][1],dp[i][j] + a[k][2]);
                    else if(j == 0) dp[i][j] = max(dp[i - 1][j] + a[k][0],dp[i][j] + a[k][2]);
                    else dp[i][j] = max(dp[i - 1][j] + a[k][0],max(dp[i][j - 1] + a[k][1],dp[i][j] + a[k][2]));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n / 2; i++)
        {
            for (int j = n / 2 - i; j <= n / 2; j++)
            {
                ans = max(ans,dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
