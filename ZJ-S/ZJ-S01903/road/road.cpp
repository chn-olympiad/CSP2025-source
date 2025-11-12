#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e4, K = 10;

using PII = pair<int, int>;
using PIII = pair<int, PII>;

int n, m, k, a[K][N], sum = 0, c[K], fa[N], ans;
bool flg = true;
vector<PIII> e;

int find(int x) {
    return fa[x] == x ? x : find(fa[x]);
}
int cd(int x, int y) {
    int minn = INT_MAX;
    for (int i = 1; i <= k; i ++ )
        minn = min(minn, a[i][x] + a[i][y]);
    return minn;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1, x, y, z; i <= m; i ++ ) {
        cin >> x >> y >> z;
        e.push_back({z, {x, y}});
        sum += z;
    }
    for (int i = 1; i <= k; i ++ ) {
        cin >> c[i];
        flg &= (c[i] == 0);
        for (int j = 1; j <= n; j ++ )
            cin >> a[i][j];
    }
    if (k == 0) {
        cout << sum << '\n';
        return 0;
    }
    if (flg) {
        for (int i = 1; i <= n; i ++ )  fa[i] = i;
        for (int i = 1; i <= k; i ++ )
            for (int j = 1; j <= n; j ++ )
                e.push_back({a[i][j], {i, j}});
        sort(e.begin(), e.end());
        int sum = 0;
        for (PIII pii : e) {
            int x = pii.second.first, y = pii.second.second, fax = find(x), fay = find(y);
            if (fax == fay) continue;
            sum ++ ;
            ans += pii.first;
            if (sum >= n - 1 + k)   break;
            fa[fax] = fay;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
4 3 1
1 2 5
2 4 3
1 3 2
0 5 1 3 1
*/