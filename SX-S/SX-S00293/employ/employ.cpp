#include <bits/stdc++.h>
#define file(name, suf) #name"."#suf
#define input(name) freopen(file(name, in), "r", stdin)
#define output(name) freopen(file(name, out), "w", stdout)
#define mp std::make_pair

constexpr int N = 20, Mod = 998244353;
int n, m, c[N], p[N], ans;
char s[N];

void solve() {
    std::cin >> n >> m >> (s + 1);
    for (int i = 1; i <= n; i++) std::cin >> c[i], p[i] = i;
    do {
        int x = 0;
        for (int i = 1; i <= n; i++) {
            if ((i - x - 1) < c[p[i]] && s[i] == '1') ++x;
        }
        if (x >= m) ++ans;
    } while (std::next_permutation(p + 1, p + n + 1));
    std::cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    input(main), output(main);
#else
    input(employ), output(employ);
#endif
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // std::cin >> _;
    while (_--) solve();
    std::cerr << "Time : " << (double)clock() / CLOCKS_PER_SEC << '\n';
    return 0;
}