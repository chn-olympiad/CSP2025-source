#include<bits/stdc++.h>
using namespace std;
struct data {
    int a, b, c;
} a[100005];
int n;
namespace case55 {
    int f[205][205][205];
    void main() {
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                for(int k = 0; k + j <= i; k++) {
                    if(j) f[i][j][k] = max(f[i - 1][j - 1][k] + a[i].a, f[i][j][k]);
                    if(k) f[i][j][k] = max(f[i - 1][j][k - 1] + a[i].b, f[i][j][k]);
                    if(i - j - k) f[i][j][k] = max(f[i - 1][j][k] + a[i].c, f[i][j][k]);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i <= n / 2 && j <= n / 2 && (n - i - j) <= n / 2) {
                    ans = max(ans, f[n][i][j]);
                }
            }
        }
        cout << ans << endl;
        return;
    }
}
namespace sol {
    int p = 0;
    vector<data> v[4];
    void main() {
        p = 0;
        v[1].clear(); v[2].clear(); v[3].clear();
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i].a >= a[i].b && a[i].a >= a[i].c) v[1].push_back(a[i]), ans += a[i].a;
            else if(a[i].b >= a[i].a && a[i].b >= a[i].c) v[2].push_back(a[i]), ans += a[i].b;
            else v[3].push_back(a[i]), ans += a[i].c;
        }
        if((int)v[1].size() * 2 > n) p = 1;
        if((int)v[2].size() * 2 > n) p = 2;
        if((int)v[3].size() * 2 > n) p = 3;
        if(p == 0) return cout << ans << endl, void();
        vector<int> t;
        for(auto x : v[p]) {
            if(p == 1) t.push_back(x.a - max(x.b, x.c));
            else if(p == 2) t.push_back(x.b - max(x.a, x.c));
            else t.push_back(x.c - max(x.a, x.b));
        }
        sort(t.begin(), t.end());
        for(int i = 0; i < (int)t.size() - n / 2; i++) {
            ans -= t[i];
        }
        cout << ans << endl;
    }
}
inline void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b >> a[i].c;
    if(n <= 200) return case55::main();
    sol::main();
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _ = 0;
    cin >> _;
    while(_--) solve();


    return 0;
}