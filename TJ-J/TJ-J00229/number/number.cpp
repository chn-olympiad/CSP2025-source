#include <bits/stdc++.h>
using namespace std;
#define int long long

string s, ans;

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans += s[i];
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    cout << ans;
    return 0;
}//期望得分100pts。 
