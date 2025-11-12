#include <iostream>
#define END cout.flush(); fclose(stdin); fclose(stdout);
using namespace std;

string s1[200010], s2[200010];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            bool flag = false;
            for (int j = 0; j < t1.size() - s1[i].size() + 1; j++) {
                cout << t1.substr(j, s1[i].size()) << ' ' << t2.substr(j, s2[i].size()) << '\n';
                if ((t1.substr(j, s1[i].size()) == s1[i]) && (t2.substr(j, s2[i].size()) != s2[i])) {
                    flag = false;
                    break;
                }
                if ((t1.substr(j, s1[i].size()) == s1[i])) {
                    flag = true;
                    j += s1[i].size();
                }
            }
            ans += flag;
        }
        cout << ans << '\n';
    }
    END;
    return 0;
}
