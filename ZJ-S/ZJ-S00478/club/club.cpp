#include <iostream>
#include <cstdio>

#include <vector>
#include <array>
#include <algorithm>
#include <functional>

using ll_t = long long;
// one set

void dfs(int n, ll_t& res, const std::vector<std::array<ll_t, 3>> &vec, std::array<int, 3> &cnt, ll_t sum, ll_t idx)
{
    if (!(cnt[0] <= n/2 && cnt[1] <= n/2 && cnt[2] <= n/2))
            return;
        if (idx==n) {
            res = std::max(res, sum);
            return;
        }
        for (int i{0}; i < 3; i++){
            cnt[i]++;
            dfs(n, res, vec, cnt, sum+vec[idx][i], idx+1);
            cnt[i]--;
        }
}

void Solve()
{
    int n{};
    std::cin >> n;
    std::vector<std::array<ll_t, 3>> vec(n);
    for (int i{0}; i < n; i++) {
        std::cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
    bool flag_a{true}, flag_b{true};
    for (int i{0}; i < n; i++) {
        if (vec[i][3] != 0) {
            flag_b = false;
            flag_a = false;
            break;
        }
    }
    if (flag_a)
        for (int i{0}; i < n; i++) {
            if (vec[i][2] != 0) {
                flag_a = false;
                break;
            }
        }

    ll_t res{0};
    if (flag_a) {
        std::sort(vec.begin(), vec.end(), std::greater<>());
        for (int i{0}; i < n/2; i++)
            res += vec[i][0];
        std::cout << res;
        return;
    }

    std::array<int, 3> cnt{};

    dfs(n, res, vec, cnt, 0, 0);
    std::cout << res << "\n";
}

int main()
{
    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // dfs 40 pts
    int t{};
    std::cin >> t;
    for (int i{0};i < t;i++)
        Solve();
    return  0;
}
