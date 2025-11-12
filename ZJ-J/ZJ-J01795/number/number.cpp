#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int vis[11];
string s;
bool is_number(char ch) {
    if ('0' <= ch && ch <= '9') return true;
    else return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
        if (is_number(s[i])) vis[(s[i] - '0')]++;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = vis[i]; j >= 1; j--) {
            cout << i;
        }
    }
    return 0;
}
