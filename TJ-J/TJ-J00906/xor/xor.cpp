#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, a[500005], f[1500005], ans, dp[500005], b[500005];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> m;
    memset(f, -0x3f, sizeof(f));
    memset(dp, -0x3f, sizeof(dp));
    f[0] = 0;
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = b[i - 1] ^ a[i];
        dp[i] = f[b[i] ^ m] + 1;
        mx = max(mx, dp[i]);
        f[b[i]] = mx;
    }
    cout << mx;
    return 0;
}
/*
1 2 4
1 3 7

2 3 3 0
*/

