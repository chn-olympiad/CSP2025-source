#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, q;
string a[N][2];

int main() {
    freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i][0] >> a[i][1];
    while (q --) {
        string s, t;
        cin >> s >> t;
        int m = s.size(), ans = 0;
        for (int j = 1; j <= n; j ++) {
            bool flag = 0;
            if (s.find(a[j][0]) == s.npos) continue;
            int i = s.find(a[j][0]), k = a[j][0].size();
            if (i + k > m) continue;
            if (s.substr(0, i) != t.substr(0, i) ||
                s.substr(i + k) != t.substr(i + k))
                continue;
            if (a[j][1] == t.substr(i, k))
                ans ++;
        }
        cout << ans << '\n';
    }
    return 0;
}