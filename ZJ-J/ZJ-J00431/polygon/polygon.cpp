#include <cstdio>
#include <iostream>

#include <vector>
#include <algorithm>

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    using ll_t = long long;
    constexpr ll_t kMod{998'244'353LL};
    int n{};
    std::cin >> n;
    std::vector<ll_t> vec(n + 1);
    // idx startsv from 1 and vec[0] == 0
    ll_t m{0};
    for (int i{1}; i <= n; i++) {
        std::cin >> vec[i];
        if (vec[i] > m)
            m = vec[i];
    }
    m = m * 2 + 5;
    std::sort(vec.begin(), vec.end());

    std::vector<std::vector<ll_t>> dp(m, std::vector<ll_t>(n + 1));
    dp[0][0] = 1;
    for (int i{0}; i < m; i++) {
        for (int j{0}; j <= n; j++) {
            ll_t t{vec[j] > i ? 0 : i - vec[j]};
            for (int k{0}; k < j; k++) {
                dp[i][j] += dp[t][k];
                dp[i][j] %= kMod;
            }
        }
    }

    ll_t ans{0};
    for (int i{1}; i <= n; i++) {
        ans += dp[2 * vec[i] + 1][i];
        ans %= kMod;
    }
    std::cout << ans;
    return 0;
}
