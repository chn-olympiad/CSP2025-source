#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 10;
int T, n, cnt[4], ans;
struct Node{
    int val, i, j;
    bool operator < (const Node A) const{
        return val < A.val;
    }
};
vector<pii> a[N];
priority_queue<Node> q[4];
void update(int mx){
    while(cnt[mx] > n / 2){
        auto now = q[mx].top();
        q[mx].pop();
        if(now.j == 0) continue;
        ans += now.val, cnt[mx]--;
        cnt[a[now.i][now.j - 1].second]++;
        if(now.j > 1) q[a[now.i][now.j - 1].second].push(Node{-a[now.i][now.j - 1].first + a[now.i][now.j - 2].first, now.i, now.j - 1});
        // cout << ans << endl;
    }
}
void solve(){
    cin >> n, ans = 0;
    for(int i = 1; i <= 3; i++){
        cnt[i] = 0;
        while(!q[i].empty()) q[i].pop();
    }
    for(int i = 1; i <= n; i++) a[i].clear();
    for(int i = 1, x; i <= n; i++){
        for(int j = 1; j <= 3; j++) cin >> x, a[i].push_back({x, j});
        sort(a[i].begin(), a[i].end());
        cnt[a[i][2].second]++, q[a[i][2].second].push(Node{-a[i][2].first + a[i][1].first, i, 2}), ans += a[i][2].first;
    }
    while(max({cnt[1], cnt[2], cnt[3]}) > n / 2){
        for(int j = 1; j <= 3; j++)
            if(cnt[j] > n / 2) update(j);
    }
    cout << ans << endl;
}
int main(){
    // freopen("example/club5.in", "r", stdin);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}