#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int t, n, m;
struct Node {
    int x, id, d;
} a[3 * N];
int b[N][4];
int cnt[4];
bitset<N> st;
int ans;

void dfs(int u, int sum) {
    if (u == n + 1) {
        ans = max(ans, sum);
        return;
    }
    if (cnt[1] < m) {
        cnt[1] ++;
        dfs(u + 1, sum + b[u][1]);
        cnt[1] --;
    }
    if (cnt[2] < m) {
        cnt[2] ++;
        dfs(u + 1, sum + b[u][2]);
        cnt[2] --;
    }
    if (cnt[3] < m) {
        cnt[3] ++;
        dfs(u + 1, sum + b[u][3]);
        cnt[3] --;
    }
}

void solve() {
    memset(cnt, 0, sizeof cnt);
    st.reset();
    cin >> n;
    m = n / 2;
    ans = 0;
    bool flag = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1, x; j <= 3; j ++) {
            cin >> x;
            b[i][j] = x;
            if (j > 1 && x) flag = 0;
        }
    if (n <= 8) {
        dfs(1, 0);
        cout << ans << '\n';
        return;
    }
    if (flag) {
        int idx = 0;
        for (int i = 1; i <= n; i ++)
            a[++ idx] = {b[i][1], i, 0};
        sort(a + 1, a + idx + 1, [](Node p, Node q) {
            return p.x > q.x;
        });
        for (int i = 1; i <= m; i ++)
            ans += a[i].x;
        cout << ans << '\n';
        return;
    }
    {
        int idx = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 3; j ++) {
                a[++ idx] = {b[i][j], i, j};
            }
        }
        sort(a + 1, a + idx + 1, [](Node p, Node q) {
            return p.x > q.x;
        });
        for (int i = 1; i <= idx; i ++) {
            int x = a[i].x, id = a[i].id, d = a[i].d;
            if (cnt[d] >= m) continue;
            if (st[id]) continue;
            st[id] = 1, cnt[d] ++;
            ans += x;
        }
        cout << ans << '\n';
    }
}

int main() {
    freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t --) solve();
    return 0;
}