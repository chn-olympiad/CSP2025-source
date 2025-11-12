#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace Qiuyu3600 {
const int N = 1e5 + 10;
int n, a[N][3], d[N], cnt[3], ans;
inline int delta(const int &x) {
    int sec = 0;
    if(d[x] == 0) sec = max(a[x][1], a[x][2]);
    if(d[x] == 1) sec = max(a[x][0], a[x][2]);
    if(d[x] == 2) sec = max(a[x][0], a[x][1]);
    return sec - a[x][d[x]];
}
priority_queue<int> d0, d1, d2;
void Hutao() {
    ans = cnt[0] = cnt[1] = cnt[2] = 0;
    d0 = priority_queue<int>(), d1 = priority_queue<int>(), d2 = priority_queue<int>();
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) ans += a[i][0], d[i] = 0, ++ cnt[0], d0.push(delta(i));
        else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) ans += a[i][1], d[i] = 1, ++ cnt[1], d1.push(delta(i));
        else if(a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) ans += a[i][2], d[i] = 2, ++ cnt[2], d2.push(delta(i));
    }
    for(; cnt[0] > n >> 1; -- cnt[0]) ans += d0.top(), d0.pop();
    for(; cnt[1] > n >> 1; -- cnt[1]) ans += d1.top(), d1.pop();
    for(; cnt[2] > n >> 1; -- cnt[2]) ans += d2.top(), d2.pop();
    cout << ans << "\n";
}
}
signed main() {
    #ifndef DB
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #endif
    int t; cin >> t; while(t --) Qiuyu3600::Hutao();
    return 0;
}