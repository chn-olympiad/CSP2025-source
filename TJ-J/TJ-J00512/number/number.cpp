#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    vector<int> cnt(10, 0);
    for (char c : s) if (isdigit(c)) cnt[c - '0']++;
    for (int i = 9; i >= 0; i--)
        for (int j = 0; j < cnt[i]; j++)
            cout << i;
    cout << '\n';
    return 0;
}
