#include <bits/stdc++.h>
#define file(name, suf) #name"."#suf
#define input(name) freopen(file(name, in), "r", stdin)
#define output(name) freopen(file(name, out), "w", stdout)
#define mp std::make_pair

typedef long long ll;
constexpr int N = 1e4 + 10, M = 1e6 + 10, K = 11;
int n, m, k, c[K], f[N + K];
struct edge {int u, v, w; } e[M];
std::vector<edge> E;
ll ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    return f[v] = u, true;
}

ll calc(int s) {
    ll res = 0;
    for (int i = 0; i < k; i++) if (s >> i & 1) res += c[i];
    for (int i = 1; i <= n + k; i++) f[i] = i;
    for (auto& [u, v, w] : E) {
        if (u <= n && v <= n) {
            if (merge(u, v)) res += w;
        } else {
            if (s >> (u - n - 1) & 1) {
                if (merge(u, v)) res += w;
            }
        }
    }
    return res;
}

void solve() {
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) std::cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1; i <= n; i++) f[i] = i;
    std::sort(e + 1, e + m + 1, [&](const edge& a, const edge& b) { return a.w < b.w; });
    for (int i = 1; i <= m; i++) {
        if (merge(e[i].u, e[i].v)) {
            ans += e[i].w;
            E.emplace_back(e[i]);
        }
    }
    for (int i = 1; i <= k; i++) {
        std::cin >> c[i - 1];
        for (int j = 1, w; j <= n; j++) {
            std::cin >> w, E.emplace_back(edge{n + i, j, w});
        }
    }
    std::sort(E.begin(), E.end(), [&](const edge& a, const edge& b) { return a.w < b.w; });
    for (int s = 1; s < (1 << k); s++) ans = std::min(ans, calc(s));
    std::cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    input(main), output(main);
#else
    input(road), output(road);
#endif
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // std::cin >> _;
    while (_--) solve();
    std::cerr << "Time : " << (double)clock() / CLOCKS_PER_SEC << '\n';
    return 0;
}