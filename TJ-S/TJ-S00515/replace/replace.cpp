#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q;
map<int, string> s1, s2;
bool check(int l, int r, string a, string b) {
    for (int i = 0; i <= l; i++) if (a[i] != b[i]) return 0;
    for (int i = r; i <= n; i++) if (a[i] != b[i]) return 0;
    return 1;
}
signed main() {
    freopen("replace1.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    while (q--) {
        string a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int last = 0;
            int posa = a.find(s1[i]), posb = b.find(s2[i]);
            while (posa != -1 && posb != -1) {
                if (posa == posb) {
                    last = posa + s1[i].size();
                    if (check(posa - 1, last, s1[i], s2[i])) ans++;
                }
                posa = a.find(s1[i], last), posb = b.find(s2[i], last);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
