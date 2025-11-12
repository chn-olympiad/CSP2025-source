#include <iostream>
#include <climits>
#include <algorithm>

namespace noip {
    using Int = long long;
    using UInt = unsigned long long;

    constexpr Int Max_N1 = 30, Max_N2 = 200, Max_N3 = 100000, Max_J = 3;
    Int T, n;
    Int a[1 + Max_N3][1 + Max_J] {};

    void main() {
        std::freopen("club.in", "r", stdin);
        std::freopen("club.out", "w", stdout);

        std::cin >> T;
        while (T--) {
            std::cin >> n;
            for (Int i = 1; i <= n; i++) for (Int j = 1; j <= 3; j++) std::cin >> a[i][j];

            if (n <= 200 && n > 30) {
                Int f2[1 + Max_N2 / 2][1 + Max_N2 / 2] {};
                std::fill(&f2[1][1], &f2[Max_N2 / 2][Max_N2 / 2] + 1, LLONG_MIN);
                std::fill(&f2[0][0], &f2[1][1], 0LL);
                for (Int j = 1; j <= n / 2; j++) {
                    f2[0][j] = f2[j][0] = 0;
                }

                for (Int i = 1; i <= n; i++) {
                    for (Int k = n / 2; k >= 0; k--) {
                        for (Int l = n / 2; l >= 0; l--) {
                            if (k >= 1 && f2[k - 1][l] != LLONG_MIN) f2[k][l] = std::max({f2[k][l], f2[k - 1][l] + a[i][1]});
                            if (l >= 1 && f2[k][l - 1] != LLONG_MIN) f2[k][l] = std::max({f2[k][l], f2[k][l - 1] + a[i][2]});
                            // std::cout << i << ' ' << k << ' ' << l << ' ' << f[k][l] << std::endl;
                        }
                    }
                }
                std::cout << f2[n / 2][n / 2] << std::endl;
                continue;
            } else if (n > 200) {
                Int tmp[1 + Max_N3] {};
                for (Int i = 1; i <= n; i++) tmp[i] = a[i][1];
                std::sort(tmp + 1, tmp + n + 1);
                Int ans = 0;
                for (Int i = n; i > n - n / 2; i--) {
                    ans += tmp[i];
                }
                std::cout << ans << std::endl;
                continue;
            }

            Int f[1 + Max_N1 / 2][1 + Max_N1 / 2][1 + Max_N1 / 2] {};
            std::fill(&f[1][1][1], &f[Max_N1 / 2][Max_N1 / 2][Max_N1 / 2] + 1, LLONG_MIN);
            std::fill(&f[0][0][0], &f[1][1][1], 0LL);
            for (Int j = 1; j <= n / 2; j++) {
                for (Int k = 1; k <= n / 2; k++) {
                    f[j][k][0] = f[0][j][k] = f[j][0][k] = 0;
                }
            }

            for (Int i = 1; i <= n; i++) {
                for (Int k = n / 2; k >= 0; k--) {
                    for (Int l = n / 2; l >= 0; l--) {
                        for (Int m = n / 2; m >= 0; m--) {
                            if (k >= 1 && f[k - 1][l][m] != LLONG_MIN) f[k][l][m] = std::max({f[k][l][m], f[k - 1][l][m] + a[i][1]});
                            if (l >= 1 && f[k][l - 1][m] != LLONG_MIN) f[k][l][m] = std::max({f[k][l][m], f[k][l - 1][m] + a[i][2]});
                            if (m >= 1 && f[k][l][m - 1] != LLONG_MIN) f[k][l][m] = std::max({f[k][l][m], f[k][l][m - 1] + a[i][3]});
                            std::cout << i << ' ' << k << ' ' << l << ' ' << m << ' ' << f[k][l][m] << std::endl;
                        }
                    }
                }
            }
            std::cout << f[n / 2][n / 2][n / 2] << std::endl;

            std::fclose(stdin);
            std::fclose(stdout);
        }
    }
}

int main() {
    noip::main();
    return 0;
}