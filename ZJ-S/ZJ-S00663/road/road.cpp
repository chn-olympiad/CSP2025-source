#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
int ans = 0;
int f[10010];

class Edge {
    public:
        int st, ed;
        int w;
        bool operator< (Edge &other) {
            return w < other.w;
        }
} e[1000010];

int find (int x) {
    if (x == f[x]) {
        return x;
    }
    return f[x] = find (f[x]);
}

signed main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        f[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i].st = u;
        e[i].ed = v;
        e[i].w = w;
    }

    int npr[10010];
    for (int i = 1; i <= k; ++i) {
        int c;
        cin >> c;

        for (int j = 1; j <= n; ++j) {
            cin >> npr[j];
        }
    }

    sort (e + 1, e + m + 1);

    int tot = 0;
    for (int i = 1; i <= m; ++i) {
        int u = e[i].st;
        int v = e[i].ed;
        int fu = find (u);
        int fv = find (v);

        if (fu != fv) {
            f[fv] = fu;
            ans += e[i].w;
            ++tot;
        }

        if (tot == n - 1) {
            break;
        }
    }

    cout << ans << endl;

    fclose (stdin);
    fclose (stdout);
    return 0;
}
