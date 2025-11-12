#include <bits/stdc++.h>

using namespace std;

int a[500005];
int tmp[2000005];
int L[500005];
int dp[500005];
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int sum = 0;
    memset(tmp, -1, sizeof(tmp));
    tmp[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum ^= a[i];
        if (tmp[sum ^ k] != -1) {
            L[i] = tmp[sum ^ k] + 1;//[L[i], i] ^sum= k
           // cout << i << ":" << L[i] << endl;
        }
        tmp[sum] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (L[i]) {
            dp[i] = max(dp[i], dp[L[i] - 1] + 1);
        }
        //cout << "dp" << i << "=" << dp[i] << endl;
    }
    cout << dp[n];
    return 0;
}