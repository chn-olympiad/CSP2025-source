/*

[2025-11-1 15:05] 已通过全部样例。
用时 35 min。


*/


#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 100005;
int n;
int a[N][3];
priority_queue<int> q[3];
int cnt[3];
int ans = 0;
signed Main() {
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
    while(!q[2].empty()) q[2].pop();
    cnt[0] = cnt[1] = cnt[2] = 0;
    ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for(int i = 1; i <= n; i ++) {
        int ma = max(a[i][0],
            max(a[i][1], a[i][2])
        ) ;
        if(ma == a[i][0]) {
            cnt[0] ++;
            q[0].push(max(a[i][1] - a[i][0], a[i][2] - a[i][0]));
        } else if(ma == a[i][1]) {
            cnt[1] ++;
            q[1].push(max(a[i][0] - a[i][1], a[i][2] - a[i][1]));
        } else {
            cnt[2] ++;
            q[2].push(max(a[i][0] - a[i][2], a[i][1] - a[i][2]));
        }
        ans += ma;
    }
    while(cnt[0] > n / 2) {
        cnt[0] --;
        ans += q[0].top();
        q[0].pop();
    }
    while(cnt[1] > n / 2) {
        cnt[1] --;
        ans += q[1].top();
        q[1].pop();
    }
    while(cnt[2] > n / 2) {
        cnt[2] --;
        ans += q[2].top();
        q[2].pop();
    }
    cout << ans << "\n";
    return 0;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t --) {
        Main();
    }
    return 0;
}