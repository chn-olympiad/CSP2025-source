#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <algorithm>

constexpr long long kMod{998'244'353LL};

int main()
{
    std::freopen("employ.in", "r", stdin);
    std::freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n{}, m{};
    std::cin >> n >> m;
    std::string test;
    test.reserve(n + 5);
    std::cin >> test;
    std::vector<int> quit_lim(n);
    for (int i{0}; i < n; i++) {
        std::cin >> quit_lim[i];
    }

    using ll_t = long long;
    if (n < 12) {
        std::vector<int> permut(n);
        for (int i{0}; i < n; i++)
            permut[i] = i;
        ll_t res{0};
        do {
            int cnt{0};
            for (int i{0}; i < n; i++) {
                if (test[i]=='1' && (i - cnt) < quit_lim[permut[i]])
                    cnt++;
            }
            if (cnt >= m) res ++;
        } while (std::next_permutation(permut.begin(), permut.end()));
        std::cout << res % kMod;
    } else {
        std::cout << 0;
    }
    return 0;
}
