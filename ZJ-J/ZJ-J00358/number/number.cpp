#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6 + 100;
int ans[N], cnt;
int check(char x) {
	if (x >= '0' && x <= '9') {
		return 1;
	}
	return 0;
}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (check(s[i]) == 1) {
			ans[++cnt] = s[i] - '0';
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = cnt; i >= 1; i--) {
		cout << ans[i];
	}
	return 0;
}
