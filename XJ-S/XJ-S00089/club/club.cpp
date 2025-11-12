#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using std::cin;
using std::cout;
const int N = 1e5 + 3;
int n, a[N][4], ans;
int cl[4];
bool vis[N];
struct node{
    int num, x, y;
    bool friend operator<(node p, node q){
        return p.num > q.num || (p.num == q.num && a[p.y][p.x] > a[q.y][q.x]);
    }
} s[3 * N];
void solve(){
    cin >> n;
    memset(vis, 0, sizeof vis);
    memset(cl, 0, sizeof cl);
    for (int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        s[i * 3 - 2] = {a[i][1] - a[i][2] - a[i][3], 1, i};
        s[i * 3 - 1] = {a[i][2] - a[i][1] - a[i][3], 2, i};
        s[i * 3] = {a[i][3] - a[i][2] - a[i][1], 3, i};
    }
    std::sort(s + 1, s + 3 * n + 1);
    int ans = 0;
    for (int i = 1; i <= 3 * n; i++){
        if (vis[s[i].y] || cl[s[i].x] == n / 2)
            continue;
        ans += a[s[i].y][s[i].x];
        vis[s[i].y] = 1, cl[s[i].x]++;
    }
    cout << ans << '\n';
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
        solve();
}
