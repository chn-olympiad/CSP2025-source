#include <bits/stdc++.h>
#define file(name, suf) #name"."#suf
#define input(name) freopen(file(name, in), "r", stdin)
#define output(name) freopen(file(name, out), "w", stdout)
#define mp std::make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<ull, ull> puu;
typedef std::tuple<int, puu, int> opt;
constexpr int N = 2e5 + 10, M = 5e6 + 10;
constexpr ull base = 131;
int n, q, id[N];
ll ans[N];
ull pw[M], hash[N][2], hsh[M][2];
std::string s[N][2], t[2];
std::vector<opt> op[N];
std::map<puu, int> map[M];

ull query(int l, int r, int w) {
    if (!l) return hsh[r][w];
    return hsh[r][w] - hsh[l - 1][w] * pw[r - l + 1];
}

puu query(int l, int r) {
    if (!l) return mp(hsh[r][0], hsh[r][1]);
    return mp(hsh[r][0] - hsh[l - 1][0] * pw[r - l + 1], hsh[r][1] - hsh[l - 1][1] * pw[r - l + 1]);
}

void solve() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i][0] >> s[i][1], id[i] = i;
    }
    std::sort(id + 1, id + n + 1, [&](const int& a, const int& b) { return s[a][0].size() < s[b][0].size(); });
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < s[id[i]][0].size(); ++j) {
            hash[i][0] = hash[i][0] * base + s[id[i]][0][j];
            hash[i][1] = hash[i][1] * base + s[id[i]][1][j];
        }
        map[s[id[i]][0].size()][mp(hash[i][0], hash[i][1])]++;
    }
    pw[0] = 1;
    for (int i = 1; i < M; i++) pw[i] = pw[i - 1] * base;
    for (int i = 1; i <= q; i++) {
        std::cin >> t[0] >> t[1], hsh[0][0] = t[0][0], hsh[0][1] = t[1][0];
        for (int j = 1; j < t[0].size(); j++) {
            hsh[j][0] = hsh[j - 1][0] * base + t[0][j];
            hsh[j][1] = hsh[j - 1][1] * base + t[1][j];
        }
        for (int l = 0; l < t[0].size(); l++) {
            if (!l || hsh[l - 1][0] == hsh[l - 1][1]) {
                for (int r = t[0].size() - 1; r >= l; r--) {
                    if (r == t[0].size() - 1 || query(r + 1, t[0].size() - 1, 0) == query(r + 1, t[0].size() - 1, 1)) {
                        ans[i] += map[r - l + 1][query(l, r)];
                    } else break;
                }
            } else break;
        }
        std::cout << ans[i] << '\n';
    }
}

int main() {
#ifdef LOCAL
    input(main), output(main);
#else
    input(replace), output(replace);
#endif
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // std::cin >> _;
    while (_--) solve();
    std::cerr << "Time : " << (double)clock() / CLOCKS_PER_SEC << '\n';
    return 0;
}