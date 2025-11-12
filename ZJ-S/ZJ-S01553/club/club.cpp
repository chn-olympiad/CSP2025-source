#include<bits/stdc++.h>
using namespace std;

int t, n, a[100005][5], dp[205][105][105], ans, b[100005];
bool f;

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        f = 0;
        cin >> n;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++)
                cin >> a[i][j];
            if(a[i][2] != 0 || a[i][3] != 0) f = 1;
        }
        ans = 0;
        if(f == 0){
            for(int i = 1;i <= n;i++) b[i] = a[i][1];
            sort(b + 1, b + n + 1);
            for(int i = n;i > n/2;i--) ans += b[i];
            cout<<ans<<'\n';
            continue;
        }
        memset(dp, -100000000, sizeof dp);
        dp[0][0][0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= i;j++){
                for(int k = 0;k <= i - j;k++){
                    int l = i - j - k;
                    if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
                    if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
                    if(l > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
                }
            }
        }
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= n;j++){
                if(i + j < n/2 || i > n/2 || j > n/2) continue;
                ans = max(ans, dp[n][i][j]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}