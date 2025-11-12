#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N][7], n, c[4];

inline void solve() {
    cin >> n;
    c[1] = c[2] = c[3] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
            c[1] ++, ans += a[i][1], a[i][0] = 1;
            if(a[i][2] > a[i][3]) a[i][4] = 2;
            else a[i][4] = 3;
        }
        else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
            c[2] ++, ans += a[i][2], a[i][0] = 2;
            if(a[i][1] > a[i][3]) a[i][4] = 1;
            else a[i][4] = 3;
        }
        else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {
            c[3] ++, ans += a[i][3], a[i][0] = 3;
            if(a[i][2] > a[i][1]) a[i][4] = 2;
            else a[i][4] = 1;
        }
    }
    int id = 0;
    if(c[1] > n / 2) id = 1;
    if(c[2] > n / 2) id = 2;
    if(c[3] > n / 2) id = 3;
    if(id == 0) {
        cout << ans << '\n';
        return;
    }
    priority_queue<int, vector<int> > q;
    for(int i = 1; i <= n; i ++) {
        if(a[i][0] != id) continue;
        q.push(a[i][a[i][4]] - a[i][id]);
        if(q.size() > n / 2)
            ans += q.top(), q.pop();
    }
    cout << ans << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T --) solve();
}