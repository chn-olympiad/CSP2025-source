#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5, K = 10;

using PII = pair<int, int>;

int q, n, ls[N], ans;
string s[N][2], t1, t2;

string get1(int x) {
    string tmp = "";
    for (int i = 0; i < x; i ++ )   tmp += t1[i];
    return tmp;
}
string get2(int x, int y) {
    string tmp = "";
    for (int i = x; i < y; i ++ )   tmp += t1[i];
    return tmp;
}
string get3(int x) {
    string tmp = "";
    for (int i = x, l = t1.size(); i < l; i ++ )    tmp += t1[i];
    return tmp;
}

struct tstr {
    int pb, n, lsa, rsa;
}a[N][2];
tstr init(string s) {
    tstr res;
    for (int j = 0, l = s.size(); j < l; j ++ )
        if (s[j] == 'b') {
            res.pb = j;
            res.lsa = j + 1;
            res.n = l;
            res.rsa = l - j - 1;
        }
    return res;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++ )  cin >> s[i][0] >> s[i][1], ls[i] = s[i][0].size();
    for (int i = 1; i <= n; i ++ ) {
        a[i][0] = init(s[i][0]);
        a[i][1] = init(s[i][1]);
    }
    while (q -- ) {
        ans = 0;
        cin >> t1 >> t2;
        int tn = t1.size();
        if (n <= 1000 && q <= 1000 && tn <= 2000) {
            for (int i = 0; i <= tn; i ++ )
                for (int j = i + 1; j <= tn; j ++ ) {
                    string x = get1(i), y = get2(i, j), z = get3(j);
                    // cout << i << ' ' << j << '\n';
                    for (int k = 1; k <= n; k ++ ) {
                        if (s[k][0] == y) {
                            if (x + s[k][1] + z == t2)
                                ans ++ ;
                        }
                    }
                }
        } else {
            tstr ts1 = init(t1), ts2 = init(t2);
            // cout << ts1.lsa << ' ' << ts1.lsa << '\n';
            for (int i = 1; i <= n; i ++ ) {
                if (ts1.lsa >= a[i][0].lsa && ts1.rsa >= a[i][0].rsa)
                    if (ts1.lsa - a[i][0].lsa + a[i][1].lsa == ts2.lsa && ts1.rsa - a[i][0].rsa + a[i][1].rsa == ts2.rsa)
                        ans ++ ;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
1 1
ab aab
ab aab

*/
