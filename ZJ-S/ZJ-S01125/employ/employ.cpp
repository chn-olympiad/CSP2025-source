#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

namespace W1ngD1nGa5ter
{
    class Process
    {
    public:
        Process() = default;
        int operator()()
        {
            int n, m;
            std::cin >> n >> m;
            std::string s;
            std::cin >> s;
            std::vector<int> c(n), p(n);
            for (int i{}; i < n; ++i)
                std::cin >> c[i], p[i] = i;
            if (!std::count(s.begin(), s.end(), '0'))
            {
                long long ans{1};
                for (int i{2}; i <= n; ++i)
                    ans *= i;
                std::cout << ans << '\n';
                return 0;
            }
            if (std::count(s.begin(), s.end(), '1') < m)
            {
                std::cout << "0\n";
                return 0;
            }
            if (n > 12)
            {
                // std::cerr << "too big :(\n";
                std::cout << "0\n";
                return 0;
            }
            std::sort(c.begin(), c.end());
            int ans{};
            do
            {
                int cnt{};
                bool flag{};
                for (int i{}; i < n; ++i)
                {
                    if (s[i] == '0' || cnt >= c[p[i]])
                    {
                        ++cnt;
                        if (cnt + m > n)
                        {
                            flag = true;
                            break;
                        }
                    }
                }
                if (!flag && ++ans == 998244353)
                    ans = 0;
            }
            while (std::next_permutation(p.begin(), p.end()));
            std::cout << ans << '\n';
            return 0;
        }
    };
}

int main()
{
    if (std::freopen("employ.in", "r", stdin) == nullptr || std::freopen("employ.out", "w", stdout) == nullptr)
        return 0;
    std::cin.tie(nullptr)->sync_with_stdio(false);
    W1ngD1nGa5ter::Process Main;
    int t{1};
    // std::cin >> t;
    while (t--)
    {
        Main();
    }
    std::cout << std::flush;
    return 0;
}
