#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
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
            int n, q;
            std::cin >> n >> q;
            std::vector<std::pair<std::string, std::string>> s(n);
            for (int i{}; i < n; ++i)
            {
                std::cin >> s[i].first >> s[i].second;
            }
            while (q--)
            {
                std::string t1, t2;
                std::cin >> t1 >> t2;
                int last{static_cast<int>(t1.length())};
                while (~last && t1[last] == t2[last])
                    --last;
                std::queue<std::pair<int, std::unordered_set<int>>> q;
                std::unordered_set<int> full;
                for (int i{}; i < n; ++i)
                    full.emplace(i);
                q.emplace(0, full);
                int ans{};
                int l = static_cast<int>(t1.length());
                while (!q.empty())
                {
                    int i = q.front().first;
                    auto available = q.front().second;
                    q.pop();
                    if (i > last)
                        ++ans;
                    while (i < l)
                    {
                        for (int j : available)
                        {
                            int sl = static_cast<int>(s[j].first.length());
                            if (t1.substr(i, sl) == s[j].first && t2.substr(i, sl) == s[j].second)
                            {
                                // auto t = t1.substr(0, i) + s[j].second + t1.substr(i + sl);
                                // std::cerr << "t = \"" << t << "\"\n";
                                auto tmp = available;
                                tmp.erase(j);
                                q.emplace(i + sl, tmp);
                            }
                        }
                        if (t1[i] != t2[i])
                            break;
                        ++i;
                    }
                }
                std::cout << ans << '\n';
            }
            return 0;
        }
    };
}

int main()
{
    if (std::freopen("replace.in", "r", stdin) == nullptr || std::freopen("replace.out", "w", stdout) == nullptr)
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
