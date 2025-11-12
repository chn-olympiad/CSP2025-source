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
const int N = 2e5 + 5;
const int mod = 998244353, bas = 31;
int n, q, cnt[N], pw[N], p0[(int)5e6 + 5], p1[(int)5e6 + 5], q0[(int)5e6 + 5], q1[(int)5e6 + 5];
bool flag;
string s[N][2];
unordered_map<int, poly> pre0, pre1, suf0, suf1;
int geth(int* p, int l, int r) {
    return (p[r] - 1ll * (!l ? 0 : p[l - 1]) * pw[r - l + 1] % mod + mod) % mod;
}
int gett(int* p, int l, int r) {
    // if(flag) cerr << p[l] << ' ' << l << ' ' << r << ' ' << p[r + 1] << '\n';
    return (p[l] - 1ll * p[r + 1] * pw[r - l + 1] % mod + mod) % mod;
}
bool chk(int l, int r) {
    return geth(p0, l, r) == geth(p1, l, r);
}
void Solve() {
    int n, q;
    cin >> n >> q;
    REP(i, 1, n) cin >> s[i][0] >> s[i][1];
    REP(i, pw[0] = 1, N - 1) pw[i] = 1ll * pw[i - 1] * bas % mod;
    REP(i, 1, n) {
        int sm = 0, len = s[i][0].size();
        REP(j, 0, len - 1) sm = (1ll * sm * bas + s[i][0][j] - 96) % mod, pre0[sm].pb(i);
        sm = 0;
        REP(j, 0, len - 1) sm = (1ll * sm * bas + s[i][1][j] - 96) % mod, pre1[sm].pb(i);
        sm = 0;
        DOW(j, len - 1, 0) sm = (1ll * sm * bas + s[i][0][j] - 96) % mod, suf0[sm].pb(i);
        // if(i == 3) cerr << sm << '\n';
        sm = 0;
        DOW(j, len - 1, 0) sm = (1ll * sm * bas + s[i][1][j] - 96) % mod, suf1[sm].pb(i);
    }
    while(q --) {
        string t0, t1;
        cin >> t0 >> t1, q0[t0.size()] = q1[t1.size()] = 0;
        REP(i, 0, t0.size() - 1) p0[i] = (1ll * (!i ? 0 : p0[i - 1]) * bas + t0[i] - 96) % mod;
        REP(i, 0, t1.size() - 1) p1[i] = (1ll * (!i ? 0 : p1[i - 1]) * bas + t1[i] - 96) % mod;
        DOW(i, t0.size() - 1, 0) q0[i] = (1ll * (i == (int)t0.size() - 1 ? 0 : q0[i + 1]) * bas + t0[i] - 96) % mod;
        DOW(i, t0.size() - 1, 0) q1[i] = (1ll * (i == (int)t1.size() - 1 ? 0 : q1[i + 1]) * bas + t1[i] - 96) % mod;
        // cerr << q0[0] << '\n';
        int l = 0, r = t0.size() - 1, pl = 0, pr = t0.size() - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(chk(0, mid)) l = mid + 1;
            else r = mid - 1, pl = mid;
        }
        l = 0, r = t0.size() - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(chk(mid, t0.size() - 1)) r = mid - 1;
            else l = mid + 1, pr = mid;
        }
        poly del;
        DOW(i, pl, 0) {
            int now = geth(p0, i, pr);
            if(pre0.count(now)) 
                for(auto v : pre0[now])
                    cnt[v] ++, del.pb(v);
            now = geth(p1, i, pr);
            if(pre1.count(now)) 
                for(auto v : pre1[now])
                    cnt[v] ++, del.pb(v);
        }
        // cerr << pl << ' ' << pr << '\n';
        // cerr << cnt[3] << '\n';
        REP(i, pr, t0.size() - 1) {
            // if(i == pr) flag = 1;
            int now = gett(q0, pl, i);
            // flag = 0;
            // if(i == pr) cerr << now << '\n';
            if(suf0.count(now)) 
                for(auto v : suf0[now])
                    cnt[v] ++, del.pb(v);
            now = gett(q1, pl, i);
            if(suf1.count(now)) 
                for(auto v : suf1[now])
                    cnt[v] ++, del.pb(v);
        }
        int ans = 0;
        
        for(auto v : del) {
            if(cnt[v] == 4) ans ++;
            cnt[v] = 0;
        }
        cout << ans << '\n';
    }
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}