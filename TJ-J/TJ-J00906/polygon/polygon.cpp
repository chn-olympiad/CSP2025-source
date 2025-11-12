#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int P = 998244353;

int n, a[5005], dp[5005], ans;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        int nw = 0;
        for(int j = a[i] + 1; j <= a[n] + 1; j++)nw = (nw + dp[j]) % P;
        ans = (ans + nw) % P;
        for(int k = a[n] + 1; k >= 0; k--) dp[min(a[n] + 1, k + a[i])] = (dp[min(a[n] + 1, k + a[i])] + dp[k]) % P;
    }
    cout << ans;
    return 0;
}
/*

*/

