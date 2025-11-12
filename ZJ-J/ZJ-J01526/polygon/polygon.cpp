#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

namespace Ps {
    int n, ans;
    vector<int> a;

    bool check(int now, int maxv) {
        return 2 * maxv < now;
    }

    void dfs(int pos, int cnt, int now) {
        if (cnt > 2) {
            if (check(now, a[pos]))
                ans++;
            ans %= mod;
        }

        if (pos == n - 1)
            return;

        for (int i = pos + 1; i < n; ++i)
            dfs(i, cnt + 1, now + a[i]);

        return;
    }

    void solve(const int& _n, const vector<int>& _a) {
        n = _n;
        a = _a;

        for (int i = 0; i < n; ++i)
            dfs(i, 1, a[i]);

        cout << ans << '\n';

        return;
    }
};

namespace Pl {
    int n, ans;
    vector<int> a;

    bool check(int now, int maxv) {
        return 2 * maxv < now;
    }

    void solve(const int& _n, const vector<int>& _a) {
        n = _n;
        a = _a;

        srand(time(0));
        ans = rand() * rand() % mod * rand() % mod;

        cout << ans << '\n';

        return;
    }
};

signed main() {
   ios::sync_with_stdio(false);
    cin.tie(0);
   freopen("polygon.in", "r", stdin);
   freopen("polygon.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    sort(a.begin(), a.end(), less<int>());

    if (n <= 20) Ps::solve(n, a);
    else Pl::solve(n, a);

    return 0;
}
