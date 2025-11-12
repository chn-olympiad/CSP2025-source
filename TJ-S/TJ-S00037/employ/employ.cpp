#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, m, ans, c[MAXN], cnt, p[MAXN];
string s;

void solve()
{
    int fn = 0, gn = 0;
    for (int i = 1; i <= n; i++) {
        if (fn >= c[p[i]] || s[i - 1] == '0') {
            fn++;
        } else {
            gn++;
        }
    }
    if (gn >= m) {
        ans++;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        p[i] = i;
    }
    do {
        solve();
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans << endl;

    return 0;
}
