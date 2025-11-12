#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, P = 998244353;
int n, m, c[N];
string s;
ll ans;
int p[N], vis[N];
void Check() {
    int now = 0, emp = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '0' || now >= c[p[i]]) {
            ++now;
        } else {
            ++emp;
        }
    }
    if (emp >= m) (++ans) %= P;
}
void DFS(int u) {
    if (u == n + 1) return Check();
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            vis[i] = 1, p[u] = i;
            DFS(u + 1);
            vis[i] = 0, p[u] = 0;
        }
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    DFS(1);
    cout << ans << '\n';
    return 0;
}
// 8 pts