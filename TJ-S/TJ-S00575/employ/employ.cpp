#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, m;
ll a[200010], b[200010];

ll f[20],g[20];
ll ans = 0;
void dfs(ll now) {
    if (now > n ){
        ll x = 0, s = 0;
        for (int i = 1; i <= n; i++) {
            if (s >= b[g[i]]) s++;
            else if (a[i]) x++;
            else {
                s++;
            }
        }
        if (x >= m) ans++;
    }
for (int i = 1; i <= n; i++) {
    if (!f[i])
    {
        f[i] = 1;
        g[now] = i;
        dfs(now + 1);
        f[i] = 0;
        g[now] = 0;
    }
}
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        a[i ] = s[i] - '0';
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dfs(1);
    cout << ans % 998244353;
    return 0;
}
