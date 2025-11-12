#include <iostream>
#include <string>

namespace noip {
    using Int = long long;
    using UInt = unsigned long long;

    std::string s;
    Int cnt[1 + 9] {};
    bool flag = false;

    void main() {
        std::freopen("number.in", "r", stdin);
        std::freopen("number.out", "w", stdout);

        std::cin >> s;
        for (Int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') cnt[s[i] - '0']++, flag = flag || (s[i] >= '1' && s[i] <= '9');
        }

        if (!flag) {
            std::cout << 0 << std::endl;
        } else {
            for (Int i = 9; i >= 0; i--) {
                for (Int j = 1; j <= cnt[i]; j++) {
                    std::cout << i;
                }
            }
            std::cout << std::endl;
        }

        std::fclose(stdin);
        std::fclose(stdout);
    }
}

int main() {
    noip::main();
    return 0;
}