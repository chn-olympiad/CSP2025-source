#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for(int i = (int)(a); i <= (int)(b); i ++)
#define DOW(i, a, b) for(int i = (int)(a); i >= (int)(b); i --)
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define poly vector<int>
const int N = 1e5 + 5, mod = 998244353;
int n, pp, m, id[N], cnt[N];
string s;
int c[N];
void Solve() {
    cin >> n >> m >> s;
    s =  ' ' + s;
    // REP(i, 1, n) cnt[i] = cnt[i - 1] + (s[i] == '0');
    REP(i, 1, n) cin >> c[i];
    REP(i, 1, n) id[i] = i;
    do {
        int ss = 0, ans = 0;
        REP(i, 1, n) 
        if(s[i] == '1' && c[id[i]] > ss) ans ++;
        else ss ++;
        // REP(i, 1, n) cerr << c[id[i]] << ' ';
        // cerr << ' ' << ans << '\n';
        if(ans >= m) pp ++;
    } while(next_permutation(id + 1, id + 1 + n));
    cout << pp << '\n';
}
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}