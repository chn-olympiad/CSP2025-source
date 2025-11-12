#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 2e5 + 5;
typedef pair<int, int> pll;
int n, q;
string s1[maxn], s2[maxn];
// string t1[maxn], t2[maxn];

// int id1[maxn], id2[maxn], tid1[maxn], tid2[maxn];

// void one() {
//     string t1, t2; cin >> t1 >> t2;
//     if (t1.size() != t2.size()) {
//         cout << 0 << endl;
//         return;
//     }
//     int l = 0, r = t1.size();
// }
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> q;
    // int F = 1;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
        // int cnt2 = 0, cnt1 = 0;
        // for (int j = 0; j < s1[i].size(); j++) {
        //     if (s1[i][j] != 'a' && s1[i][j] != 'b') F = 0;
        //     if (s2[i][j] != 'a' && s2[i][j] != 'b') F = 0;
        //     if (s2[i][j] == 'b') cnt2++, id2[i] = j;
        //     if (s1[i][j] == 'b') cnt1++, id1[i] = j;
        //     if (cnt2 > 1) F = 0;
        //     if (cnt1 > 1) F = 0;
        // }
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        if (t1.size() != t2.size()) {
            cout << 0 << endl;
            continue;
        }
        int l = 0, r = 0;
        for (int i = 0; i < t1.size(); i++) {
            if (t1[i] != t2[i]) r = i;
        }
        for (int i = t1.size(); i >= 0; i--) {
            if (t1[i] != t2[i]) l = i;
        }
        for (int i = 0; i < t1.size(); i++) {
            for (int j = 1; j <= n; j++) {
                bool F = 1;
                for (int k = 0; k < s1[j].size(); k++) {
                    if (s1[j][k] != t1[i + k] || s2[j][k] != t2[i + k]) {
                        F = 0;
                        break;
                    }
                }
                if (F) {
                    if (i <= l && i + s1[j].size() - 1 >= r) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    // if (q == 1) {
    //     one();
    //     return 0;
    // }
    // for (int i = 1; i <= q; i++) {
    //     cin >> t1[i] >> t2[i];
    //     int cnt1 = 0, cnt2 = 0;
    //     for (int j = 0; j < t1[i].size(); j++) {
    //         if (t1[i][j] != 'a' && t1[i][j] != 'b') F = 0;
    //         if (t1[i][j] == 'b') cnt1++, tid1[i] = j;
    //         if (cnt1 > 1) F = 0;
    //     }
    //     for (int j = 0; j < t2[i].size(); j++) {
    //         if (t2[i][j] != 'a' && t2[i][j] != 'b') F = 0;
    //         if (t2[i][j] == 'b') cnt2++, tid2[i] = j;
    //         if (cnt2 > 1) F = 0;
    //     }
    // }

    // if (F) {
    //     for (int i = 1; i <= n; i++) {

    //     }
    //     for (int i = 1; i <= q; i++) {
    //         if (t1[i].size() != t2[i].size()) {cout << 0 << endl; continue;}

    //     }
    // }
    return 0;
}