#include <iostream>
#include <cstdio>

#include <vector>
#include <utility>
#include <string>

using PiStr = std::pair<std::string, std::string>;

bool Check (const PiStr &p, const PiStr &q)
{
    if (p.first.size() > q.first.size() || q.first.size() != q.second.size())
        return false;
    int min_idx{-1}, max_idx{-1};
    for (int i{0}; i< q.first.size(); i++) {
        if (q.first[i] != q.second[i]) {
            if (min_idx == -1)
                min_idx = i;
            max_idx = i;
        }
    }
    if (max_idx - min_idx + 1 > p.first.size())
        return false;
    for (int i{0}; i + p.first.size() - 1 < q.first.size() && i <= min_idx; i++) {
        if (q.first[i] == p.first[0] && q.second[i] == p.second[0]) {
            bool flag{true};
            for (int j{1}; j < p.first.size(); j++) {
                if (q.first[i+j] != p.first[j] || q.second[i+j] != p.second[j]) {
                    flag = false;
                    break;
                }
                if (flag && i + p.first.size() - 1 >= max_idx)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    std::freopen("replace.in", "r", stdin);
    std::freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n{}, q{};
    std::cin >> n >> q;
    std::vector<PiStr> opt(n);
    for (int i{0}; i < n; i++)
        std::cin >> opt[i].first >> opt[i].second;
    for (int i{0}; i < q; i++) {
        PiStr q_str;
        int cnt{0};
        std::cin >> q_str.first >> q_str.second;
        for (const auto &p: opt) {
            if (Check(p, q_str))
                cnt++;
        }
        std::cout << cnt << "\n";
    }
    return 0;
}
