#include <bits/stdc++.h>
using namespace std;
namespace Main {
#define int long long
#define endl '\n'
#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename ...Tail>
void debug_out(Head H, Tail... T) {
    cerr << ' ' << H;
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif // LOCAL
const int N = 1e5 + 55;
int T, n, m, a[N][3], b[N], c[3], d[N];
int func() {
    int ans = 0;
    m = 0;
    for (int i = 1; i <= n; i++) {
        int x = max(max(a[i][0], a[i][1]), a[i][2]);
        ans += x;
        if (a[i][0] == x) d[i] = 0;
        else if (a[i][1] == x) d[i] = 1;
        else d[i] = 2;
        c[d[i]]++;
    }
    int k = -1;
    for (int j = 0; j < 3; j++)
        if (c[j] > n / 2) k = j;
    if (k == -1) return ans;
    for (int i = 1; i <= n; i++) {
        int k1 = (k + 1) % 3, k2 = (k + 2) % 3;
        if (d[i] != k) continue;
        b[++m] = a[i][k] - max(a[i][k1], a[i][k2]);
    }
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= c[k] - n / 2; i++)
        ans -= b[i];
    return ans;
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0), ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
        cout << func() << endl;
        for (int i = 0; i < 3; i++) c[i] = 0;
    }
    return 0;
}
}
signed main() {
    Main::main();
    return 0;
}

