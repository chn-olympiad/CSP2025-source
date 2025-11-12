#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long dp[2][4][5005];
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int maxn = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    sort(a + 1,a + n + 1);
    dp[0][0][0] = 1;
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 2;j++){
            for(int k = 0;k <= maxn + 1;k++){
                dp[i % 2][j][k] = 0;
            }
        }
        for(int j = 0;j <= 2;j++){
            for(int k = 0;k <= maxn + 1;k++){
                dp[i % 2][j][k] = (dp[i % 2][j][k] + dp[(i - 1) % 2][j][k]) % mod;
                int ji = j + 1,ki = k + a[i];
                if(j + 1 > 1)ji = 2;
                if(k + a[i] > maxn)ki = maxn + 1;
                dp[i % 2][ji][ki] = (dp[i % 2][ji][ki] + dp[(i - 1) % 2][j][k]) % mod;
            }
        }
        if(i >= 2 && i < n){
            for(int k = a[i + 1] + 1;k <= maxn + 1;k++){
                ans = (ans + dp[i % 2][2][k]) % mod;
            }
        }
    }
    cout << ans;
    //cout << dp[1][1][1];
    return 0;
}