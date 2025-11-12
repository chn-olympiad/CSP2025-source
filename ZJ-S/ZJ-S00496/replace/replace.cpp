#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 2e5 + 5;
constexpr int mod = 998244853;
int base;
std::mt19937 rnd(time(0));

int n, q, len;
std::string s[N][2];
int l[N][2], r[N][2];

void sol() {
    base = rnd() % 1000 + 500;

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i][0] >> s[i][1];
        len += s[i][0].size() + s[i][1].size();
    }
    if (len > 2000) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0, k = 0; j < (int)s[i][0].size(); j++) {
                if (s[i][0][j] == 'b') {
                    k = 1;
                    continue;
                }
                if (k == 0) {
                    l[i][0]++;
                } else {
                    r[i][0]++;
                }
            }
            for (int j = 0, k = 0; j < (int)s[i][1].size(); j++) {
                if (s[i][1][j] == 'b') {
                    k = 1;
                    continue;
                }
                if (k == 0) {
                    l[i][1]++;
                } else {
                    r[i][1]++;
                }
            }
            // std::cout << l[i][0] << " " << r[i][0] << "  " << l[i][1] << " " << r[i][1] << "\n";
        }
        while (q--) {
            int l0 = 0, r0 = 0, l1 = 0, r1 = 0;
            std::string t0, t1;
            std::cin >> t0 >> t1;
            for (int j = 0, k = 0; j < (int)t0.size(); j++) {
                if (t0[j] == 'b') {
                    k = 1;
                    continue;
                }
                if (k == 0) {
                    l0++;
                } else {
                    r0++;
                }
            }
            for (int j = 0, k = 0; j < (int)t1.size(); j++) {
                if (t1[j] == 'b') {
                    k = 1;
                    continue;
                }
                if (k == 0) {
                    l1++;
                } else {
                    r1++;
                }
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                cnt += (l0 >= l[i][0] && l1 - l0 == l[i][1] - l[i][0] && r0 >= r[i][0] && r1 - r0 == r[i][1] - r[i][0]);
            }
            // std::cout << l0 << " " << r0 << "  " << l1 << " " << r1 << "  ";
            std::cout << cnt << "\n";
        }
        return;
    }
    while (q--) {
        std::string t, T;
        std::cin >> t >> T;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int cur = 0, p = t.find(s[i][0], cur);
            while (p >= 0) {
                if (p == cur && t.replace(p, s[i][0].size(), s[i][1]) == T) {
                    // std::cout << t << " " << p << "\n";
                    cnt++;
                }
                t.replace(p, s[i][1].size(), s[i][0]);
                cur++;
                p = t.find(s[i][0], cur);
            }
        }
        std::cout << cnt << "\n";
    }
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // init();
    int T = 1;
    // std::cin >> T;
    while (T--) sol();
    return 0;
}