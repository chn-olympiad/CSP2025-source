#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

// using i128 = __int128;
// using u128 = unsigned __int128;

constexpr int N = 5e5 + 5;
constexpr int M = (1 << 20) + 5;

int n, k, a[N], s[N], lst[M], dp[N];

void sol() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }

    memset(lst, -1, sizeof lst);
    lst[0] = 0;
    for (int i = 1; i <= n; i++) {
        // std::cout << i << " " << s[i] << " " << (s[i] ^ k) << " " << lst[s[i] ^ k] << "\n";
        dp[i] = std::max(dp[i - 1], (lst[s[i] ^ k] == -1 ? 0 : dp[lst[s[i] ^ k]] + 1));
        lst[s[i]] = i;
    }
    std::cout << dp[n] << "\n";
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

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
