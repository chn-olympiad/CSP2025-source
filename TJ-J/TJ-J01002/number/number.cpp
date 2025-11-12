#include <bits/stdc++.h>

using namespace std;

bool test(char c) {
	if ((int)c >= 48 && (int)c <= 57) {
		return 1;
	}
	return 0;
}
string s;
const int N = 1e6 + 50;
int ans[N], cnt;string a, b;
//48-57
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (test(s[i])) {
			ans[cnt] = (int)s[i]-48;
			cnt++;
		}
	}
	sort(ans, ans+cnt);
	for (int i = cnt-1; i >= 0; i--) {
		cout << ans[i];
	}
	return 0;
} 
