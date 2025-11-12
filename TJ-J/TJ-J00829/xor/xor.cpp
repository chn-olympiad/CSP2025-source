#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[50010];
struct Node {
    int l, r;
};
vector<Node> tk;

int dfs(int u, int cnt, int last) {
    if (u >= tk.size()) return cnt;
    if (tk[u].l <= last) return dfs(u + 1, cnt, last);
    return max(dfs(u + 1, cnt, last), dfs(u + 1, cnt + 1, tk[u].r));
}
int yh(int l, int r) {
    int ans = a[l];
    for (int i = l + 1; i <= r; i++) ans ^= a[i];
    return ans;
}
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int mn = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], mn = max(mn, a[i]);
    if (mn == 1) {
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += a[i];
        cout << ans;
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (yh(i, j) == k) tk.push_back({i, j});
        }
    }
    cout << dfs(0, 0, 0);
    return 0;
}
