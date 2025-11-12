#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

// using i128 = __int128;
// using u128 = unsigned __int128;

std::string s;
int cnt[200];

void sol() {
    char c;
    while (std::cin >> c) {
        if (isdigit(c)) {
            s += c;
        }
    }

    for (char i : s) cnt[i]++;
    for (int i = 199; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            std::cout << char(i);
        }
    }
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

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
