#include <bits/stdc++.h>
using namespace std;
//)!$*#@$*!##(
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, ans = "";
	cin >> s;
	int len = s.length();
	for (char c = '9'; c >= '0'; c--) for (int i = 0; i < len; i++) if (s[i] == c) ans += c;
	cout << ans << endl;
	return 0;
}
