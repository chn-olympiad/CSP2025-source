#include <bits/stdc++.h>
using namespace std;
#define int long long
int t[15];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size() - 1;
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[s[i] - 48]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= t[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
