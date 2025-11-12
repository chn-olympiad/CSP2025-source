#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

// using i128 = __int128;
// using u128 = unsigned __int128;

constexpr int N = 5005;
constexpr int mod = 998244353;

int n, a[N];
i64 ans, f[N];

void sol() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        // std::cout << a[i] << " ";
        for (int j = a[i] + 1; j <= 5001; j++) {
            ans = (ans + f[j]) % mod;
        }
        // std::cout << a[i] << "\n";
        for (int j = 5001; j >= 0; j--) {
            // std::cout << std::min(5001, j + a[i]) << "+=" << j << "\n";
            f[std::min(5001, j + a[i])] = (f[std::min(5001, j + a[i])] + f[j]) % mod;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // init();
    int T = 1;
    // std::cin >> T;
    while (T--) {
        sol();
    }
    return 0;
}
