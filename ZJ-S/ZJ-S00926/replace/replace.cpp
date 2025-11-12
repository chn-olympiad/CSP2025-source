#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
struct Node {
    string s1, s2;
    vector<int> kmp;
};

vector<Node> a;

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;
    a.resize(n);
    for (int k = 0; k < n; ++k) {
        cin >> a[k].s1 >> a[k].s2;
        a[k].kmp.resize(a[k].s1.size()+1);
        for (int i = 1, j = 0; i < a[k].s1.size(); ++i) {
            while (j > 0 && a[k].s1[i] != a[k].s1[j]) {
                j = a[k].kmp[j-1];
            }
            if (a[k].s1[i] == a[k].s1[j]) { ++j; }
            a[k].kmp[i] = j;
            // cerr << a[k].kmp[i] << ' ';
        }
        // cerr << endl;
    }

    while (q--) {
        int ans = 0;
        string s1, s2;
        cin >> s1 >> s2;
        // cerr << "Current q is " << q << '\n';
        for (int k = 0; k < n; ++k) {
            for (int i = 0, j = 0; i < s1.size(); ++i) {
                while (j > 0 && s1[i] != a[k].s1[j]) {
                    j = a[k].kmp[j-1];
                }
                if (s1[i] == a[k].s1[j]) { ++j; }
                if (j == a[k].s1.size()) {
                    // cerr << i << ' ' << j-1 << ' ' << i-j << " a " << s1.substr(0, i-j+1) << " b " << s1.substr(i+1) << endl;
                    if (s1.substr(0, i-j+1) + a[k].s2 + s1.substr(i+1) == s2) { ++ ans; }
                    j = a[k].kmp[j-1];
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}