#include <bits/stdc++.h>
#define ll long long
#define db double
#define i128 __int128
#define AKIOI ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
string s, ans;
ll len, ton[11];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out","w",stdout);

	AKIOI;
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			ton[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (ton[i] != 0) {
			ton[i]--;
			ans += char(i + '0');
		}
	}
	if (ans[0] == '0')
		cout << '0';
	else
		cout << ans;
	return 0;
}
/*
290es1q0

92100
*/
