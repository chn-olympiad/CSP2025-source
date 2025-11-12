#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10,K=(1<<20)+10;
long long n, k, a[N],lt[K],dp[N],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    long long sum = 0;
    memset(lt, -1, sizeof(lt));
    lt[0] = 0;
    for (int i = 1; i <= n;i++){
        sum ^= a[i];
        
        long long ne = sum ^ k;
        if(lt[ne]!=-1){
            dp[i] = dp[lt[ne]] + 1;
        }
        lt[sum] = i;
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n] << '\n';
    return 0;
}
/*
AK 自动机   rp++
CCF Orz
*/