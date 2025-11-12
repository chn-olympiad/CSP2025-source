#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

namespace W1ngD1nGa5ter
{
    class Process
    {
    public:
        Process() = default;
        int operator()()
        {
            int n;
            std::cin >> n;
            std::vector<std::array<int, 3>> a(n);
            bool sp_a{true}, sp_b{true};
            for (int i{}; i < n; ++i)
            {
                std::cin >> a[i][0] >> a[i][1] >> a[i][2];
                if (a[i][1])
                    sp_a = false;
                if (a[i][2])
                    sp_a = false, sp_b = false;
            }
            // if (n * n / 4 >= 134217728 / 2)
            // if (n > 200)
            {
                // std::cerr << "too big :(\n";
                if (sp_a)
                {
                    std::sort(a.begin(), a.end(), [](std::array<int, 3> a, std::array<int, 3> b) -> bool
                              { return a[0] > b[0]; });
                    std::cout << std::accumulate(a.begin(), a.begin() + n / 2, 0, [](int &sum, std::array<int, 3> a)
                                                 { return sum += a[0]; }) << '\n';
                    return 0;
                }
                if (sp_b)
                {
                    int ans{};
                    std::vector<int> f(n / 2 + 1);
                    for (int i{}; i < n; ++i)
                    {
                        for (int j{std::min(i + 1, n / 2)}; j >= std::max(0, i + 1 - n / 2); --j)
                        {
                            if (j < i + 1)
                                f[j] += a[i][1];
                            if (j)
                                f[j] = std::max(f[j], f[j - 1] + a[i][0]);
                            ans = std::max(ans, f[j]);
                        }
                    }
                    std::cout << ans << '\n';
                    return 0;
                }
            }
            int ans{};
            std::vector<std::vector<int>> f(n / 2 + 1, std::vector<int>(n / 2 + 1));
            for (int i{}; i < n; ++i)
            {
                for (int j{std::min(i + 1, n / 2)}; ~j; --j)
                {
                    for (int k{std::min(i + 1 - j, n / 2)}; k >= std::max(0, i + 1 - j - n / 2); --k)
                    {
                        if (j + k < i + 1)
                            f[j][k] += a[i][2];
                        if (j)
                            f[j][k] = std::max(f[j][k], f[j - 1][k] + a[i][0]);
                        if (k)
                            f[j][k] = std::max(f[j][k], f[j][k - 1] + a[i][1]);
                        ans = std::max(ans, f[j][k]);
                    }
                }
            }
            std::cout << ans << '\n';
            return 0;
        }
    };
}

int main()
{
    if (std::freopen("club.in", "r", stdin) == nullptr || std::freopen("club.out", "w", stdout) == nullptr)
        return 0;
    std::cin.tie(nullptr)->sync_with_stdio(false);
    W1ngD1nGa5ter::Process Main;
    int t{1};
    std::cin >> t;
    while (t--)
    {
        Main();
    }
    std::cout << std::flush;
    return 0;
}
