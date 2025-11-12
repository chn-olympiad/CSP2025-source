#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

using ll_t = long long;

struct Edge {
    int u{}, v{};
    ll_t w{};
    friend bool operator<(const Edge lhs, const Edge rhs)
    {
        if (lhs.w == rhs.w)
            return (lhs.u==rhs.u ? lhs.v < rhs.v : lhs.u < rhs.u);
        return lhs.w < rhs.w;
    }
};

int find(int idx, std::vector<int> &fa)
{
    if (fa[fa[idx]] != fa[idx])
        fa[idx] = find(fa[idx], fa);
    return fa[idx];
}

int main()
{
    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n{}, m{}, k{};
    std::cin >> n >> m >> k;
    std::vector<Edge> edge_vec;
    edge_vec.reserve(m + k * n + 5);
    for (int i{0}; i < m; i++) {
        Edge temp{};
        std::cin >> temp.u >> temp.v >> temp.w;
        temp.u--;
        temp.v--;
        edge_vec.emplace_back(temp);
    }
    if (k == 0) {
        std::sort(edge_vec.begin(), edge_vec.end());
        std::vector<int> fa(n);
        for (int i{0}; i < n; i++) {
            fa[i] = i;
        }
        int cnt{1};
        ll_t res{0};

        for (const auto& e: edge_vec) {
            if (find(e.u, fa) != find(e.v, fa)) {
                cnt++;
                res += e.w;
                fa[e.u] = fa[e.v];
                if (cnt == n)
                    break;
            }
        }
        std::cout << res;
    } else {}
    return 0;
}
