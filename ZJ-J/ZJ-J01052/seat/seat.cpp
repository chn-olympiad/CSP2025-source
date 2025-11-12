#include <iostream>
#include <algorithm>

namespace noip {
    using Int = long long;
    using UInt = unsigned long long;

    constexpr Int Max_N = 10, Max_M = 10, Max_L = Max_N * Max_M;
    Int n, m, l, r;
    Int a[1 + Max_L] {};

    void main() {
        std::freopen("seat.in", "r", stdin);
        std::freopen("seat.out", "w", stdout);

        std::cin >> n >> m;
        l = n * m;
        for (Int i = 1; i <= l; i++) std::cin >> a[i];
        r = a[1];
        std::sort(a + 1, a + 1 + l);
        Int ai = 1, aj = 1, cnt = l;
        for (; cnt >= 1; cnt--) {
            if (a[cnt] == r) break;
            else {
                if (aj % 2 != 0) {
                    ai++;
                    if (ai > n) aj++, ai = n;
                } else {
                    ai--;
                    if (ai < 1) aj++, ai = 1;
                }
            }
        }

        std::cout << aj << ' ' << ai << std::endl;

        std::fclose(stdin);
        std::fclose(stdout);
    }
}

int main() {
    noip::main();
    return 0;
}