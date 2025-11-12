#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

// using i128 = __int128;
// using u128 = unsigned __int128;

int n, m;
std::vector<int> v;

void sol() {
    std::cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }

    int x = v[0];
    std::sort(v.begin(), v.end(), std::greater<int>());
    int p = 0;
    for (int i = 1; i < (int)v.size(); i++) {
        if (v[i] == x)
            p = i;
    }

    // std::cout << p << "\n";
    std::cout << p / n + 1 << " " << (p / n % 2 ? n - p % n : p % n + 1) << "\n";
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // init();
    int T = 1;
    // std::cin >> T;
    while (T--) {
        sol();
    }
    return 0;
}
