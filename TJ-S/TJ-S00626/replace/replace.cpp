#include <iostream>
#include <string>
using namespace std;
string s[200010][2];
int main () {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i][0] >> s[i][1];
    }
    while(q --) {
        string t, tt;
        cin >> t >> tt;
        if (t.length() != tt.length()) {
            cout << 0 << "\n";
            continue;
        }
        int m = t.length(), res = 0;
        for (int i = 1; i <= n; i ++) {
            int len = s[i][0].length();
            // cout << "len = " << len << "\n";
            for (int j = 0; j < m - len + 1; j ++) {
                // cout << "substr " << t.substr(j, len) << "\n";
                if (t.substr(j, len) == s[i][0]) {
                    string x = "";
                    if (j >= 1) {
                        x = t.substr(0, j);
                    }
                    string z = "";
                    if (j + len <= m - 1) {
                        z = t.substr(j + len, m - j - len);
                    }
                    if (x + s[i][1] + z == tt) {
                        res ++;
                    }
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}