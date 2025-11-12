#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int mod = 998244353;
constexpr int N = 505;

int n, m;
std::string s;
int a[N], p[N];

void sol() {
    std::cin >> n >> m >> s;
    s = " " + s;
    if (n > 18) {
        int f = 1;
        for (int i = 1; i <= m; i++) {
            f &= (s[i] == '1');
        }
        if (!f) {
            std::cout << "0\n";
            return;
        }
        i64 ans = 1LL;
        for (int i = n; i >= 1; i--) ans = ans * i % mod;
        std::cout << ans << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    do {
        int f = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt >= a[p[i]] || s[i] == '0') {
                cnt++;
                continue;
            }
            f++;
        }
        ans += (f >= m);
    } while (std::next_permutation(p + 1, p + n + 1));
    std::cout << ans << "\n";
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // init();
    int T = 1;
    // std::cin >> T;
    while (T--) sol();
    return 0;
}