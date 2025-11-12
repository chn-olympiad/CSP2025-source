#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int q1 = 97;
const int p1 = 998244353;


string s[200005][2];

map <pair <ll, ll>, map <pair <ll, int>, vector <pair <ll, int> > > > mp;//{{最小的修改前，修改后}, {{前缀，前缀长度}，{后缀,后缀长度}}}

ll hs[5000005];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio();
    cin.tie(0);

    int n, q;cin >> n >> q;
    int i, j;
    for (i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        int len = s[i][0].size();
        int id1 = -1;
        for (j = 0; j < len; j++) {
            if (s[i][0][j] != s[i][1][j]) {
                id1 = j;
                break;
            }
        }
        if (id1 == -1) {
            n--;i--;continue;
        }
        int id2;
        for (j = len - 1; j >= 0; j--) {
            if (s[i][0][j] != s[i][1][j]) {
                id2 = j;
                break;
            }
        }

        ll v1 = 0;
        for (j = id1 - 1; j >= 0; j--) {
            v1 = (v1 * q1 + (s[i][0][j] - 'a' + 1)) % p1;
        }
        ll v2 = 0, v3 = 0;
        for (j = id1; j <= id2; j++) {
            v2 = (v2 * q1 + (s[i][0][j] - 'a' + 1)) % p1;
            v3 = (v3 * q1 + (s[i][1][j] - 'a' + 1)) % p1;
        }
        ll v4 = 0;
        for (j = id2 + 1; j < len; j++) {
            v4 = (v4 * q1 + (s[i][0][j] - 'a' + 1)) % p1;
        }
        //cout << v1 << ":" << id1 << " " << v2 << "and" << v3 << " " << v4 << ":" << len - 1 - id2 << endl;
        mp[{v2, v3}][{v1, id1}].push_back({v4, len - 1 - id2});
    }
    while (q--) {
        string t1, t2;cin >> t1 >> t2;
        int len = t1.size();
        int id1 = 0;
        for (j = 0; j < len; j++) {
            if (t1[j] != t2[j]) {
                id1 = j;
                break;
            }
        }
        int id2;
        for (j = len - 1; j >= 0; j--) {
            if (t1[j] != t2[j]) {
                id2 = j;
                break;
            }
        }
        ll vt1 = 0, vt2 = 0;
        for (j = id1; j <= id2; j++) {
            vt1 = (vt1 * q1 + (t1[j] - 'a' + 1)) % p1;
            vt2 = (vt2 * q1 + (t2[j] - 'a' + 1)) % p1;
        }
        hs[0] = 0;
        int E = len - id2;
        for (j = id2 + 1; j <= len; j++) {
            hs[j - id2] = (hs[j - id2 - 1] * q1 + (t1[j] - 'a' + 1)) % p1;//hs[i]为i长度的hsh值
        }
        if (!mp[{vt1, vt2}].empty()) {
            //cout << vt1<< "and" << vt2 << endl;
            ll vnow = 0;
            int ans = 0;
            for (j = id1; j >= 0; j--) {
                if (j < id1) {
                    vnow = (vnow * q1 + (t1[j] - 'a' + 1)) % p1;
                }
                //cout << vnow << "..." << endl;
                if (!mp[{vt1, vt2}][{vnow, id1 - j}].empty()) {
                    for (auto l : mp[{vt1, vt2}][{vnow, id1 - j}]) {
                        //cout << l.first << "!" << l.second << endl;
                        if (l.second <= E && hs[l.second] == l.first) {
                            ans++;
                        }
                    }
                }
            }
            cout << ans << "\n";
        }else {
            cout << "0\n";
        }
    }
    return 0;
}