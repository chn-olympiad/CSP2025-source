#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 20, K = (1 << 18) + 5, mod = 998244353;

using PII = pair<int, int>;

int n, m, a[N], p[N], ans;
bool vis[N];
string s;

void dfs(int x) {
    if (x == n + 1) {
        int ct = 0, ss = 0;
        for (int i = 1; i <= n; i ++ )
            if (ct >= a[p[i]] || s[i - 1] == '0')   ct ++ ;
            else   ss ++ ;
        if (ss >= m) {
            ans ++ ;
        }
        return ;
    }
    for (int i = 1; i <= n; i ++ )
        if (vis[i] == false) {
            vis[i] = true;
            p[x] = i;
            dfs(x + 1);
            p[x] = 0;
            vis[i] = false;
        }
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i ++ )  cin >> a[i];
    dfs(1);
    cout << ans << '\n';
    return 0;
}