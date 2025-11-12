#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace Qiuyu3600 {
const int N = 2e5 + 10;
int n, q; string s[N][2], t[2];
void Hutao() {
    cin >> n >> q;
    int l1 = 0, l2 = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i][0] >> s[i][1];
        l1 += s[i][0].size() << 1;
    }
    for(int _ = 1; _ <= q; _ ++) {
        cin >> t[0] >> t[1];
        if(t[0].size() != t[1].size()) {
            cout << "0\n";
            continue;
        }
        int res = 0, x = -1;
        for(int i = 0; !~x; i ++) if(t[0][i] != t[1][i]) x = i;
        for(int i = t[0].size(); i == t[0].size() || t[0][i] == t[1][i]; -- i) {
            for(int j = 1; j <= n; j ++) {
                if(i - x > s[j][0].size() || i < s[j][0].size()) continue;
                int sz = s[j][0].size();
                for(int k = 1; k <= sz; k ++)
                    if(t[0][i - k] != s[j][0][sz - k] || t[1][i - k] != s[j][1][sz - k])
                        goto ending;
                ++ res;
                ending:;
            }
        }
        cout << res << "\n";
    }
}
}
int main() {
    #ifndef DB
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #endif
    int t = 1; while(t --) Qiuyu3600::Hutao();
    return 0;
}