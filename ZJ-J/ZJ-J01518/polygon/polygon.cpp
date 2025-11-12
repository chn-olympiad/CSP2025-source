#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005];
long long ans = 0, dp[5005];
long long power(long long a, long long x)
{
    long long res = 1;
    while(x){
        if(x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(a[1] + a[2] > a[3]) {
        ans = 1;
        dp[3] = 1;
    }
    for(int i = 4;i <= n;i++){
        for(int j = i - 1;j >= 1;j--){
            int c = a[i] - a[j];
            int pos1 = lower_bound(a + 1, a + n + 1, c) - a;
            int pos2 = upper_bound(a + 1, a + n + 1, c) - a;
            // cout<<j<<' '<<pos1<<' '<<pos2<<'\n';
            if(pos1 < j){
                ans = (ans + dp[pos2] % MOD);
                ans = (ans + power(2, pos2) - power(2, pos1) - pos2 + pos1 + MOD) % MOD;
                dp[i] = (dp[pos2] + dp[i] + power(2, pos2) - power(2, pos1) - pos2 + pos1 + MOD) % MOD;
            }
            if(pos2 < j){
                ans = (ans + power(2, j - 1) - power(2, pos2) + MOD) % MOD;
                dp[i] = (dp[i] + power(2, j - 1) - power(2, pos2) + MOD) % MOD;
            }
            
        }
    }
    // for(int i = 1;i <= n;i++) cout<<dp[i]<<' ';
    // cout<<'\n';
    cout<<ans<<'\n';
    return 0;
}