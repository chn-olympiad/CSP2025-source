#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e5+7;
int n, k;
int a[maxn];
int p[maxn];
int dp[maxn];
map<int, int> q;

signed main(signed argc, char const *argv[]) {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], p[i] = p[i - 1] ^ a[i];
    q[0] = 0;
    for (int i = 1; i <= n; i++) {
        q[p[i]] = i;
        if (q.count(k ^ p[i]))
            dp[i] = max(dp[i - 1], dp[q[k ^ p[i]]] + 1);
        else
            dp[i] = dp[i - 1];
    }
    cout << dp[n] << endl;
    return 0;
}
