#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    vector<int> cnt(10);
    for (auto i : s) {
        if ('0' <= i && i <= '9')
            cnt[i - '0']++;
    }

    bool flag = 0;
    for (int i = 9; i >= 0; --i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << i;
            flag = 1;
        }
    }

    cout << '\n';

    return 0;
}
