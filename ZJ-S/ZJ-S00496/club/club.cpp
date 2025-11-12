#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 1e5 + 5;

int n, a[N][3], f[N][2];
int mx[N], md[N], mn[N];
int mxid[N], mdid[N], mnid[N];

struct Node {
    int id, now;

    friend bool operator < (const Node &lhs, const Node &rhs) {
        if (f[lhs.id][lhs.now] != f[rhs.id][rhs.now]) return f[lhs.id][lhs.now] < f[rhs.id][rhs.now];
        return lhs.id > rhs.id;
    }
};

i64 ans;
std::priority_queue<Node> Q;

void sol() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        mx[i] = std::max({a[i][0], a[i][1], a[i][2]});
        mn[i] = std::min({a[i][0], a[i][1], a[i][2]});
        md[i] = a[i][0] + a[i][1] + a[i][2] - mx[i] - mn[i];
        f[i][1] = mx[i] - md[i];
        f[i][0] = md[i] - mn[i];
        Q.push(Node{i, 1});
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == mx[i]) mxid[i] = j;
        }
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == md[i] && j != mxid[i]) mdid[i] = j;
        }
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == mn[i] && j != mxid[i] && j != mdid[i]) mnid[i] = j;
        }
        // std::cout << mx[i] << " " << md[i] << " " << mn[i] << "  " << mxid[i] << " " << mdid[i] << " " << mnid[i] << "\n";
    }

    int cnt[3] = {0, 0, 0};
    ans = 0;

    while (Q.size()) {
        auto tmp = Q.top();
        Q.pop();
        int id = tmp.id, now = tmp.now;
        if (now == 1) {
            if (cnt[mxid[id]] < n / 2) {
                cnt[mxid[id]]++;
                ans += mx[id];
            } else {
                Q.push(Node{id, 0});
            }
        } else {
            if (cnt[mdid[id]] < n / 2) {
                cnt[mdid[id]]++;
                ans += md[id];
            } else {
                cnt[mnid[id]]++;
                ans += mn[id];
            }
        }
    }
    std::cout << ans << "\n";
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // init();
    int T = 1;
    std::cin >> T;
    while (T--) sol();
    return 0;
}