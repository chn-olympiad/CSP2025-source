#include <iostream>
#include <algorithm>

namespace noip {
    using Int = long long;
    using UInt = unsigned long long;

    constexpr Int Max_N = 500000;
    Int n, k;
    Int a[1 + Max_N] {};
    UInt s[1 + Max_N] {};
    Int f[1 + Max_N] {};

    void main() {
        std::freopen("xor.in", "r", stdin);
        std::freopen("xor.out", "w", stdout);

        std::cin >> n >> k;
        for (Int i = 1; i <= n; i++) std::cin >> a[i];
        for (Int i = 1; i <= n; i++) s[i] = s[i - 1] ^ a[i];

        for (Int i = 1; i <= n; i++) {
            for (Int j = 0; j < i; j++) {
                f[i] = std::max(f[i], f[j] + (Int)((s[i] ^ s[j]) == k));
            }
        }

        std::cout << f[n] << std::endl;

        std::fclose(stdin);
        std::fclose(stdout);
    }
}

int main() {
    noip::main();
    return 0;
}
