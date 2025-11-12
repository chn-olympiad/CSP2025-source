#include <bits/stdc++.h>
using namespace std;

#define int long long

#define file(name) assert(freopen(#name".in", "r", stdin)), assert(freopen(#name".out", "w", stdout))
#define _f(i, a, b) for(int i = a; i <= b; ++i)
#define _d(i, a, b) for(int i = a; i >= b; --i)
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define all(container) container.begin(), container.end()

constexpr int N = 1e5 + 5;

int n, cnt[3], ans;
pii a[N][3];
priority_queue<int, vector<int>, greater<int>> pq[3];

void solve() {
    cin >> n, ans = 0;
    memset(cnt, 0, sizeof cnt);
    _f(i, 0, 2) {
        while(pq[i].size()) pq[i].pop();
    }
    _f(i, 1, n) {
        _f(j, 0, 2) cin >> a[i][j].fi, a[i][j].se = j;
        sort(a[i], a[i] + 3);
        cnt[a[i][2].se]++, ans += a[i][2].fi;
        pq[a[i][2].se].emplace(a[i][2].fi - a[i][1].fi);
    }
    _f(i, 0, 2) if(cnt[i] > n / 2) {
        int s = cnt[i] - n / 2;
        while(s--) {
            int x = pq[i].top(); pq[i].pop();
            ans -= x;
        }
    }
    cout << ans << '\n';
}

signed main() {
    file(club);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while(tt--)
    solve();
    return 0;
}