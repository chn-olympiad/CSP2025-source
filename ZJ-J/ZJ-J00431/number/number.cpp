#include <cstdio>
#include <iostream>

#include <string>
#include <array>


// #define DEBUG

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s_in{};
    std::cin >> s_in;
    std::size_t len{s_in.size()};
#ifdef DEBUG
    std::cout << s_in.size() << std::endl;
    std::cout << s_in << std::endl;
#endif // DEBUG
    std::array<int, 10> cnt{};
    // cnt.fill(0);
    auto is_number = [](char c) -> bool { return c >='0' && c <= '9'; };
    for (std::size_t i{0}; i < len; i++) {
        if (is_number(s_in[i]))
            cnt[s_in[i] - '0']++;
    }
#ifdef DEBUG
    for (int i{9};i>=0;i++)
        std::cout << cnt[i] << ' ' << std::flush;
#endif // DEBUG

    for (int i{9}; i >= 0; i--) {
        for (int j{0}; j < cnt[i]; j++)
            std::cout << i;
    }

    return 0;
}
