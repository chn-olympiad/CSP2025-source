#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int maxn = 1e5+5;

int T;
int n;

struct Member {
    int sel;
    ll a, b, c; ll mx, sc;
    Member(): sel(0), a(0), b(0), c(0), mx(0), sc(0) {}
};
vector<Member> a;

// 先把哪里部门最多给求出来，其他的肯定都不可能超过n/2
// 如果不存在有部门是超过n/2的，直接满足所有人的需求
// 如果存在，优先考虑谁对其他部门的需求量更大
// 

// 好的，思路很清晰

// n <= 30
namespace solve1{
struct Member {
    ll a, b, c;
};
vector<Member> a;
int lim;
ll ans = 0xc0c0c0c0c0c0c0c0;
void dfs(int cur, ll s, int mema, int memb, int memc) {
    if (cur == n) {
        ans = max(ans, s);
        return void();
    }
    if (mema < lim) { dfs(cur+1, s + a[cur].a, mema+1, memb, memc); } 
    if (memb < lim) { dfs(cur+1, s + a[cur].b, mema, memb+1, memc); } 
    if (memc < lim) { dfs(cur+1, s + a[cur].c, mema, memb, memc+1); } 
}
void solve() {
    a.resize(n);
    ans = 0xc0c0c0c0c0c0c0c0;
    lim = n >> 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    dfs(0, 0, 0, 0, 0);
    cout << ans << '\n';
}
}

// // to all a2 == a2 == 0
// namespace solve2 {
// void solve() {
//     sort(a.begin(), a.end(), [&](const Member&x, const Member&y){ return x.a > y.a; } );
//     ll ans = 0;
//     for (int i = 0; i < (n<<1); ++i) {
//         ans += a[i].a;
//     }
//     cout << ans << '\n';
// }
// };



signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n <= 10) { solve1::solve(); continue; }
        vector<Member>(n).swap(a);
        // bool flag = 1;
        int mema = 0, memb = 0, memc = 0;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            ll mx = max({a[i].a, a[i].b, a[i].c});
            a[i].mx = mx;
            
            // find the middle size number
            // ll mn = min({a[i].a, a[i].b, a[i].c});
            if ((a[i].b <= a[i].a && a[i].a <= a[i].c) || (a[i].c <= a[i].a && a[i].a <= a[i].b)) { a[i].sc = a[i].a; }
            if ((a[i].a <= a[i].b && a[i].b <= a[i].c) || (a[i].c <= a[i].b && a[i].b <= a[i].a)) { a[i].sc = a[i].b; }
            if ((a[i].b <= a[i].c && a[i].c <= a[i].a) || (a[i].a <= a[i].c && a[i].c <= a[i].b)) { a[i].sc = a[i].c; }
            
            if (mx == a[i].a) { a[i].sel ^= 0b0001; }
            if (mx == a[i].b) { a[i].sel ^= 0b0010; }
            if (mx == a[i].c) { a[i].sel ^= 0b0100; }

            if (mx == a[i].a) {
                ++mema; ans += a[i].a;
            } else if (mx == a[i].b) {
                ++memb; ans += a[i].b;;
            } else {
                ++memc; ans += a[i].c;;
            }
            // if (a[i].b | a[i].c) { flag = 0; }
        }
        // if (flag) { solve2::solve(); continue; }
        int mxsz = max({mema, memb, memc});
        // 如果每个人的条件都可以满足
        if (mxsz <= (n>>1)) {
            // cerr << "Im at testcase " << T << endl;
            cout << ans << '\n'; continue;
        }

        int mxc = 0;
        if (mxsz == mema) { mxc = 0b0001; }
        if (mxsz == memb) { mxc = 0b0010; }
        if (mxsz == memc) { mxc = 0b0100; }
        // cerr << n << ' ' << mema << ' ' << memb << ' ' << memc << endl;
        vector<int> rm(mxsz);
        int rmcnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].sel & mxc) {
                rm[rmcnt++] = a[i].mx - a[i].sc;
            }
        }
        sort(rm.begin(), rm.end());
        // for (int x : rm) { cerr << x << ' '; }
        // 如果不是每个人都可以被满足，找第二志愿与第一志愿差小的，给差小的人换上第二志愿
        // sort(a.begin(), a.end(), [&](const Member&x, const Member&y){ return !(x.sel !=mxc && y.sel == mxc); });
        // cerr << "Im running" << endl;
        // sort(a.begin(), a.end(), [&](const Member&x, const Member&y){ return x.mx - x.sc < y.mx - y.sc; });
        // cerr << mxsz - (n>>1) << endl;
        for (int i = 0; i < mxsz - (n>>1); ++i) {
            ans -= rm[i];
        }

        cout << ans << '\n';
    }

    return 0;
}

