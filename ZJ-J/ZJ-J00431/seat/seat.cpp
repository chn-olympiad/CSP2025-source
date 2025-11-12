#include <cstdio>
#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>

// #define DEBUG

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n{}, m{};
    std::cin >> n >> m;
    // n = row m = column
    std::vector<int> vec(n*m);
    for (int i{0}; i < n * m; i++)
        std::cin >> vec[i];
    int score{vec[0]},
        idx{0};

    std::sort(vec.begin(), vec.end(), std::greater<int>());
    for (; idx < n * m; idx++)
        if (vec[idx] ==  score)
            break;
    int column{idx / n + 1}, row{idx % n + 1};
    if (column % 2 == 0)
        row = n + 1 - row;
    std::cout << column << ' ' << row;
    return 0;
}
