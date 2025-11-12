#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 505, mod = 998244353;

int c[N];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = " " + s;
    for(int i=1; i<=n; i++) cin >> c[i];

    vector<int> id(n + 1);
    iota(id.begin(), id.end(), 0);
    int ans = 0;
    do {
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(s[i] == '0') {
                cnt ++;
            } else {
                if(cnt >= c[id[i]]) cnt++;
            }
        }
        // for(int i=1; i<=n; i++) cout << id[i] << " \n"[i == n];
        // cout << cnt << "\n";
        ans += (cnt <= n - m);
    } while(next_permutation(id.begin() + 1, id.end()));
    cout << ans << "\n";
    return 0;
}