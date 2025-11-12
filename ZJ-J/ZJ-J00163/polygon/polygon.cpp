#include <bits/stdc++.h>
using namespace std;
const long long N = 5100,mod=998244353;
long long n, a[N],dp[2*N],cnt[2*N],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    dp[0] = 1;
    cnt[0] = 1;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long su = 5000 * 2;
    for (int i = 1; i <= n;i++){
        long long sum = 0;
        for (int j = a[i] + 1; j <= su + 1;j++){
            sum += dp[j] - cnt[j];
            sum %= mod;
        }
        ans += sum;
        ans %= mod;
        cnt[a[i]]++;
        for (int j = 0; j <= a[i];j++){
            dp[su + 1] += dp[su + 1 - j];
            dp[su + 1] %= mod;
        }
        for (int j = su; j >= a[i];j--){
            dp[j] += dp[j - a[i]];
            dp[j] %= mod;
        }
    }
    
        cout << ans << '\n';
    return 0;
}
/*
AK 自动机   rp++
CCF Orz
*/