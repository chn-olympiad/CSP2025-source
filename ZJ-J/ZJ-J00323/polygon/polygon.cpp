#include <bits/stdc++.h>
using namespace std;
int a[5005], n, cnt = 0;
void dfs(int now, int sum, int maxx) {
    cout << now << ' ' << sum << ' ' << maxx << '\n';
    if (now == n) {
        if (sum > maxx * 2)
            cnt++;
        return;
    }
    // choose it
    dfs(now + 1, sum += a[now + 1], max(maxx, a[now + 1]));
    //do not choose
    dfs(now + 1, sum, maxx);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    dfs(0, 0, 0);
    cout << cnt << '\n';
    return 0;
}