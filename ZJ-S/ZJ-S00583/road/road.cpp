#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    char ch = getchar();
    int x = 0, m = 1;
    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * m;
}

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 1e4 + 5;

int f[N], w[15];

int gf(int x) {
    return (x == f[x]) ? x : (f[x] = gf(f[x]));
}

void merge(int x, int y) {
    x = gf(x), y = gf(y);
    f[x] = y;
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, pr>> edge, Edge;
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edge.pb({w, {x, y}});
    }
    sort(edge.begin(), edge.end());
    for (int i = 1; i <= n; i++) f[i] = i;
    ll ans = 0;
    for (auto u : edge) {
        int x = u.second.first, y = u.second.second;
        if (gf(x) != gf(y)) {
            ans += u.first;
            Edge.pb(u);
            merge(x, y);
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> w[i];
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            Edge.pb({x, {i + n, j}});
        }
    }
    sort(Edge.begin(), Edge.end());
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 1; j <= n + k; j++) f[j] = j;
        ll res = 0, tot = n + __builtin_popcount(i);
        for (int j = 1; j <= k; j++) if ((i >> (j - 1)) & 1) res += w[j];
        for (auto u : Edge) {
            int x = u.second.first, y = u.second.second;
            if (x <= n || (i >> (x - n - 1)) & 1) {
                if (gf(x) != gf(y)) {
                    res += u.first, merge(x, y), tot--;
                    if (res >= ans || tot == 1) break;
                }
            }
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
}