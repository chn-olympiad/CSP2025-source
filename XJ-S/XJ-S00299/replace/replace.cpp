#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, q;
map<string, string> mp;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    while (q--) {
        string a, b;
        cin >> a >> b;
        if (a.length() != b.length()) {
            cout << 0 << '\n';
            continue;
        }
        long long ans = 0;
        int L = a.length();
        // if (L <= 200) {
        for (int len = 1; len <= L; len++) {
            for (int l = 0; l < L - len + 1; l++) {
                string s = a.substr(l, len);
                if (mp.count(s) == 0) continue;
                string t = a;
                for (int i = 0; i < len; i++) {
                    t[l + i] = mp[s][i];
                }
                if (t == b) ans++;
            }
        }
        cout << ans << '\n';
        // } else {

        // }
    }
    return 0;
}