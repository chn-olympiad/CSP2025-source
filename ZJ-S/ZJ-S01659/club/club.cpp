#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define P emplace_back
bool MBE;
namespace SOLVER {
const int N = 1e5 + 5;
int n, a[N][3], id[N], c[3], ans; vector<int> res;
void MAIN() {
    cin >> n; ans = 0; c[0] = c[1] = c[2] = 0; res.clear();
    rep(i, 1, n) {
        rep(j, 0, 2) cin >> a[i][j]; id[i] = 0;
        if(a[i][1] > a[i][id[i]]) id[i] = 1; if(a[i][2] > a[i][id[i]]) id[i] = 2;
        ans += a[i][id[i]], c[id[i]]++;
    }
    rep(k, 0, 2) if(c[k] > n / 2) {
        rep(i, 1, n) if(id[i] == k) res.P(a[i][k] - max(a[i][!k], a[i][3 - k - !k]));
        sort(res.begin(), res.end()); // for(int x : res) cerr << x << ' '; cerr << endl;
        rep(i, 0, c[k] - n / 2 - 1) ans -= res[i]; break; 
    }
    cout << ans << '\n';
}
}
bool MED;
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t; cin >> t; while(t--) SOLVER::MAIN();
    cerr << (&MBE - &MED) / 1024 << " kb, " << clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}