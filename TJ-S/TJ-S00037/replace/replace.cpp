#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int n, q;
string s[MAXN][3], t[MAXN][3];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][1] >> s[i][2];
    }
    for (int i = 1; i <= q; i++) {
        cin >> t[i][1] >> t[i][2];
    }
    for (int i = 1; i <= q; i++) {
        int ans = 0;
        for (int j = 0; j < t[i][1].size(); j++) {
            string s1 = t[i][1].substr(0, j);
            for (int k = 1; k <= n; k++) {
                if (t[i][1].substr(j, s[k][1].size()) == s[k][1] && t[i][2] == s1 + s[k][2] + t[i][1].substr(j + s[k][1].size(), t[i][1].size() - (j + s[k][1].size()))) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
