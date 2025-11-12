#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef array<int, 3> ai3;

const int N = 2e2 + 5, M = 1e5 + 5;

ai3 a[M];

int dp[N][N][N];

vector<pii> b[M];
int id[M], n;

void solve1() {
    memset(dp, 0, sizeof dp);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=min(i, n/2); j++) {
            for(int k=0; k<=min(i, n/2); k++) {
                int l = i - j - k;
                if(l > n / 2) continue;
                if(j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + a[i][0]);
                if(k) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + a[i][1]);
                if(l) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + a[i][2]);
            }
        }
    }
    int ans = 0;
    for(int j=0; j<=n/2; j++) {
        for(int k=0; k<=n/2; k++) {
            int l = n - j - k;
            if(l > n / 2) continue;
            ans = max(ans, dp[n][j][k]);
        }
    }
    cout << ans << "\n";
}

void solve2() {
    for(int i=1; i<=n; i++) id[i] = 0;

    for(int i=1; i<=n; i++) {
        b[i].resize(3);
        for(int j=0; j<3; j++) {
            b[i][j].first = a[i][j];
            b[i][j].second = j;
        }
        sort(b[i].begin(), b[i].end(), greater<pii>());
    }
    sort(b + 1, b + 1 + n);
    ll ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q[3];
    for(int i=n; i>=1; i--) {
        int x = b[i][0].first, c = b[i][0].second;
        int y = b[i][1].first, d = b[i][1].second;
        if(q[c].size() < n / 2) {
            ans += x;
            q[c].push({x, i});
        } else {
            auto u = q[c].top();
            int res1 = u.first + y;
            int res2 = b[u.second][id[u.second] + 1].first + x;
            ans += y;
            if(res1 < res2) {
                ans -= res1;
                ans += res2;
                q[c].pop();
                q[c].push({x, i});
                id[u.second] ++;
                q[b[u.second][id[u.second]].second].push(u);
            } else {
                q[d].push({y, i});
            }
        }
    }
    cout << ans << "\n";
}

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            cin >> a[i][j];
        }
    }
    if(n <= 200) {
        solve1();
    } else {
        solve2();
    }
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) solve();

    return 0;
}