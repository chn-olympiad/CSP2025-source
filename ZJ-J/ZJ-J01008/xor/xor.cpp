#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int dp[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        dp[i] = dp[i - 1];
        long long sum = 0;
        for(int j = i;j >= 1;j--){
            sum ^= a[j];
            if(sum == k){
                dp[i] = max(dp[i],dp[j - 1] + 1);
                break;
            }
            if(dp[j - 1] <= dp[i] - 1)break;
        }
    }
    cout << dp[n];


    return 0;
}