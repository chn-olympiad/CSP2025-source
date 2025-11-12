#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
int ans[15];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ans[s[i] - '0']++;
		}
	}
	int fl = 0;
	for (int i = 9; i >= 0; i--) {
		if (ans[i] > 0 && i != 0) {
			fl = 1;
		}
		for (int j = 1; j <= ans[i]; j++) {
			cout << i;
			if (i == 0 && fl == 0) {
				break;
			}
		}
	}

	return 0;
}
