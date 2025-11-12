#include <bits/stdc++.h>
#define lld long long
using namespace std;

const lld M = 998244353;

lld n, ans;
vector<lld> a, f;

void dfs(lld k, lld l, lld sum, lld maxn) {
    if (!k) {
        if (sum > 2 * maxn) ans = (ans + 1) % M;
        return;
    }
    for (int i = l + 1; i <= n; i++) {
        dfs(k - 1, i, sum + a[i], max(maxn, a[i]));
    }
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    a.resize(n + 1);
    f.resize(n + 1);

    for (lld i = 1; i <= n; i++) cin >> a[i];

    for (lld i = 3; i <= n; i++) {
        dfs(i, 0, 0, 0);
    }

    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}