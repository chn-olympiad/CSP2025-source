#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

namespace W1ngD1nGa5ter
{
    class Process
    {
    public:
        Process() = default;
        int operator()()
        {
            int n, m, k;
            std::cin >> n >> m >> k;
            // std::vector<std::vector<std::pair<int, int>>> e(n + 1);
            std::vector<std::tuple<long long, int, int>> edges(m + k * n);
            for (int i{}; i < m; ++i)
            {
                int u, v;
                long long w;
                std::cin >> u >> v >> w;
                edges[i] = std::make_tuple(w, u - 1, v - 1);
                // e[u].emplace_back(v, w);
                // e[v].emplace_back(u, w);
            }
            std::vector<long long> c(k);
            // std::vector<std::vector<std::pair<int, int>>> additional(k, std::vector<std::pair<int, int>>(n));
            // std::vector<std::vector<int>> a(k, std::vector<int>(n));
            for (int i{}; i < k; ++i)
            {
                std::cin >> c[i];
                for (int j{}; j < n; ++j)
                {
                    int a;
                    std::cin >> a;
                    // std::cin >> a[i][j];
                    edges[m + i * n + j] = std::make_tuple(a, n + i, j);
                }
            }
            // std::cerr << "input done\n";
            std::sort(edges.begin(), edges.end());
            std::vector<int> fa(n + k);
            auto find = [&fa](auto &&find, int x) -> int
            {
                return fa[x] == x ? x : fa[x] = find(find, fa[x]);
            };
            auto merge = [&fa, &find](int x, int y) -> bool
            {
                if ((x = find(find, x)) == (y = find(find, y)))
                    return false;
                if (x < y)
                    std::swap(x, y);
                fa[y] = x;
                return true;
            };
            long long ans{std::numeric_limits<long long>::max()};
            // std::cerr << "ready\n";
            for (int state{}; state < (1 << k); ++state)
            {
                // std::cerr << std::hex << state << std::dec << '\n';
                std::iota(fa.begin(), fa.end(), 0);
                long long cur{};
                for (int i{}; i < k; ++i)
                    cur += (state & (1 << i)) * c[i];
                // std::cerr << "at start : cur = " << cur << '\n';
                for (std::tuple<long long, int, int> edge : edges)
                {
                    long long w = std::get<0>(edge);
                    int u = std::get<1>(edge);
                    int v = std::get<2>(edge);
                    if (u >= n && (~state & (1 << (u - n))))
                        continue;
                    cur += merge(u, v) * w;
                }
                // std::cerr << "cur = " << cur << "\n";
                if (cur >= ans)
                    continue;
                // std::cerr << "checking\n";
                int cnt{};
                for (int i{}; i < n; ++i)
                    if (find(find, i) == i)
                        ++cnt;
                // std::cerr << "cnt = " << cnt << '\n';
                if (cnt > 1)
                    continue;
                ans = cur;
                // std::cerr << "ans = " << ans << "\n";
            }
            std::cout << ans << '\n';
            return 0;
        }
    };
}

int main()
{
    if (std::freopen("road.in", "r", stdin) == nullptr || std::freopen("road.out", "w", stdout) == nullptr)
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
