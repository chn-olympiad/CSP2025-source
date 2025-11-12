#include <bits/stdc++.h>
#define file(name, suf) #name"."#suf
#define input(name) freopen(file(name, in), "r", stdin)
#define output(name) freopen(file(name, out), "w", stdout)
#define mp std::make_pair

#define int long long

typedef std::pair<int, int> pii;
constexpr int N = 1e5 + 10;
int n, a[N][3], cnt[N], belong[N], ans;

void solve() {
    std::cin >> n, cnt[0] = cnt[1] = cnt[2] = ans = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        int j = 0, tmp = a[i][0];
        for (int k = 1; k < 3; k++) if (a[i][k] > tmp) tmp = a[i][k], j = k;
        ++cnt[j], ans += tmp, belong[i] = j;
    }
    int j = -1;
    for (int k = 0; k < 3; k++) if (cnt[k] > n / 2) j = k;
    if (j == -1) return std::cout << ans << '\n', void();
    std::priority_queue<pii> q; 
    for (int i = 1; i <= n; i++) if (belong[i] == j) {
        for (int k = 0; k < 3; k++) if (k != j) {
            q.emplace(a[i][k] - a[i][j], i);
        }
    }
    while (cnt[j] > n / 2) {
        auto [w, i] = q.top();
        q.pop();
        if (belong[i] == -1) continue;
        assert(belong[i] == j);
        belong[i] = -1, ans += w, --cnt[j];
    }
    std::cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
    input(main), output(main);
#else
    input(club), output(club);
#endif
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    while (_--) solve();
    return 0;
}