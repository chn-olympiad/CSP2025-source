#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[5010];

int dfs(int n, int k, int step, int sum) {
    if (step > n) {
        if (sum > k) return 1;
        return 0;
    }
    return (dfs(n, k, step + 1, sum + a[step]) + dfs(n, k, step + 1, sum)) % 998244353;
}
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    if (n > 20) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 3; i <= n; i++) {
        ans = (ans + dfs(i - 1, a[i], 1, 0)) % 998244353;
    }
    cout << ans;
    return 0;
}
