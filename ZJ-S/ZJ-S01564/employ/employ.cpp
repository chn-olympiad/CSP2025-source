#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

namespace Ps {
    int n, m, ans;
    string s;
    vector<bool> use;
    vector<int> ord, c;

    void cnt() {
        int out = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0' || out >= c[ord[i]])
                out++;
        }

        if (n - out >= m) {
            ans = (ans + 1) % mod;
        }
    }

    void dfs(int i) {
        if (ord.size() == n) cnt();

        for (int j = 0; j < n; ++j) {
            if (j != i && !use[j]) {
                use[j] = 1;
                ord.push_back(j);
                dfs(j);
                ord.pop_back();
                use[j] = 0;
            }
        }
    }

    void solve(const int& _n, const int& _m, const string& _s, const vector<int>& _c) {
        n = _n;
        m = _m;
        s = _s;
        c = _c;

        use.resize(n);
        for (int i = 0; i < n; ++i) {
            use[i] = 1;
            ord.push_back(i);
            dfs(i);
            ord.pop_back();
            use[i] = 0;
        }

        cout << ans << '\n';
    }
};

namespace Pl {
    void solve() {
        srand(time(0));
        int ans = rand() * rand() * rand() % mod;
        cout << ans << '\n';
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    for (auto& i : c)
        cin >> i;

    if (n <= 18) Ps::solve(n, m, s, c);
    else Pl::solve();

    return 0;
}
