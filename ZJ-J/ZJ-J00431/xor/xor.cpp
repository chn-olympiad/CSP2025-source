#include <cstdio>
#include <iostream>

#include <vector>
#include <algorithm>

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n{}, k{};
    // k >= 0
    std::cin >> n >> k;
    std::vector<int> pre_sum(n + 1);
    // idx starts from 1
    for (int i{1}; i <= n; i++) {
        std::cin >> pre_sum[i];
        pre_sum[i] ^= pre_sum[i - 1];
    }
    // int ans{0};
    std::vector<int> dp(n + 1);

    for (int i{1}; i <= n; i++) {
        dp[i] = dp[i-1];
        for (int j{i-1}; j >= 0; j--)
            if ((pre_sum[i] ^ pre_sum[j]) == k) {
                dp[i] = std::max(dp[i], dp[j] + 1);
                break;
            }
        // ans = std::max(ans, dp[i]);
    }
    std::cout << dp[n];
    // baoli 60 pts
    return 0;
}
