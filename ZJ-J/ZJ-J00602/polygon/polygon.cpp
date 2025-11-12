#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n;
int a[100010];
int ans = 0;

void dfs (int nows, int nowm, int nowp) {
    if (nows > nowm * 2) {
        ++ans;
        ans %= MOD;
    }
    if (nowp == n) {
        return;
    }
    for (int i = nowp + 1; i <= n; ++i) {
        dfs (nows + a[i], max (nowm, a[i]), i);
    }
}

int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    dfs (0, 0, 0);

    cout << ans << endl;

    fclose (stdin);
    fclose (stdout);
    return 0;
}