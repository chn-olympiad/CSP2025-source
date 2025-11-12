#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n, m;
string s[N][2], t[N][2], difs[N][2], dift[N][2];
struct node {string s; int id;};
int c[N];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i][0] >> s[i][1];
        // difs[i][0] = difs[i][1] = "0";
        // for(int j = 0, flag = 0; j < s[i][0].size(); i ++) {
        //     if(s[i][0][j] != s[i][1][j] && flag <= 1) {
        //         difs[i][0].push_back(s[i][0][j]),
        //         difs[i][1].push_back(s[i][1][j]);
        //         if(flag == 0) flag = 1;
        //     }
        //     else if(s[i][0][j] == s[i][1][j] && flag == 1)
        //         flag = 2;
        //     else if(s[i][0][j] != s[i][1][j] && flag == 2)
        //         difs[i][0] = difs[i][1] = "0";
        // }
        // if(difs[i][0] == difs[i][1]) continue;
    }
    // cerr << s[1][1].size() << '\n';
    for(int i = 1; i <= m; i ++) {
        int ans = 0;
        cin >> t[i][0] >> t[i][1];
        // if(t[i][0].size() != t[i][1].size()) {
            cout << "0\n";
            // continue;
        // }
        // for(int k = 1; k <= n; k ++) {
        //     for(int j = 0; j <= t[i][0].size() - s[k][0].size(); j ++) {
        //         if(t[i][0].substr(j, s[k][0].size()) != s[k][0]) continue;
        //         if(t[i][0].substr(0, j) + s[k][1] + t[i][0].substr(0, 1) + \
        //         t[i][0].substr(j + s[k][0].size(), t[i][0].size() - j - s[k][0].size() + 1) == t[i][1]) ans ++;
        //         // cerr << i << ' ' << t[i][0].size() - s[k][0].size() << ' ' << k << '\n';
        //     }
        // }
        // cout << ans << '\n';
    }
}